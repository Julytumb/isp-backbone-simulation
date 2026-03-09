#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/ipv4-static-routing-helper.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <functional>


using namespace ns3;

NS_LOG_COMPONENT_DEFINE("NetworkSimulation");

//Function for skipping the line breaks
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (std::string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

// Callback function for transmitted packets
static void TxCallback(Ptr<const Packet> packet, Ptr<NetDevice> dev, std::map<Ptr<NetDevice>, uint64_t>* deviceTxBytes) {
    (*deviceTxBytes)[dev] += packet->GetSize();
}

// Callback function for received packets
static void RxCallback(Ptr<const Packet> packet, Ptr<NetDevice> dev, std::map<Ptr<NetDevice>, uint64_t>* deviceRxBytes) {
    (*deviceRxBytes)[dev] += packet->GetSize();
}

// Structure to hold link information
struct Link {
    std::string a_node;
    std::string a_iface;
    std::string b_node;
    std::string b_iface;
    uint32_t capacity_mbps;
    uint32_t line;
};

// Structure to hold router information
struct Router {
    std::string node;
    std::string kind;
};

// Structure to hold route information
struct Route {
    std::string srcrouter;
    std::string nexthop;
    uint32_t weight;
};

// Structure to hold traffic information
struct Traffic {
    std::string srcRouter;
    std::string destRouter;
    uint64_t amount;
    uint32_t numPackets;
    uint32_t packetSize;
    uint32_t duration;
    std::string protocol;
};



// Function to read CSV file and parse lines
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Read routers from CSV
std::map<std::string, Router> readRouters(const std::string& filename) {
    std::map<std::string, Router> routers;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        NS_LOG_ERROR("Cannot open file: " << filename);
        return routers;
    }

    // Skip header
    std::getline(file, line);
    bool firstLine = true;

    while (std::getline(file, line)) {
        auto tokens = split(line, ',');
        if (tokens.size() >= 2) {
            if (firstLine) {
                if (tokens[0].size() >= 3 && tokens[0].compare(0, 3, "\xef\xbb\xbf") == 0) {
                    tokens[0] = tokens[0].substr(3);
                }
                firstLine = false;
            }
            Router router;
            router.node = trim(tokens[0]);
            router.kind = trim(tokens[1]);
            routers[router.node] = router;
        }
    }

    file.close();
    return routers;
}

// Read links from CSV
std::vector<Link> readLinks(const std::string& filename) {
    std::vector<Link> links;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        NS_LOG_ERROR("Cannot open file: " << filename);
        return links;
    }

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        auto tokens = split(line, ',');
        if (tokens.size() >= 6) {
            Link link;
            link.a_node = trim(tokens[0]);
            link.a_iface = trim(tokens[1]);
            link.b_node = trim(tokens[2]);
            link.b_iface = trim(tokens[3]);
            link.capacity_mbps = std::stoul(tokens[4]);
            link.line = std::stoul(tokens[5]);
            links.push_back(link);
        }
    }

    file.close();
    return links;
}

// Read routes from CSV
std::vector<Route> readRoutes(const std::string& filename) {
    std::vector<Route> routes;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        NS_LOG_ERROR("Cannot open file: " << filename);
        return routes;
    }

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        auto tokens = split(line, ',');
        if (tokens.size() >= 3) {
            Route route;
            std::string src = trim(tokens[0]);
            std::string nh = trim(tokens[1]);

            // replace +AC0- with - 
            size_t pos;
            while ((pos = src.find("+AC0-")) != std::string::npos) {
                src.replace(pos, 5, "-");
            }
            while ((pos = nh.find("+AC0-")) != std::string::npos) {
                nh.replace(pos, 5, "-");
            }
            // ----------------------------------------------------

            route.srcrouter = src;
            route.nexthop = nh;
            route.weight = std::stoul(tokens[2]);
            routes.push_back(route);
        }
    }

    file.close();
    return routes;
}

// Read traffic from CSV
std::vector<Traffic> readTraffic(const std::string& filename) {
    std::vector<Traffic> trafficFlows;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        NS_LOG_ERROR("Cannot open file: " << filename);
        return trafficFlows;
    }

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        auto tokens = split(line, ',');
        if (tokens.size() >= 6) {
            Traffic traffic;
            traffic.srcRouter = trim(tokens[0]);
            traffic.destRouter = trim(tokens[1]);
            traffic.amount = std::stoull(tokens[2]);
            traffic.numPackets = std::stoul(tokens[3]);
            traffic.duration = std::stoul(tokens[4]);
            traffic.protocol = trim(tokens[5]);
            traffic.packetSize = (traffic.amount / 8) / traffic.numPackets;
            trafficFlows.push_back(traffic);
        }
    }

    file.close();
    return trafficFlows;
}

int main(int argc, char *argv[]) {
    // Set simulation parameters
    Time::SetResolution(Time::NS);
    LogComponentEnable("NetworkSimulation", LOG_LEVEL_INFO);

    // Loop over numbered files starting from 0
    for (int i = 0; ; ++i) {
        std::string suffix = (i == 0) ? "" : std::to_string(i);
        std::string routesFile = "../sources/routes.csv";
        std::string linksFile = "../sources/links.csv";
        std::string trafficFile = "../generated_sources/traffic" + suffix + ".csv";
        std::string outputFile = "../outputs/traffic_over_nodes" + suffix + ".csv";

        // Check if traffic file exist by trying to open them
        std::ifstream testTraffic(trafficFile);
        if (!testTraffic.is_open()) {
            NS_LOG_INFO("Stopping loop: traffic file not found for index " << i);
            break;
        }
        testTraffic.close();

        NS_LOG_INFO("Running simulation for index " << i);

        // Read CSV data
        NS_LOG_INFO("Reading CSV files...");
        auto routers = readRouters("../sources/routers.csv");
        auto links = readLinks(linksFile);
        auto routes = readRoutes(routesFile);
        auto trafficFlows = readTraffic(trafficFile);

        if (routers.empty()) {
            NS_LOG_ERROR("Routers file is empty or invalid, skipping index " << i);
            continue;
        }
        if (links.empty() || routes.empty() || trafficFlows.empty()) {
            NS_LOG_INFO("One of the CSV files is empty for index " << i << ", stopping loop");
            break;
        }

        NS_LOG_INFO("Found " << routers.size() << " routers");
        NS_LOG_INFO("Found " << links.size() << " links");
        NS_LOG_INFO("Found " << routes.size() << " routes");
        NS_LOG_INFO("Found " << trafficFlows.size() << " traffic flows");

        // Create nodes
        NodeContainer nodes;
        std::map<std::string, Ptr<Node>> nodeMap;
        std::map<std::string, std::vector<Ptr<NetDevice>>> nodeDeviceMap;

        for (const auto& router : routers) {
            Ptr<Node> node = CreateObject<Node>();
            nodeMap[router.first] = node;
            nodes.Add(node);
        }

        NS_LOG_INFO("Created " << nodes.GetN() << " nodes");

        // Map to store transmitted bytes per device
        std::map<Ptr<NetDevice>, uint64_t> deviceTxBytes;
        // Map to store received bytes per device
        std::map<Ptr<NetDevice>, uint64_t> deviceRxBytes;

        // Declare flow monitor
        FlowMonitorHelper flowmon;
        Ptr<FlowMonitor> monitor;

        // Setup CSV for traffic over nodes
        //std::ofstream trafficCsv(outputFile);
        //std::map<std::string, uint64_t> prevTxBytes;
        //std::map<std::string, uint64_t> prevRxBytes;
        //for (auto& pair : nodeMap) {
            //prevTxBytes[pair.first] = 0;
            //prevRxBytes[pair.first] = 0;
        //}
        //trafficCsv << "Time";
        //for (auto& pair : nodeMap) {
            //trafficCsv << "," << pair.first << "_Tx," << pair.first << "_Rx";
        //}
        //trafficCsv << std::endl;

        std::function<void()> collectTraffic;

        // Create point-to-point links
        std::vector<NetDeviceContainer> deviceContainers;
        // Parallel vector to remember which two routers each device container connects.
        // This is used later when installing static routes.
        std::vector<std::pair<std::string, std::string>> deviceRouterPairs;

        InternetStackHelper internet;
        internet.Install(nodes);
        /*
        // ---------------------------------------------------------------------
        // TOPOLOGY OPTION 1: build from links.csv (original behavior)
        //
        // This block is kept for easy toggling. To use it instead of the
        // routes-based topology below, comment out the "TOPOLOGY OPTION 2"
        // block and uncomment this one.
        // ---------------------------------------------------------------------
        
        for (const auto& link : links) {
            if (nodeMap.find(link.a_node) != nodeMap.end() &&
                nodeMap.find(link.b_node) != nodeMap.end()) {

                // Create point-to-point channel
                PointToPointHelper p2p;
                std::stringstream ss;
                ss << link.capacity_mbps << "Mbps";
                p2p.SetDeviceAttribute("DataRate", StringValue(ss.str()));
                p2p.SetChannelAttribute("Delay", StringValue("2ms"));

                NodeContainer linkNodes;
                linkNodes.Add(nodeMap[link.a_node]);
                linkNodes.Add(nodeMap[link.b_node]);

                NetDeviceContainer devices = p2p.Install(linkNodes);
                deviceContainers.push_back(devices);
                deviceRouterPairs.emplace_back(link.a_node, link.b_node);

                // Set up tracing for transmitted bytes
                for (uint32_t i = 0; i < devices.GetN(); ++i) {
                    Ptr<NetDevice> dev = devices.Get(i);
                    deviceTxBytes[dev] = 0;
                    deviceRxBytes[dev] = 0;
                    Ptr<PointToPointNetDevice> p2pDev = DynamicCast<PointToPointNetDevice>(dev);
                    if (p2pDev) {
                        Callback<void, Ptr<const Packet>> txCb = [dev, &deviceTxBytes](Ptr<const Packet> packet) {
                            TxCallback(packet, dev, &deviceTxBytes);
                        };
                        p2pDev->TraceConnectWithoutContext("MacTx", txCb);
                        Callback<void, Ptr<const Packet>> rxCb = [dev, &deviceRxBytes](Ptr<const Packet> packet) {
                            RxCallback(packet, dev, &deviceRxBytes);
                        };
                        p2pDev->TraceConnectWithoutContext("MacRx", rxCb);
                    }
                }
            }
        }
        */
        
        // ---------------------------------------------------------------------
        // TOPOLOGY OPTION 2: build physical links directly from routes.csv
        //
        // For each (srcrouter, nexthop) in routes.csv, we create a point-to-point
        // link if both routers exist. This way, the Dijkstra graph and the
        // physical topology are consistent even if links.csv is incomplete.
        // ---------------------------------------------------------------------
        for (const auto& route : routes) {
            auto itSrc = nodeMap.find(route.srcrouter);
            auto itNh  = nodeMap.find(route.nexthop);
            if (itSrc == nodeMap.end() || itNh == nodeMap.end()) {
                continue;
            }

            // Avoid creating duplicate links for the same unordered pair
            bool exists = false;
            for (const auto& pair : deviceRouterPairs) {
                if ((pair.first == route.srcrouter && pair.second == route.nexthop) ||
                    (pair.first == route.nexthop && pair.second == route.srcrouter)) {
                    exists = true;
                    break;
                }
            }
            if (exists) {
                continue;
            }

            PointToPointHelper p2p;
            // Use a default capacity; routes.csv currently has weights but no bandwidth.
            p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
            p2p.SetChannelAttribute("Delay", StringValue("2ms"));

            NodeContainer linkNodes;
            linkNodes.Add(itSrc->second);
            linkNodes.Add(itNh->second);

            NetDeviceContainer devices = p2p.Install(linkNodes);
            deviceContainers.push_back(devices);
            deviceRouterPairs.emplace_back(route.srcrouter, route.nexthop);

            // Set up tracing for transmitted bytes
            for (uint32_t i = 0; i < devices.GetN(); ++i) {
                Ptr<NetDevice> dev = devices.Get(i);
                deviceTxBytes[dev] = 0;
                deviceRxBytes[dev] = 0;
                Ptr<PointToPointNetDevice> p2pDev = DynamicCast<PointToPointNetDevice>(dev);
                if (p2pDev) {
                    Callback<void, Ptr<const Packet>> txCb = [dev, &deviceTxBytes](Ptr<const Packet> packet) {
                        TxCallback(packet, dev, &deviceTxBytes);
                    };
                    p2pDev->TraceConnectWithoutContext("MacTx", txCb);
                    Callback<void, Ptr<const Packet>> rxCb = [dev, &deviceRxBytes](Ptr<const Packet> packet) {
                        RxCallback(packet, dev, &deviceRxBytes);
                    };
                    p2pDev->TraceConnectWithoutContext("MacRx", rxCb);
                }
            }
        }
        

        // Populate nodeDeviceMap
        for (const auto& router : routers) {
            std::string name = router.first;
            std::vector<Ptr<NetDevice>> devs;
            Ptr<Node> node = nodeMap[name];
            for (uint32_t i = 0; i < node->GetNDevices(); ++i) {
                devs.push_back(node->GetDevice(i));
            }
            nodeDeviceMap[name] = devs;
        }

        //NS_LOG_INFO("Created " << deviceContainers.size() << " links (from routes.csv topology)");

        // Assign IP addresses
        Ipv4AddressHelper address;
        address.SetBase("10.0.0.0", "255.255.255.0");

        std::vector<Ipv4InterfaceContainer> interfaceContainers;
        uint32_t subnetIndex = 0;

        for (auto& devices : deviceContainers) {
            std::stringstream ss;
            ss << "10." << (subnetIndex / 256) << "." << (subnetIndex % 256) << ".0";
            address.SetBase(ss.str().c_str(), "255.255.255.0");
            Ipv4InterfaceContainer interfaces = address.Assign(devices);
            interfaceContainers.push_back(interfaces);
            subnetIndex++;
        }

        std::map<Ipv4Address, std::string> ipToName;
        for (auto& pair : nodeMap) {
            std::string name = pair.first;
            Ptr<Node> node = pair.second;
            Ptr<Ipv4> ipv4 = node->GetObject<Ipv4>();
            for (uint32_t i = 1; i < ipv4->GetNInterfaces(); ++i) {
                for (uint32_t j = 0; j < ipv4->GetNAddresses(i); ++j) {
                    Ipv4Address addr = ipv4->GetAddress(i, j).GetLocal();
                    ipToName[addr] = name;
                }
            }
        }

        // ---------------------------------------------------------------------
        // Set up routing using Dijkstra on the router graph defined by routes.csv
        // ---------------------------------------------------------------------

        // Build an index for routers: name -> integer id
        std::map<std::string, uint32_t> routerIndex;
        std::vector<std::string> indexToRouter;
        {
            uint32_t idx = 0;
            for (const auto& r : routers) {
                routerIndex[r.first] = idx++;
                indexToRouter.push_back(r.first);
            }
        }

        uint32_t nRouters = static_cast<uint32_t>(indexToRouter.size());

        // Build adjacency list from routes (directed, weighted)
        std::vector<std::vector<std::pair<uint32_t, uint32_t>>> adj(nRouters);
        for (const auto& route : routes) {
            auto itSrc = routerIndex.find(route.srcrouter);
            auto itNh  = routerIndex.find(route.nexthop);
            if (itSrc == routerIndex.end() || itNh == routerIndex.end()) {
                continue;
            }
            uint32_t u = itSrc->second;
            uint32_t v = itNh->second;
            adj[u].push_back(std::make_pair(v, route.weight));
        }

        // ---------------------------------------------------------------------
        // TEMPORARY: Make routes bidirectional (easy to comment out)
        // This adds reverse edges so if A->B exists, B->A is also created.
        // ---------------------------------------------------------------------
        for (const auto& route : routes) {
            auto itSrc = routerIndex.find(route.srcrouter);
            auto itNh  = routerIndex.find(route.nexthop);
            if (itSrc == routerIndex.end() || itNh == routerIndex.end()) {
                continue;
            }
            uint32_t u = itSrc->second;
            uint32_t v = itNh->second;
            // Add reverse edge (v -> u) with same weight if not already present
            bool exists = false;
            for (const auto& edge : adj[v]) {
                if (edge.first == u) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                adj[v].push_back(std::make_pair(u, route.weight));
            }
        }
        // ---------------------------------------------------------------------

        // Helper to find link index between two routers (by name) using the
        // deviceRouterPairs built from the chosen topology option above.
        auto findLinkIndex = [&deviceRouterPairs](const std::string& a, const std::string& b) -> int {
            for (size_t i = 0; i < deviceRouterPairs.size(); ++i) {
                if ((deviceRouterPairs[i].first == a && deviceRouterPairs[i].second == b) ||
                    (deviceRouterPairs[i].first == b && deviceRouterPairs[i].second == a)) {
                    return static_cast<int>(i);
                }
            }
            return -1;
        };

        // Pre-compute a "primary" address for each router (first non-loopback address)
        std::map<std::string, Ipv4Address> routerPrimaryAddress;
        for (const auto& entry : nodeMap) {
            const std::string& name = entry.first;
            Ptr<Node> node = entry.second;
            Ptr<Ipv4> ipv4 = node->GetObject<Ipv4>();
            Ipv4Address primary("0.0.0.0");
            if (ipv4 != nullptr) {
                for (uint32_t i = 1; i < ipv4->GetNInterfaces(); ++i) { // skip interface 0 (loopback)
                    if (ipv4->GetNAddresses(i) > 0) {
                        Ipv4InterfaceAddress ifAddr = ipv4->GetAddress(i, 0);
                        if (ifAddr.GetLocal() != Ipv4Address("0.0.0.0")) {
                            primary = ifAddr.GetLocal();
                            break;
                        }
                    }
                }
            }
            routerPrimaryAddress[name] = primary;
            NS_LOG_INFO("Primary IP for router " << name << " = " << primary);
        }

        // collectTraffic = [&]() {
        //     double time = Simulator::Now().GetSeconds();
        //     trafficCsv << time;
        //     for (auto& pair : nodeMap) {
        //         Ptr<Node> node = pair.second;
        //         uint64_t totalTx = 0;
        //         uint64_t totalRx = 0;
        //         for (uint32_t i = 0; i < node->GetNDevices(); ++i) {
        //             Ptr<NetDevice> dev = node->GetDevice(i);
        //             totalTx += deviceTxBytes[dev];
        //             totalRx += deviceRxBytes[dev];
        //         }
        //         uint64_t diffTx = totalTx - prevTxBytes[pair.first];
        //         uint64_t diffRx = totalRx - prevRxBytes[pair.first];
        //         prevTxBytes[pair.first] = totalTx;
        //         prevRxBytes[pair.first] = totalRx;
        //         trafficCsv << "," << diffTx << "," << diffRx;
        //     }
        //     trafficCsv << std::endl;
        //     if (time + 1.0 < 30.0) {
        //         Simulator::Schedule(Seconds(1.0), collectTraffic);
        //     }
        // };

        //----------------------------------------------
            //NEU!!!
        //----------------------------------------------

        // Create Mapping file
        if (i == 0) {
            std::string mapFileName = "../outputs/link_map.csv"; // Suffix entfernt
            std::ofstream mapCsv(mapFileName);
            mapCsv << "LinkID,NodeA,NodeB" << std::endl;

            // Schleifenvariable von 'i' auf 'linkIdx' geändert, 
            // um Konflikte mit dem 'i' der äußeren Schleife zu vermeiden.
            for (size_t linkIdx = 0; linkIdx < deviceRouterPairs.size(); ++linkIdx) {
                mapCsv << linkIdx << "," << deviceRouterPairs[linkIdx].first << "," << deviceRouterPairs[linkIdx].second << std::endl;
            }
            mapCsv.close();
            NS_LOG_INFO("Created link mapping file: " << mapFileName);
        }
        // Prepare traffic csv
        std::ofstream trafficCsv(outputFile);
        
        trafficCsv << "Time";
        for (size_t i = 0; i < deviceContainers.size(); ++i) {
            trafficCsv << ",Link_" << i;
        }
        trafficCsv << std::endl;

        // throughput calculation
        std::vector<uint64_t> prevLinkBytes(deviceContainers.size(), 0);

       // record every second
        collectTraffic = [&]() {
            double time = Simulator::Now().GetSeconds();
            trafficCsv << time;

            // iterate over every link
            for (size_t i = 0; i < deviceContainers.size(); ++i) {
                // Ein Link hat immer 2 Seiten (Geräte): A und B
                Ptr<NetDevice> devA = deviceContainers[i].Get(0);
                Ptr<NetDevice> devB = deviceContainers[i].Get(1);

                // get bytes from both sides
                uint64_t currentBytesA = deviceTxBytes[devA];
                uint64_t currentBytesB = deviceTxBytes[devB];
                
                // record all the traffic from the link (in both directions)
                uint64_t totalCurrentBytes = currentBytesA + currentBytesB;

                // (new-old) * 8 Bit / 1 second / 1 million for Mbps
                uint64_t diffBytes = totalCurrentBytes - prevLinkBytes[i];
                double mbps = (diffBytes * 8.0) / 1000000.0; 

                trafficCsv << "," << mbps;

                // update
                prevLinkBytes[i] = totalCurrentBytes;
            }
            
            trafficCsv << std::endl;

            // repeat every second
            if (time + 1.0 < 30.0) {
                Simulator::Schedule(Seconds(1.0), collectTraffic);
            }
        };

        Ipv4StaticRoutingHelper staticRoutingHelper;

        // Dijkstra for each router as source
        for (uint32_t s = 0; s < nRouters; ++s) {
            const std::string& srcName = indexToRouter[s];
            Ptr<Node> srcNode = nodeMap[srcName];
            Ptr<Ipv4> srcIpv4 = srcNode->GetObject<Ipv4>();
            Ptr<Ipv4StaticRouting> staticRouting = staticRoutingHelper.GetStaticRouting(srcIpv4);

            const uint32_t INF = std::numeric_limits<uint32_t>::max();
            std::vector<uint32_t> dist(nRouters, INF);
            std::vector<int32_t> prev(nRouters, -1);
            std::vector<bool> visited(nRouters, false);

            // Min-heap of (distance, node)
            struct HeapNode {
                uint32_t d;
                uint32_t v;
                bool operator>(const HeapNode& other) const {
                    return d > other.d;
                    return d > other.d;
                }
            };

            std::priority_queue<HeapNode, std::vector<HeapNode>, std::greater<HeapNode>> pq;
            dist[s] = 0;
            pq.push({0, s});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (visited[u]) continue;
                visited[u] = true;
                for (const auto& edge : adj[u]) {
                    uint32_t v = edge.first;
                    uint32_t w = edge.second;
                    if (dist[u] != INF && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        prev[v] = static_cast<int32_t>(u);
                        pq.push({dist[v], v});
                    }
                }
            }

            // For each destination, derive next-hop and install a host route
            for (uint32_t t = 0; t < nRouters; ++t) {
                if (t == s) continue;
                if (dist[t] == INF) continue; // unreachable

                // Walk back from t to find the first hop after s
                int32_t current = static_cast<int32_t>(t);
                int32_t previous = prev[current];
                if (previous == -1) {
                    continue;
                }
                while (previous != static_cast<int32_t>(s)) {
                    current = previous;
                    previous = prev[current];
                    if (previous == -1) {
                        break;
                    }
                }
                if (previous == -1) {
                    continue;
                }
                uint32_t nextHopIndex = static_cast<uint32_t>(current);

                const std::string& destName = indexToRouter[t];
                const std::string& nextHopName = indexToRouter[nextHopIndex];

                // Find the link between src and nextHop
                int linkIdx = findLinkIndex(srcName, nextHopName);
                if (linkIdx < 0) {
                    continue;
                }

                // Determine outgoing interface index and next-hop IP
                NetDeviceContainer& devices = deviceContainers[static_cast<size_t>(linkIdx)];
                Ipv4InterfaceContainer& ifaces = interfaceContainers[static_cast<size_t>(linkIdx)];

                Ptr<NetDevice> outDev;
                Ipv4Address nextHopAddr;

                // Use deviceRouterPairs to determine which router is on which side of the link.
                // This works for both topology options (links.csv and routes.csv).
                const std::pair<std::string, std::string>& routerPair = deviceRouterPairs[static_cast<size_t>(linkIdx)];
                if (routerPair.first == srcName) {
                    outDev = devices.Get(0);
                    nextHopAddr = ifaces.GetAddress(1);
                } else {
                    outDev = devices.Get(1);
                    nextHopAddr = ifaces.GetAddress(0);
                }

                int32_t outIfIndex = srcIpv4->GetInterfaceForDevice(outDev);
                if (outIfIndex < 0) {
                    continue;
                }

                Ipv4Address destAddr = routerPrimaryAddress[destName];
                if (destAddr == Ipv4Address("0.0.0.0")) {
                    continue;
                }

                staticRouting->AddHostRouteTo(destAddr, nextHopAddr, static_cast<uint32_t>(outIfIndex));
                //NS_LOG_INFO("Routing: " << srcName << " -> " << destName
                            //<< " via next-hop " << nextHopName
                            //<< " destAddr=" << destAddr
                            //<< " nextHopAddr=" << nextHopAddr
                            //<< " outIfIndex=" << static_cast<uint32_t>(outIfIndex));
            }
        }

        // Print all routing tables at time 0 to debug paths
        AsciiTraceHelper ascii;
        Ptr<OutputStreamWrapper> routingStream = ascii.CreateFileStream("../outputs/routing-tables" + suffix + ".log");
        Ipv4GlobalRoutingHelper::PrintRoutingTableAllAt(Seconds(0.0), routingStream);

        // Install traffic applications
        // Use a different UDP port for each traffic flow to avoid multiple
        // servers trying to bind the same (node, port) combination.
        uint16_t basePort = 9000;
        uint32_t flowIndex = 0;

        for (const auto& traffic : trafficFlows) {
            if (nodeMap.find(traffic.srcRouter) != nodeMap.end() &&
                nodeMap.find(traffic.destRouter) != nodeMap.end()) {

                uint16_t port = basePort + static_cast<uint16_t>(flowIndex);

                // Get destination IP address - use the primary IP that routing uses
                Ptr<Node> destNode = nodeMap[traffic.destRouter];
                Ipv4Address destAddr = routerPrimaryAddress[traffic.destRouter];
                if (destAddr == Ipv4Address("0.0.0.0")) {
                    NS_LOG_WARN("Destination router " << traffic.destRouter << " has no IP address, skipping flow");
                    ++flowIndex;
                    continue;
                }

                if (traffic.protocol == "udp") {
                    // Install UDP server on destination (no echo, just receive)
                    UdpServerHelper serverHelper(port);
                    ApplicationContainer serverApps = serverHelper.Install(destNode);
                    serverApps.Start(Seconds(1.0));
                    serverApps.Stop(Seconds(traffic.duration + 3.0));

                    // Install UDP client on source (one-way traffic to server)
                    UdpClientHelper clientHelper(destAddr, port);
                    clientHelper.SetAttribute("MaxPackets", UintegerValue(traffic.numPackets));
                    clientHelper.SetAttribute("Interval", TimeValue(Seconds(traffic.duration / (double)traffic.numPackets)));
                    clientHelper.SetAttribute("PacketSize", UintegerValue(traffic.packetSize));

                    ApplicationContainer clientApps = clientHelper.Install(nodeMap[traffic.srcRouter]);
                    clientApps.Start(Seconds(2.0));
                    clientApps.Stop(Seconds(traffic.duration + 2.0));
                }

                ++flowIndex;
            } else {
                
            }
        }

        // Enable flow monitoring
        monitor = flowmon.InstallAll();

        Simulator::Schedule(Seconds(1.0), collectTraffic);

        // Run simulation
        NS_LOG_INFO("Running simulation...");
        Simulator::Stop(Seconds(30.0));
        Simulator::Run();

        // Print flow statistics
        monitor->CheckForLostPackets();
        Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier>(flowmon.GetClassifier());
        std::map<FlowId, FlowMonitor::FlowStats> stats = monitor->GetFlowStats();

        NS_LOG_INFO("Flow Statistics:");
        for (std::map<FlowId, FlowMonitor::FlowStats>::const_iterator i = stats.begin(); i != stats.end(); ++i) {
            Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow(i->first);
            NS_LOG_INFO("Flow " << i->first << " (" << t.sourceAddress << " -> " << t.destinationAddress << ")");
            NS_LOG_INFO("  Tx Packets: " << i->second.txPackets);
            NS_LOG_INFO("  Rx Packets: " << i->second.rxPackets);
            NS_LOG_INFO("  Lost Packets: " << i->second.lostPackets);
            NS_LOG_INFO("  Throughput: " << i->second.rxBytes * 8.0 / (i->second.timeLastRxPacket.GetSeconds() - i->second.timeFirstTxPacket.GetSeconds()) / 1024 / 1024 << " Mbps");
        }

        Simulator::Destroy();

        trafficCsv.close();
    }

    return 0;
}
