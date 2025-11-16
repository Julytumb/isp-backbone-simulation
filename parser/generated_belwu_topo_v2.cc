#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv4-static-routing-helper.h"
#include "ns3/packet-sink.h"
#include <string>
#include <map>
#include <cstdint>
#include <utility>

using namespace ns3;
NS_LOG_COMPONENT_DEFINE("GeneratedBelwuTopology");

int main(int argc, char* argv[])
{
    NS_LOG_INFO("--- 1. Initializing Helpers & Containers ---");
    std::map<std::string, Ptr<Node>> nodeMap;
    std::map<std::string, std::string> nodeKindMap;
    std::map<std::pair<std::string, uint32_t>, std::string> nodeIfaceToNameMap;
    NodeContainer allNodes;
    InternetStackHelper stack;
    PointToPointHelper p2p;
    Ipv4AddressHelper address;
    Ipv4StaticRoutingHelper staticRoutingHelper;

    NS_LOG_INFO("--- 1b. Populating Node 'Kind' Map ---");
    nodeKindMap["aal-hs-1"] = "cisco";
    nodeKindMap["alb-hs-1"] = "cisco";
    nodeKindMap["bib-hs-1"] = "cisco";
    nodeKindMap["boe-1"] = "cisco";
    nodeKindMap["ess-hs-1"] = "cisco";
    nodeKindMap["f"] = "cisco";
    nodeKindMap["fdh-dhbw-1"] = "cisco";
    nodeKindMap["fds-stw-1"] = "cisco";
    nodeKindMap["fra-decix-a99"] = "cisco";
    nodeKindMap["fra-tc-a99"] = "cisco";
    nodeKindMap["frb-kg-1"] = "cisco";
    nodeKindMap["frb-rz-1"] = "cisco";
    nodeKindMap["frb-rz-2"] = "cisco";
    nodeKindMap["gei-hs-1"] = "cisco";
    nodeKindMap["goe-hs-1"] = "cisco";
    nodeKindMap["hdh-dhbw-1"] = "cisco";
    nodeKindMap["hdl-city-1"] = "cisco";
    nodeKindMap["hdl-rz-1"] = "cisco";
    nodeKindMap["hlb-hs-1"] = "cisco";
    nodeKindMap["hor-dhbw-1"] = "cisco";
    nodeKindMap["k"] = "cisco";
    nodeKindMap["kar-bib-1"] = "cisco";
    nodeKindMap["kar-nord-1"] = "cisco";
    nodeKindMap["kar-rz-1"] = "cisco";
    nodeKindMap["kar-rz-a99"] = "cisco";
    nodeKindMap["keh-hs-1"] = "cisco";
    nodeKindMap["kon-bib-1"] = "cisco";
    nodeKindMap["kon-rz-1"] = "cisco";
    nodeKindMap["lbg-fa-1"] = "cisco";
    nodeKindMap["lbg-ph-1"] = "cisco";
    nodeKindMap["loe-dhbw-1"] = "cisco";
    nodeKindMap["man-rz-1"] = "cisco";
    nodeKindMap["man-schl-1"] = "cisco";
    nodeKindMap["mar-dla-1"] = "cisco";
    nodeKindMap["mos-dhbw-2"] = "cisco";
    nodeKindMap["n"] = "cisco";
    nodeKindMap["ofg-hs-1"] = "cisco";
    nodeKindMap["pfo-hs-1"] = "cisco";
    nodeKindMap["rav-dhbw-1"] = "cisco";
    nodeKindMap["re"] = "cisco";
    nodeKindMap["rot-hs-1"] = "cisco";
    nodeKindMap["sgd-ph-1"] = "cisco";
    nodeKindMap["shl-hs-2"] = "cisco";
    nodeKindMap["sig-hs-1"] = "cisco";
    nodeKindMap["st"] = "cisco";
    nodeKindMap["t"] = "cisco";
    nodeKindMap["tro-mh-1"] = "cisco";
    nodeKindMap["vis-hs-1"] = "cisco";
    nodeKindMap["wei-hs-1"] = "cisco";

    NS_LOG_INFO("--- 2. Creating Nodes ---");
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["aal-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("aal-hs-1", node);
        if (nodeKindMap.find("aal-hs-1") == nodeKindMap.end()) {
            nodeKindMap["aal-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["alb-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("alb-hs-1", node);
        if (nodeKindMap.find("alb-hs-1") == nodeKindMap.end()) {
            nodeKindMap["alb-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["bib-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("bib-hs-1", node);
        if (nodeKindMap.find("bib-hs-1") == nodeKindMap.end()) {
            nodeKindMap["bib-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["boe-1"] = node;
        allNodes.Add(node);
        Names::Add("boe-1", node);
        if (nodeKindMap.find("boe-1") == nodeKindMap.end()) {
            nodeKindMap["boe-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["ess-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("ess-hs-1", node);
        if (nodeKindMap.find("ess-hs-1") == nodeKindMap.end()) {
            nodeKindMap["ess-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["fdh-dhbw-1"] = node;
        allNodes.Add(node);
        Names::Add("fdh-dhbw-1", node);
        if (nodeKindMap.find("fdh-dhbw-1") == nodeKindMap.end()) {
            nodeKindMap["fdh-dhbw-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["fds-stw-1"] = node;
        allNodes.Add(node);
        Names::Add("fds-stw-1", node);
        if (nodeKindMap.find("fds-stw-1") == nodeKindMap.end()) {
            nodeKindMap["fds-stw-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["fra-decix-a99"] = node;
        allNodes.Add(node);
        Names::Add("fra-decix-a99", node);
        if (nodeKindMap.find("fra-decix-a99") == nodeKindMap.end()) {
            nodeKindMap["fra-decix-a99"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["fra-tc-a99"] = node;
        allNodes.Add(node);
        Names::Add("fra-tc-a99", node);
        if (nodeKindMap.find("fra-tc-a99") == nodeKindMap.end()) {
            nodeKindMap["fra-tc-a99"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["frb-kg-1"] = node;
        allNodes.Add(node);
        Names::Add("frb-kg-1", node);
        if (nodeKindMap.find("frb-kg-1") == nodeKindMap.end()) {
            nodeKindMap["frb-kg-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["frb-rz-1"] = node;
        allNodes.Add(node);
        Names::Add("frb-rz-1", node);
        if (nodeKindMap.find("frb-rz-1") == nodeKindMap.end()) {
            nodeKindMap["frb-rz-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["frb-rz-2"] = node;
        allNodes.Add(node);
        Names::Add("frb-rz-2", node);
        if (nodeKindMap.find("frb-rz-2") == nodeKindMap.end()) {
            nodeKindMap["frb-rz-2"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["fuw-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("fuw-hs-1", node);
        if (nodeKindMap.find("fuw-hs-1") == nodeKindMap.end()) {
            nodeKindMap["fuw-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["gei-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("gei-hs-1", node);
        if (nodeKindMap.find("gei-hs-1") == nodeKindMap.end()) {
            nodeKindMap["gei-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["goe-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("goe-hs-1", node);
        if (nodeKindMap.find("goe-hs-1") == nodeKindMap.end()) {
            nodeKindMap["goe-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["hdh-dhbw-1"] = node;
        allNodes.Add(node);
        Names::Add("hdh-dhbw-1", node);
        if (nodeKindMap.find("hdh-dhbw-1") == nodeKindMap.end()) {
            nodeKindMap["hdh-dhbw-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["hdl-city-1"] = node;
        allNodes.Add(node);
        Names::Add("hdl-city-1", node);
        if (nodeKindMap.find("hdl-city-1") == nodeKindMap.end()) {
            nodeKindMap["hdl-city-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["hdl-rz-1"] = node;
        allNodes.Add(node);
        Names::Add("hdl-rz-1", node);
        if (nodeKindMap.find("hdl-rz-1") == nodeKindMap.end()) {
            nodeKindMap["hdl-rz-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["hlb-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("hlb-hs-1", node);
        if (nodeKindMap.find("hlb-hs-1") == nodeKindMap.end()) {
            nodeKindMap["hlb-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["hor-dhbw-1"] = node;
        allNodes.Add(node);
        Names::Add("hor-dhbw-1", node);
        if (nodeKindMap.find("hor-dhbw-1") == nodeKindMap.end()) {
            nodeKindMap["hor-dhbw-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["kar-bib-1"] = node;
        allNodes.Add(node);
        Names::Add("kar-bib-1", node);
        if (nodeKindMap.find("kar-bib-1") == nodeKindMap.end()) {
            nodeKindMap["kar-bib-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["kar-nord-1"] = node;
        allNodes.Add(node);
        Names::Add("kar-nord-1", node);
        if (nodeKindMap.find("kar-nord-1") == nodeKindMap.end()) {
            nodeKindMap["kar-nord-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["kar-rz-1"] = node;
        allNodes.Add(node);
        Names::Add("kar-rz-1", node);
        if (nodeKindMap.find("kar-rz-1") == nodeKindMap.end()) {
            nodeKindMap["kar-rz-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["kar-rz-a99"] = node;
        allNodes.Add(node);
        Names::Add("kar-rz-a99", node);
        if (nodeKindMap.find("kar-rz-a99") == nodeKindMap.end()) {
            nodeKindMap["kar-rz-a99"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["keh-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("keh-hs-1", node);
        if (nodeKindMap.find("keh-hs-1") == nodeKindMap.end()) {
            nodeKindMap["keh-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["kon-bib-1"] = node;
        allNodes.Add(node);
        Names::Add("kon-bib-1", node);
        if (nodeKindMap.find("kon-bib-1") == nodeKindMap.end()) {
            nodeKindMap["kon-bib-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["kon-rz-1"] = node;
        allNodes.Add(node);
        Names::Add("kon-rz-1", node);
        if (nodeKindMap.find("kon-rz-1") == nodeKindMap.end()) {
            nodeKindMap["kon-rz-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["kue-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("kue-hs-1", node);
        if (nodeKindMap.find("kue-hs-1") == nodeKindMap.end()) {
            nodeKindMap["kue-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["lbg-fa-1"] = node;
        allNodes.Add(node);
        Names::Add("lbg-fa-1", node);
        if (nodeKindMap.find("lbg-fa-1") == nodeKindMap.end()) {
            nodeKindMap["lbg-fa-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["lbg-ph-1"] = node;
        allNodes.Add(node);
        Names::Add("lbg-ph-1", node);
        if (nodeKindMap.find("lbg-ph-1") == nodeKindMap.end()) {
            nodeKindMap["lbg-ph-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["loe-dhbw-1"] = node;
        allNodes.Add(node);
        Names::Add("loe-dhbw-1", node);
        if (nodeKindMap.find("loe-dhbw-1") == nodeKindMap.end()) {
            nodeKindMap["loe-dhbw-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["man-rz-1"] = node;
        allNodes.Add(node);
        Names::Add("man-rz-1", node);
        if (nodeKindMap.find("man-rz-1") == nodeKindMap.end()) {
            nodeKindMap["man-rz-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["man-schl-1"] = node;
        allNodes.Add(node);
        Names::Add("man-schl-1", node);
        if (nodeKindMap.find("man-schl-1") == nodeKindMap.end()) {
            nodeKindMap["man-schl-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["mar-dla-1"] = node;
        allNodes.Add(node);
        Names::Add("mar-dla-1", node);
        if (nodeKindMap.find("mar-dla-1") == nodeKindMap.end()) {
            nodeKindMap["mar-dla-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["mos-dhbw-2"] = node;
        allNodes.Add(node);
        Names::Add("mos-dhbw-2", node);
        if (nodeKindMap.find("mos-dhbw-2") == nodeKindMap.end()) {
            nodeKindMap["mos-dhbw-2"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["nue-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("nue-hs-1", node);
        if (nodeKindMap.find("nue-hs-1") == nodeKindMap.end()) {
            nodeKindMap["nue-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["ofg-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("ofg-hs-1", node);
        if (nodeKindMap.find("ofg-hs-1") == nodeKindMap.end()) {
            nodeKindMap["ofg-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["pfo-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("pfo-hs-1", node);
        if (nodeKindMap.find("pfo-hs-1") == nodeKindMap.end()) {
            nodeKindMap["pfo-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["rav-dhbw-1"] = node;
        allNodes.Add(node);
        Names::Add("rav-dhbw-1", node);
        if (nodeKindMap.find("rav-dhbw-1") == nodeKindMap.end()) {
            nodeKindMap["rav-dhbw-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["reu-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("reu-hs-1", node);
        if (nodeKindMap.find("reu-hs-1") == nodeKindMap.end()) {
            nodeKindMap["reu-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["rot-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("rot-hs-1", node);
        if (nodeKindMap.find("rot-hs-1") == nodeKindMap.end()) {
            nodeKindMap["rot-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["sgd-ph-1"] = node;
        allNodes.Add(node);
        Names::Add("sgd-ph-1", node);
        if (nodeKindMap.find("sgd-ph-1") == nodeKindMap.end()) {
            nodeKindMap["sgd-ph-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["shl-hs-2"] = node;
        allNodes.Add(node);
        Names::Add("shl-hs-2", node);
        if (nodeKindMap.find("shl-hs-2") == nodeKindMap.end()) {
            nodeKindMap["shl-hs-2"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["sig-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("sig-hs-1", node);
        if (nodeKindMap.find("sig-hs-1") == nodeKindMap.end()) {
            nodeKindMap["sig-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["stu-al30-1"] = node;
        allNodes.Add(node);
        Names::Add("stu-al30-1", node);
        if (nodeKindMap.find("stu-al30-1") == nodeKindMap.end()) {
            nodeKindMap["stu-al30-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["stu-eti-1"] = node;
        allNodes.Add(node);
        Names::Add("stu-eti-1", node);
        if (nodeKindMap.find("stu-eti-1") == nodeKindMap.end()) {
            nodeKindMap["stu-eti-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["stu-eti-a99"] = node;
        allNodes.Add(node);
        Names::Add("stu-eti-a99", node);
        if (nodeKindMap.find("stu-eti-a99") == nodeKindMap.end()) {
            nodeKindMap["stu-eti-a99"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["tro-mh-1"] = node;
        allNodes.Add(node);
        Names::Add("tro-mh-1", node);
        if (nodeKindMap.find("tro-mh-1") == nodeKindMap.end()) {
            nodeKindMap["tro-mh-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["tue-mor-1"] = node;
        allNodes.Add(node);
        Names::Add("tue-mor-1", node);
        if (nodeKindMap.find("tue-mor-1") == nodeKindMap.end()) {
            nodeKindMap["tue-mor-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["tue-wae-1"] = node;
        allNodes.Add(node);
        Names::Add("tue-wae-1", node);
        if (nodeKindMap.find("tue-wae-1") == nodeKindMap.end()) {
            nodeKindMap["tue-wae-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["tut-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("tut-hs-1", node);
        if (nodeKindMap.find("tut-hs-1") == nodeKindMap.end()) {
            nodeKindMap["tut-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["ulm-n25-1"] = node;
        allNodes.Add(node);
        Names::Add("ulm-n25-1", node);
        if (nodeKindMap.find("ulm-n25-1") == nodeKindMap.end()) {
            nodeKindMap["ulm-n25-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["ulm-n26-1"] = node;
        allNodes.Add(node);
        Names::Add("ulm-n26-1", node);
        if (nodeKindMap.find("ulm-n26-1") == nodeKindMap.end()) {
            nodeKindMap["ulm-n26-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["vis-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("vis-hs-1", node);
        if (nodeKindMap.find("vis-hs-1") == nodeKindMap.end()) {
            nodeKindMap["vis-hs-1"] = "generic-router";
        }
    }
    {
        Ptr<Node> node = CreateObject<Node>();
        nodeMap["wei-hs-1"] = node;
        allNodes.Add(node);
        Names::Add("wei-hs-1", node);
        if (nodeKindMap.find("wei-hs-1") == nodeKindMap.end()) {
            nodeKindMap["wei-hs-1"] = "generic-router";
        }
    }
    NS_LOG_INFO("Created " << allNodes.GetN() << " nodes.");
    stack.Install(allNodes);

    NS_LOG_INFO("--- 3. Creating Links & Predicting IPs ---");
    // Link 1: stu-eti-a99(TenGigE0/0/0/9) <--> ulm-n25-1(TenGigE0/0/0/8)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link1(nodeMap["stu-eti-a99"], nodeMap["ulm-n25-1"]);
    NetDeviceContainer devices1 = p2p.Install(link1);
    address.SetBase("10.1.2.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces1 = address.Assign(devices1);
    uint32_t iface1a_idx = interfaces1.Get(0).second;
    uint32_t iface1b_idx = interfaces1.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface1a_idx)] = "TenGigE0/0/0/9";
    nodeIfaceToNameMap[std::make_pair("ulm-n25-1", iface1b_idx)] = "TenGigE0/0/0/8";

    // Link 2: ulm-n25-1(TenGigE0/0/0/7) <--> ulm-n26-1(TenGigE0/0/0/4)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link2(nodeMap["ulm-n25-1"], nodeMap["ulm-n26-1"]);
    NetDeviceContainer devices2 = p2p.Install(link2);
    address.SetBase("10.1.3.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces2 = address.Assign(devices2);
    uint32_t iface2a_idx = interfaces2.Get(0).second;
    uint32_t iface2b_idx = interfaces2.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("ulm-n25-1", iface2a_idx)] = "TenGigE0/0/0/7";
    nodeIfaceToNameMap[std::make_pair("ulm-n26-1", iface2b_idx)] = "TenGigE0/0/0/4";

    // Link 3: hlb-hs-1(TenGigE0/0/0/15) <--> kue-hs-1(TenGigE0/0/0/3)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link3(nodeMap["hlb-hs-1"], nodeMap["kue-hs-1"]);
    NetDeviceContainer devices3 = p2p.Install(link3);
    address.SetBase("10.1.4.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces3 = address.Assign(devices3);
    uint32_t iface3a_idx = interfaces3.Get(0).second;
    uint32_t iface3b_idx = interfaces3.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hlb-hs-1", iface3a_idx)] = "TenGigE0/0/0/15";
    nodeIfaceToNameMap[std::make_pair("kue-hs-1", iface3b_idx)] = "TenGigE0/0/0/3";

    // Link 4: kue-hs-1(TenGigE0/0/0/6) <--> shl-hs-2(TenGigabitEthernet0/1/1)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link4(nodeMap["kue-hs-1"], nodeMap["shl-hs-2"]);
    NetDeviceContainer devices4 = p2p.Install(link4);
    address.SetBase("10.1.5.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces4 = address.Assign(devices4);
    uint32_t iface4a_idx = interfaces4.Get(0).second;
    uint32_t iface4b_idx = interfaces4.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kue-hs-1", iface4a_idx)] = "TenGigE0/0/0/6";
    nodeIfaceToNameMap[std::make_pair("shl-hs-2", iface4b_idx)] = "TenGigabitEthernet0/1/1";

    // Link 5: stu-eti-a99(TenGigE0/0/0/10) <--> ess-hs-1(TenGigE0/0/0/11)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link5(nodeMap["stu-eti-a99"], nodeMap["ess-hs-1"]);
    NetDeviceContainer devices5 = p2p.Install(link5);
    address.SetBase("10.1.6.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces5 = address.Assign(devices5);
    uint32_t iface5a_idx = interfaces5.Get(0).second;
    uint32_t iface5b_idx = interfaces5.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface5a_idx)] = "TenGigE0/0/0/10";
    nodeIfaceToNameMap[std::make_pair("ess-hs-1", iface5b_idx)] = "TenGigE0/0/0/11";

    // Link 6: stu-al30-1(TenGigE0/0/0/16) <--> pfo-hs-1(TenGigE0/0/0/13)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link6(nodeMap["stu-al30-1"], nodeMap["pfo-hs-1"]);
    NetDeviceContainer devices6 = p2p.Install(link6);
    address.SetBase("10.1.7.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces6 = address.Assign(devices6);
    uint32_t iface6a_idx = interfaces6.Get(0).second;
    uint32_t iface6b_idx = interfaces6.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-al30-1", iface6a_idx)] = "TenGigE0/0/0/16";
    nodeIfaceToNameMap[std::make_pair("pfo-hs-1", iface6b_idx)] = "TenGigE0/0/0/13";

    // Link 7: kar-bib-1(TenGigE0/0/0/18) <--> pfo-hs-1(TenGigE0/0/0/12)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link7(nodeMap["kar-bib-1"], nodeMap["pfo-hs-1"]);
    NetDeviceContainer devices7 = p2p.Install(link7);
    address.SetBase("10.1.8.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces7 = address.Assign(devices7);
    uint32_t iface7a_idx = interfaces7.Get(0).second;
    uint32_t iface7b_idx = interfaces7.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-bib-1", iface7a_idx)] = "TenGigE0/0/0/18";
    nodeIfaceToNameMap[std::make_pair("pfo-hs-1", iface7b_idx)] = "TenGigE0/0/0/12";

    // Link 8: kon-rz-1(TenGigE0/0/0/10) <--> fdh-dhbw-1(TenGigE0/0/0/9)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link8(nodeMap["kon-rz-1"], nodeMap["fdh-dhbw-1"]);
    NetDeviceContainer devices8 = p2p.Install(link8);
    address.SetBase("10.1.9.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces8 = address.Assign(devices8);
    uint32_t iface8a_idx = interfaces8.Get(0).second;
    uint32_t iface8b_idx = interfaces8.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kon-rz-1", iface8a_idx)] = "TenGigE0/0/0/10";
    nodeIfaceToNameMap[std::make_pair("fdh-dhbw-1", iface8b_idx)] = "TenGigE0/0/0/9";

    // Link 9: fdh-dhbw-1(TenGigE0/0/0/10) <--> rav-dhbw-1(TenGigE0/0/0/9)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link9(nodeMap["fdh-dhbw-1"], nodeMap["rav-dhbw-1"]);
    NetDeviceContainer devices9 = p2p.Install(link9);
    address.SetBase("10.1.10.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces9 = address.Assign(devices9);
    uint32_t iface9a_idx = interfaces9.Get(0).second;
    uint32_t iface9b_idx = interfaces9.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("fdh-dhbw-1", iface9a_idx)] = "TenGigE0/0/0/10";
    nodeIfaceToNameMap[std::make_pair("rav-dhbw-1", iface9b_idx)] = "TenGigE0/0/0/9";

    // Link 10: wei-hs-1(TenGigE0/0/0/8) <--> rav-dhbw-1(TenGigE0/0/0/10)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link10(nodeMap["wei-hs-1"], nodeMap["rav-dhbw-1"]);
    NetDeviceContainer devices10 = p2p.Install(link10);
    address.SetBase("10.1.11.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces10 = address.Assign(devices10);
    uint32_t iface10a_idx = interfaces10.Get(0).second;
    uint32_t iface10b_idx = interfaces10.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("wei-hs-1", iface10a_idx)] = "TenGigE0/0/0/8";
    nodeIfaceToNameMap[std::make_pair("rav-dhbw-1", iface10b_idx)] = "TenGigE0/0/0/10";

    // Link 11: sig-hs-1(TenGigE0/0/0/6) <--> rav-dhbw-1(TenGigE0/0/0/8)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link11(nodeMap["sig-hs-1"], nodeMap["rav-dhbw-1"]);
    NetDeviceContainer devices11 = p2p.Install(link11);
    address.SetBase("10.1.12.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces11 = address.Assign(devices11);
    uint32_t iface11a_idx = interfaces11.Get(0).second;
    uint32_t iface11b_idx = interfaces11.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("sig-hs-1", iface11a_idx)] = "TenGigE0/0/0/6";
    nodeIfaceToNameMap[std::make_pair("rav-dhbw-1", iface11b_idx)] = "TenGigE0/0/0/8";

    // Link 12: nue-hs-1(TenGigE0/0/0/13) <--> reu-hs-1(TenGigE0/0/0/12)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link12(nodeMap["nue-hs-1"], nodeMap["reu-hs-1"]);
    NetDeviceContainer devices12 = p2p.Install(link12);
    address.SetBase("10.1.13.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces12 = address.Assign(devices12);
    uint32_t iface12a_idx = interfaces12.Get(0).second;
    uint32_t iface12b_idx = interfaces12.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("nue-hs-1", iface12a_idx)] = "TenGigE0/0/0/13";
    nodeIfaceToNameMap[std::make_pair("reu-hs-1", iface12b_idx)] = "TenGigE0/0/0/12";

    // Link 13: ulm-n26-1(TenGigE0/0/0/7) <--> hdh-dhbw-1(TenGigE0/0/0/8)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link13(nodeMap["ulm-n26-1"], nodeMap["hdh-dhbw-1"]);
    NetDeviceContainer devices13 = p2p.Install(link13);
    address.SetBase("10.1.14.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces13 = address.Assign(devices13);
    uint32_t iface13a_idx = interfaces13.Get(0).second;
    uint32_t iface13b_idx = interfaces13.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("ulm-n26-1", iface13a_idx)] = "TenGigE0/0/0/7";
    nodeIfaceToNameMap[std::make_pair("hdh-dhbw-1", iface13b_idx)] = "TenGigE0/0/0/8";

    // Link 14: hdh-dhbw-1(TenGigE0/0/0/9) <--> aal-hs-1(TenGigE0/0/0/10)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link14(nodeMap["hdh-dhbw-1"], nodeMap["aal-hs-1"]);
    NetDeviceContainer devices14 = p2p.Install(link14);
    address.SetBase("10.1.15.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces14 = address.Assign(devices14);
    uint32_t iface14a_idx = interfaces14.Get(0).second;
    uint32_t iface14b_idx = interfaces14.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hdh-dhbw-1", iface14a_idx)] = "TenGigE0/0/0/9";
    nodeIfaceToNameMap[std::make_pair("aal-hs-1", iface14b_idx)] = "TenGigE0/0/0/10";

    // Link 15: reu-hs-1(TenGigE0/0/0/14) <--> tue-wae-1(TenGigE0/0/0/13)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link15(nodeMap["reu-hs-1"], nodeMap["tue-wae-1"]);
    NetDeviceContainer devices15 = p2p.Install(link15);
    address.SetBase("10.1.16.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces15 = address.Assign(devices15);
    uint32_t iface15a_idx = interfaces15.Get(0).second;
    uint32_t iface15b_idx = interfaces15.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("reu-hs-1", iface15a_idx)] = "TenGigE0/0/0/14";
    nodeIfaceToNameMap[std::make_pair("tue-wae-1", iface15b_idx)] = "TenGigE0/0/0/13";

    // Link 16: ess-hs-1(TenGigE0/0/0/14) <--> nue-hs-1(TenGigE0/0/0/11)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link16(nodeMap["ess-hs-1"], nodeMap["nue-hs-1"]);
    NetDeviceContainer devices16 = p2p.Install(link16);
    address.SetBase("10.1.17.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces16 = address.Assign(devices16);
    uint32_t iface16a_idx = interfaces16.Get(0).second;
    uint32_t iface16b_idx = interfaces16.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("ess-hs-1", iface16a_idx)] = "TenGigE0/0/0/14";
    nodeIfaceToNameMap[std::make_pair("nue-hs-1", iface16b_idx)] = "TenGigE0/0/0/11";

    // Link 17: kar-rz-a99(HundredGigE0/4/0/1) <--> kar-rz-1(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link17(nodeMap["kar-rz-a99"], nodeMap["kar-rz-1"]);
    NetDeviceContainer devices17 = p2p.Install(link17);
    address.SetBase("10.1.18.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces17 = address.Assign(devices17);
    uint32_t iface17a_idx = interfaces17.Get(0).second;
    uint32_t iface17b_idx = interfaces17.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-rz-a99", iface17a_idx)] = "HundredGigE0/4/0/1";
    nodeIfaceToNameMap[std::make_pair("kar-rz-1", iface17b_idx)] = "HundredGigE0/0/1/0";

    // Link 18: aal-hs-1(TenGigE0/0/0/12) <--> sgd-ph-1(TenGigE0/0/0/14)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link18(nodeMap["aal-hs-1"], nodeMap["sgd-ph-1"]);
    NetDeviceContainer devices18 = p2p.Install(link18);
    address.SetBase("10.1.19.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces18 = address.Assign(devices18);
    uint32_t iface18a_idx = interfaces18.Get(0).second;
    uint32_t iface18b_idx = interfaces18.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("aal-hs-1", iface18a_idx)] = "TenGigE0/0/0/12";
    nodeIfaceToNameMap[std::make_pair("sgd-ph-1", iface18b_idx)] = "TenGigE0/0/0/14";

    // Link 19: hor-dhbw-1(TenGigE0/0/0/2) <--> fds-stw-1(TenGigabitEthernet0/0/26)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link19(nodeMap["hor-dhbw-1"], nodeMap["fds-stw-1"]);
    NetDeviceContainer devices19 = p2p.Install(link19);
    address.SetBase("10.1.20.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces19 = address.Assign(devices19);
    uint32_t iface19a_idx = interfaces19.Get(0).second;
    uint32_t iface19b_idx = interfaces19.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hor-dhbw-1", iface19a_idx)] = "TenGigE0/0/0/2";
    nodeIfaceToNameMap[std::make_pair("fds-stw-1", iface19b_idx)] = "TenGigabitEthernet0/0/26";

    // Link 20: keh-hs-1(TenGigE0/0/0/6) <--> fds-stw-1(TenGigabitEthernet0/0/27)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link20(nodeMap["keh-hs-1"], nodeMap["fds-stw-1"]);
    NetDeviceContainer devices20 = p2p.Install(link20);
    address.SetBase("10.1.21.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces20 = address.Assign(devices20);
    uint32_t iface20a_idx = interfaces20.Get(0).second;
    uint32_t iface20b_idx = interfaces20.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("keh-hs-1", iface20a_idx)] = "TenGigE0/0/0/6";
    nodeIfaceToNameMap[std::make_pair("fds-stw-1", iface20b_idx)] = "TenGigabitEthernet0/0/27";

    // Link 21: kue-hs-1(GigabitEthernet0/0/0/2) <--> shl-hs-2(GigabitEthernet0/0/23)
    p2p.SetDeviceAttribute("DataRate", StringValue("1Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link21(nodeMap["kue-hs-1"], nodeMap["shl-hs-2"]);
    NetDeviceContainer devices21 = p2p.Install(link21);
    address.SetBase("10.1.22.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces21 = address.Assign(devices21);
    uint32_t iface21a_idx = interfaces21.Get(0).second;
    uint32_t iface21b_idx = interfaces21.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kue-hs-1", iface21a_idx)] = "GigabitEthernet0/0/0/2";
    nodeIfaceToNameMap[std::make_pair("shl-hs-2", iface21b_idx)] = "GigabitEthernet0/0/23";

    // Link 22: tro-mh-1(TenGigabitEthernet0/0/4) <--> vis-hs-1(TenGigE0/0/0/2)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link22(nodeMap["tro-mh-1"], nodeMap["vis-hs-1"]);
    NetDeviceContainer devices22 = p2p.Install(link22);
    address.SetBase("10.1.23.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces22 = address.Assign(devices22);
    uint32_t iface22a_idx = interfaces22.Get(0).second;
    uint32_t iface22b_idx = interfaces22.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("tro-mh-1", iface22a_idx)] = "TenGigabitEthernet0/0/4";
    nodeIfaceToNameMap[std::make_pair("vis-hs-1", iface22b_idx)] = "TenGigE0/0/0/2";

    // Link 23: tut-hs-1(TenGigE0/0/0/8) <--> tro-mh-1(TenGigabitEthernet0/0/5)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link23(nodeMap["tut-hs-1"], nodeMap["tro-mh-1"]);
    NetDeviceContainer devices23 = p2p.Install(link23);
    address.SetBase("10.1.24.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces23 = address.Assign(devices23);
    uint32_t iface23a_idx = interfaces23.Get(0).second;
    uint32_t iface23b_idx = interfaces23.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("tut-hs-1", iface23a_idx)] = "TenGigE0/0/0/8";
    nodeIfaceToNameMap[std::make_pair("tro-mh-1", iface23b_idx)] = "TenGigabitEthernet0/0/5";

    // Link 24: tue-wae-1(TenGigE0/0/0/12) <--> tut-hs-1(TenGigE0/0/0/5)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link24(nodeMap["tue-wae-1"], nodeMap["tut-hs-1"]);
    NetDeviceContainer devices24 = p2p.Install(link24);
    address.SetBase("10.1.25.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces24 = address.Assign(devices24);
    uint32_t iface24a_idx = interfaces24.Get(0).second;
    uint32_t iface24b_idx = interfaces24.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("tue-wae-1", iface24a_idx)] = "TenGigE0/0/0/12";
    nodeIfaceToNameMap[std::make_pair("tut-hs-1", iface24b_idx)] = "TenGigE0/0/0/5";

    // Link 25: tut-hs-1(TenGigE0/0/0/7) <--> kon-bib-1(TenGigE0/0/0/12)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link25(nodeMap["tut-hs-1"], nodeMap["kon-bib-1"]);
    NetDeviceContainer devices25 = p2p.Install(link25);
    address.SetBase("10.1.26.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces25 = address.Assign(devices25);
    uint32_t iface25a_idx = interfaces25.Get(0).second;
    uint32_t iface25b_idx = interfaces25.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("tut-hs-1", iface25a_idx)] = "TenGigE0/0/0/7";
    nodeIfaceToNameMap[std::make_pair("kon-bib-1", iface25b_idx)] = "TenGigE0/0/0/12";

    // Link 26: vis-hs-1(TenGigE0/0/0/18) <--> fuw-hs-1(TenGigE0/0/0/9)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link26(nodeMap["vis-hs-1"], nodeMap["fuw-hs-1"]);
    NetDeviceContainer devices26 = p2p.Install(link26);
    address.SetBase("10.1.27.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces26 = address.Assign(devices26);
    uint32_t iface26a_idx = interfaces26.Get(0).second;
    uint32_t iface26b_idx = interfaces26.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("vis-hs-1", iface26a_idx)] = "TenGigE0/0/0/18";
    nodeIfaceToNameMap[std::make_pair("fuw-hs-1", iface26b_idx)] = "TenGigE0/0/0/9";

    // Link 27: ofg-hs-1(TenGigE0/0/0/15) <--> fuw-hs-1(TenGigE0/0/0/7)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link27(nodeMap["ofg-hs-1"], nodeMap["fuw-hs-1"]);
    NetDeviceContainer devices27 = p2p.Install(link27);
    address.SetBase("10.1.28.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces27 = address.Assign(devices27);
    uint32_t iface27a_idx = interfaces27.Get(0).second;
    uint32_t iface27b_idx = interfaces27.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("ofg-hs-1", iface27a_idx)] = "TenGigE0/0/0/15";
    nodeIfaceToNameMap[std::make_pair("fuw-hs-1", iface27b_idx)] = "TenGigE0/0/0/7";

    // Link 28: alb-hs-1(TenGigE0/0/0/4) <--> tue-wae-1(TenGigE0/0/0/9)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link28(nodeMap["alb-hs-1"], nodeMap["tue-wae-1"]);
    NetDeviceContainer devices28 = p2p.Install(link28);
    address.SetBase("10.1.29.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces28 = address.Assign(devices28);
    uint32_t iface28a_idx = interfaces28.Get(0).second;
    uint32_t iface28b_idx = interfaces28.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("alb-hs-1", iface28a_idx)] = "TenGigE0/0/0/4";
    nodeIfaceToNameMap[std::make_pair("tue-wae-1", iface28b_idx)] = "TenGigE0/0/0/9";

    // Link 29: kar-bib-1(TenGigE0/0/0/16) <--> ofg-hs-1(TenGigE0/0/0/14)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link29(nodeMap["kar-bib-1"], nodeMap["ofg-hs-1"]);
    NetDeviceContainer devices29 = p2p.Install(link29);
    address.SetBase("10.1.30.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces29 = address.Assign(devices29);
    uint32_t iface29a_idx = interfaces29.Get(0).second;
    uint32_t iface29b_idx = interfaces29.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-bib-1", iface29a_idx)] = "TenGigE0/0/0/16";
    nodeIfaceToNameMap[std::make_pair("ofg-hs-1", iface29b_idx)] = "TenGigE0/0/0/14";

    // Link 30: shl-hs-2(TenGigabitEthernet0/0/27) <--> sgd-ph-1(TenGigE0/0/0/15)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link30(nodeMap["shl-hs-2"], nodeMap["sgd-ph-1"]);
    NetDeviceContainer devices30 = p2p.Install(link30);
    address.SetBase("10.1.31.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces30 = address.Assign(devices30);
    uint32_t iface30a_idx = interfaces30.Get(0).second;
    uint32_t iface30b_idx = interfaces30.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("shl-hs-2", iface30a_idx)] = "TenGigabitEthernet0/0/27";
    nodeIfaceToNameMap[std::make_pair("sgd-ph-1", iface30b_idx)] = "TenGigE0/0/0/15";

    // Link 31: frb-rz-1(TenGigE0/0/0/18) <--> ofg-hs-1(TenGigE0/0/0/12)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link31(nodeMap["frb-rz-1"], nodeMap["ofg-hs-1"]);
    NetDeviceContainer devices31 = p2p.Install(link31);
    address.SetBase("10.1.32.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces31 = address.Assign(devices31);
    uint32_t iface31a_idx = interfaces31.Get(0).second;
    uint32_t iface31b_idx = interfaces31.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("frb-rz-1", iface31a_idx)] = "TenGigE0/0/0/18";
    nodeIfaceToNameMap[std::make_pair("ofg-hs-1", iface31b_idx)] = "TenGigE0/0/0/12";

    // Link 32: kon-rz-1(TenGigE0/0/0/13) <--> loe-dhbw-1(TenGigabitEthernet0/0/27)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link32(nodeMap["kon-rz-1"], nodeMap["loe-dhbw-1"]);
    NetDeviceContainer devices32 = p2p.Install(link32);
    address.SetBase("10.1.33.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces32 = address.Assign(devices32);
    uint32_t iface32a_idx = interfaces32.Get(0).second;
    uint32_t iface32b_idx = interfaces32.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kon-rz-1", iface32a_idx)] = "TenGigE0/0/0/13";
    nodeIfaceToNameMap[std::make_pair("loe-dhbw-1", iface32b_idx)] = "TenGigabitEthernet0/0/27";

    // Link 33: frb-kg-1(TenGigE0/0/0/9) <--> loe-dhbw-1(TenGigabitEthernet0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link33(nodeMap["frb-kg-1"], nodeMap["loe-dhbw-1"]);
    NetDeviceContainer devices33 = p2p.Install(link33);
    address.SetBase("10.1.34.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces33 = address.Assign(devices33);
    uint32_t iface33a_idx = interfaces33.Get(0).second;
    uint32_t iface33b_idx = interfaces33.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("frb-kg-1", iface33a_idx)] = "TenGigE0/0/0/9";
    nodeIfaceToNameMap[std::make_pair("loe-dhbw-1", iface33b_idx)] = "TenGigabitEthernet0/1/0";

    // Link 34: kon-rz-1(TenGigE0/0/0/5) <--> rav-dhbw-1(TenGigE0/0/0/11)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link34(nodeMap["kon-rz-1"], nodeMap["rav-dhbw-1"]);
    NetDeviceContainer devices34 = p2p.Install(link34);
    address.SetBase("10.1.35.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces34 = address.Assign(devices34);
    uint32_t iface34a_idx = interfaces34.Get(0).second;
    uint32_t iface34b_idx = interfaces34.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kon-rz-1", iface34a_idx)] = "TenGigE0/0/0/5";
    nodeIfaceToNameMap[std::make_pair("rav-dhbw-1", iface34b_idx)] = "TenGigE0/0/0/11";

    // Link 35: stu-al30-1(TenGigE0/0/0/20) <--> ulm-n26-1(TenGigE0/0/0/5)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link35(nodeMap["stu-al30-1"], nodeMap["ulm-n26-1"]);
    NetDeviceContainer devices35 = p2p.Install(link35);
    address.SetBase("10.1.36.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces35 = address.Assign(devices35);
    uint32_t iface35a_idx = interfaces35.Get(0).second;
    uint32_t iface35b_idx = interfaces35.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-al30-1", iface35a_idx)] = "TenGigE0/0/0/20";
    nodeIfaceToNameMap[std::make_pair("ulm-n26-1", iface35b_idx)] = "TenGigE0/0/0/5";

    // Link 36: stu-eti-a99(TenGigE0/0/1/7) <--> lbg-ph-1(TenGigE0/0/0/10)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link36(nodeMap["stu-eti-a99"], nodeMap["lbg-ph-1"]);
    NetDeviceContainer devices36 = p2p.Install(link36);
    address.SetBase("10.1.37.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces36 = address.Assign(devices36);
    uint32_t iface36a_idx = interfaces36.Get(0).second;
    uint32_t iface36b_idx = interfaces36.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface36a_idx)] = "TenGigE0/0/1/7";
    nodeIfaceToNameMap[std::make_pair("lbg-ph-1", iface36b_idx)] = "TenGigE0/0/0/10";

    // Link 37: tue-wae-1(TenGigE0/0/0/14) <--> rot-hs-1(TenGigabitEthernet0/0/5)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link37(nodeMap["tue-wae-1"], nodeMap["rot-hs-1"]);
    NetDeviceContainer devices37 = p2p.Install(link37);
    address.SetBase("10.1.38.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces37 = address.Assign(devices37);
    uint32_t iface37a_idx = interfaces37.Get(0).second;
    uint32_t iface37b_idx = interfaces37.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("tue-wae-1", iface37a_idx)] = "TenGigE0/0/0/14";
    nodeIfaceToNameMap[std::make_pair("rot-hs-1", iface37b_idx)] = "TenGigabitEthernet0/0/5";

    // Link 38: tue-mor-1(TenGigE0/0/0/5) <--> rot-hs-1(TenGigabitEthernet0/0/4)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link38(nodeMap["tue-mor-1"], nodeMap["rot-hs-1"]);
    NetDeviceContainer devices38 = p2p.Install(link38);
    address.SetBase("10.1.39.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces38 = address.Assign(devices38);
    uint32_t iface38a_idx = interfaces38.Get(0).second;
    uint32_t iface38b_idx = interfaces38.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("tue-mor-1", iface38a_idx)] = "TenGigE0/0/0/5";
    nodeIfaceToNameMap[std::make_pair("rot-hs-1", iface38b_idx)] = "TenGigabitEthernet0/0/4";

    // Link 39: stu-eti-a99(TenGigE0/0/1/8) <--> boe-1(TenGigabitEthernet0/0/26)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link39(nodeMap["stu-eti-a99"], nodeMap["boe-1"]);
    NetDeviceContainer devices39 = p2p.Install(link39);
    address.SetBase("10.1.40.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces39 = address.Assign(devices39);
    uint32_t iface39a_idx = interfaces39.Get(0).second;
    uint32_t iface39b_idx = interfaces39.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface39a_idx)] = "TenGigE0/0/1/8";
    nodeIfaceToNameMap[std::make_pair("boe-1", iface39b_idx)] = "TenGigabitEthernet0/0/26";

    // Link 40: hor-dhbw-1(TenGigE0/0/0/7) <--> boe-1(TenGigabitEthernet0/0/27)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link40(nodeMap["hor-dhbw-1"], nodeMap["boe-1"]);
    NetDeviceContainer devices40 = p2p.Install(link40);
    address.SetBase("10.1.41.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces40 = address.Assign(devices40);
    uint32_t iface40a_idx = interfaces40.Get(0).second;
    uint32_t iface40b_idx = interfaces40.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hor-dhbw-1", iface40a_idx)] = "TenGigE0/0/0/7";
    nodeIfaceToNameMap[std::make_pair("boe-1", iface40b_idx)] = "TenGigabitEthernet0/0/27";

    // Link 41: alb-hs-1(TenGigE0/0/0/6) <--> sig-hs-1(TenGigE0/0/0/7)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link41(nodeMap["alb-hs-1"], nodeMap["sig-hs-1"]);
    NetDeviceContainer devices41 = p2p.Install(link41);
    address.SetBase("10.1.42.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces41 = address.Assign(devices41);
    uint32_t iface41a_idx = interfaces41.Get(0).second;
    uint32_t iface41b_idx = interfaces41.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("alb-hs-1", iface41a_idx)] = "TenGigE0/0/0/6";
    nodeIfaceToNameMap[std::make_pair("sig-hs-1", iface41b_idx)] = "TenGigE0/0/0/7";

    // Link 42: stu-eti-a99(TenGigE0/0/1/6) <--> hor-dhbw-1(TenGigE0/0/0/8)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link42(nodeMap["stu-eti-a99"], nodeMap["hor-dhbw-1"]);
    NetDeviceContainer devices42 = p2p.Install(link42);
    address.SetBase("10.1.43.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces42 = address.Assign(devices42);
    uint32_t iface42a_idx = interfaces42.Get(0).second;
    uint32_t iface42b_idx = interfaces42.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface42a_idx)] = "TenGigE0/0/1/6";
    nodeIfaceToNameMap[std::make_pair("hor-dhbw-1", iface42b_idx)] = "TenGigE0/0/0/8";

    // Link 43: hor-dhbw-1(TenGigE0/0/0/6) <--> keh-hs-1(TenGigE0/0/0/8)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link43(nodeMap["hor-dhbw-1"], nodeMap["keh-hs-1"]);
    NetDeviceContainer devices43 = p2p.Install(link43);
    address.SetBase("10.1.44.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces43 = address.Assign(devices43);
    uint32_t iface43a_idx = interfaces43.Get(0).second;
    uint32_t iface43b_idx = interfaces43.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hor-dhbw-1", iface43a_idx)] = "TenGigE0/0/0/6";
    nodeIfaceToNameMap[std::make_pair("keh-hs-1", iface43b_idx)] = "TenGigE0/0/0/8";

    // Link 44: lbg-ph-1(TenGigE0/0/0/14) <--> lbg-fa-1(TenGigE0/0/0/15)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link44(nodeMap["lbg-ph-1"], nodeMap["lbg-fa-1"]);
    NetDeviceContainer devices44 = p2p.Install(link44);
    address.SetBase("10.1.45.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces44 = address.Assign(devices44);
    uint32_t iface44a_idx = interfaces44.Get(0).second;
    uint32_t iface44b_idx = interfaces44.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("lbg-ph-1", iface44a_idx)] = "TenGigE0/0/0/14";
    nodeIfaceToNameMap[std::make_pair("lbg-fa-1", iface44b_idx)] = "TenGigE0/0/0/15";

    // Link 45: ofg-hs-1(TenGigE0/0/0/13) <--> keh-hs-1(TenGigE0/0/0/7)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link45(nodeMap["ofg-hs-1"], nodeMap["keh-hs-1"]);
    NetDeviceContainer devices45 = p2p.Install(link45);
    address.SetBase("10.1.46.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces45 = address.Assign(devices45);
    uint32_t iface45a_idx = interfaces45.Get(0).second;
    uint32_t iface45b_idx = interfaces45.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("ofg-hs-1", iface45a_idx)] = "TenGigE0/0/0/13";
    nodeIfaceToNameMap[std::make_pair("keh-hs-1", iface45b_idx)] = "TenGigE0/0/0/7";

    // Link 46: kar-rz-1(HundredGigE0/0/1/1) <--> kar-bib-1(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link46(nodeMap["kar-rz-1"], nodeMap["kar-bib-1"]);
    NetDeviceContainer devices46 = p2p.Install(link46);
    address.SetBase("10.1.47.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces46 = address.Assign(devices46);
    uint32_t iface46a_idx = interfaces46.Get(0).second;
    uint32_t iface46b_idx = interfaces46.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-rz-1", iface46a_idx)] = "HundredGigE0/0/1/1";
    nodeIfaceToNameMap[std::make_pair("kar-bib-1", iface46b_idx)] = "HundredGigE0/0/1/0";

    // Link 47: kar-bib-1(HundredGigE0/0/1/1) <--> stu-al30-1(HundredGigE0/0/1/1)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link47(nodeMap["kar-bib-1"], nodeMap["stu-al30-1"]);
    NetDeviceContainer devices47 = p2p.Install(link47);
    address.SetBase("10.1.48.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces47 = address.Assign(devices47);
    uint32_t iface47a_idx = interfaces47.Get(0).second;
    uint32_t iface47b_idx = interfaces47.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-bib-1", iface47a_idx)] = "HundredGigE0/0/1/1";
    nodeIfaceToNameMap[std::make_pair("stu-al30-1", iface47b_idx)] = "HundredGigE0/0/1/1";

    // Link 48: tut-hs-1(TenGigE0/0/0/6) <--> vis-hs-1(TenGigE0/0/0/16)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link48(nodeMap["tut-hs-1"], nodeMap["vis-hs-1"]);
    NetDeviceContainer devices48 = p2p.Install(link48);
    address.SetBase("10.1.49.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces48 = address.Assign(devices48);
    uint32_t iface48a_idx = interfaces48.Get(0).second;
    uint32_t iface48b_idx = interfaces48.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("tut-hs-1", iface48a_idx)] = "TenGigE0/0/0/6";
    nodeIfaceToNameMap[std::make_pair("vis-hs-1", iface48b_idx)] = "TenGigE0/0/0/16";

    // Link 49: kar-rz-a99(HundredGigE0/4/0/4) <--> frb-rz-1(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link49(nodeMap["kar-rz-a99"], nodeMap["frb-rz-1"]);
    NetDeviceContainer devices49 = p2p.Install(link49);
    address.SetBase("10.1.50.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces49 = address.Assign(devices49);
    uint32_t iface49a_idx = interfaces49.Get(0).second;
    uint32_t iface49b_idx = interfaces49.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-rz-a99", iface49a_idx)] = "HundredGigE0/4/0/4";
    nodeIfaceToNameMap[std::make_pair("frb-rz-1", iface49b_idx)] = "HundredGigE0/0/1/0";

    // Link 50: stu-eti-a99(TenGigE0/0/1/10) <--> lbg-fa-1(TenGigE0/0/0/16)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link50(nodeMap["stu-eti-a99"], nodeMap["lbg-fa-1"]);
    NetDeviceContainer devices50 = p2p.Install(link50);
    address.SetBase("10.1.51.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces50 = address.Assign(devices50);
    uint32_t iface50a_idx = interfaces50.Get(0).second;
    uint32_t iface50b_idx = interfaces50.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface50a_idx)] = "TenGigE0/0/1/10";
    nodeIfaceToNameMap[std::make_pair("lbg-fa-1", iface50b_idx)] = "TenGigE0/0/0/16";

    // Link 51: lbg-ph-1(TenGigE0/0/0/8) <--> mar-dla-1(TenGigabitEthernet0/0/4)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link51(nodeMap["lbg-ph-1"], nodeMap["mar-dla-1"]);
    NetDeviceContainer devices51 = p2p.Install(link51);
    address.SetBase("10.1.52.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces51 = address.Assign(devices51);
    uint32_t iface51a_idx = interfaces51.Get(0).second;
    uint32_t iface51b_idx = interfaces51.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("lbg-ph-1", iface51a_idx)] = "TenGigE0/0/0/8";
    nodeIfaceToNameMap[std::make_pair("mar-dla-1", iface51b_idx)] = "TenGigabitEthernet0/0/4";

    // Link 52: hlb-hs-1(TenGigE0/0/0/12) <--> mar-dla-1(TenGigabitEthernet0/0/5)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link52(nodeMap["hlb-hs-1"], nodeMap["mar-dla-1"]);
    NetDeviceContainer devices52 = p2p.Install(link52);
    address.SetBase("10.1.53.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces52 = address.Assign(devices52);
    uint32_t iface52a_idx = interfaces52.Get(0).second;
    uint32_t iface52b_idx = interfaces52.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hlb-hs-1", iface52a_idx)] = "TenGigE0/0/0/12";
    nodeIfaceToNameMap[std::make_pair("mar-dla-1", iface52b_idx)] = "TenGigabitEthernet0/0/5";

    // Link 53: stu-eti-a99(TenGigE0/0/1/4) <--> hlb-hs-1(TenGigE0/0/0/17)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link53(nodeMap["stu-eti-a99"], nodeMap["hlb-hs-1"]);
    NetDeviceContainer devices53 = p2p.Install(link53);
    address.SetBase("10.1.54.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces53 = address.Assign(devices53);
    uint32_t iface53a_idx = interfaces53.Get(0).second;
    uint32_t iface53b_idx = interfaces53.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface53a_idx)] = "TenGigE0/0/1/4";
    nodeIfaceToNameMap[std::make_pair("hlb-hs-1", iface53b_idx)] = "TenGigE0/0/0/17";

    // Link 54: stu-eti-a99(TenGigE0/0/1/5) <--> hlb-hs-1(TenGigE0/0/0/20)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link54(nodeMap["stu-eti-a99"], nodeMap["hlb-hs-1"]);
    NetDeviceContainer devices54 = p2p.Install(link54);
    address.SetBase("10.1.55.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces54 = address.Assign(devices54);
    uint32_t iface54a_idx = interfaces54.Get(0).second;
    uint32_t iface54b_idx = interfaces54.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface54a_idx)] = "TenGigE0/0/1/5";
    nodeIfaceToNameMap[std::make_pair("hlb-hs-1", iface54b_idx)] = "TenGigE0/0/0/20";

    // Link 55: ulm-n26-1(TenGigE0/0/0/9) <--> bib-hs-1(TenGigE0/0/0/9)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link55(nodeMap["ulm-n26-1"], nodeMap["bib-hs-1"]);
    NetDeviceContainer devices55 = p2p.Install(link55);
    address.SetBase("10.1.56.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces55 = address.Assign(devices55);
    uint32_t iface55a_idx = interfaces55.Get(0).second;
    uint32_t iface55b_idx = interfaces55.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("ulm-n26-1", iface55a_idx)] = "TenGigE0/0/0/9";
    nodeIfaceToNameMap[std::make_pair("bib-hs-1", iface55b_idx)] = "TenGigE0/0/0/9";

    // Link 56: ulm-n25-1(TenGigE0/0/0/12) <--> gei-hs-1(TenGigabitEthernet0/0/24)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link56(nodeMap["ulm-n25-1"], nodeMap["gei-hs-1"]);
    NetDeviceContainer devices56 = p2p.Install(link56);
    address.SetBase("10.1.57.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces56 = address.Assign(devices56);
    uint32_t iface56a_idx = interfaces56.Get(0).second;
    uint32_t iface56b_idx = interfaces56.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("ulm-n25-1", iface56a_idx)] = "TenGigE0/0/0/12";
    nodeIfaceToNameMap[std::make_pair("gei-hs-1", iface56b_idx)] = "TenGigabitEthernet0/0/24";

    // Link 57: hlb-hs-1(TenGigE0/0/0/18) <--> lbg-ph-1(TenGigE0/0/0/13)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link57(nodeMap["hlb-hs-1"], nodeMap["lbg-ph-1"]);
    NetDeviceContainer devices57 = p2p.Install(link57);
    address.SetBase("10.1.58.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces57 = address.Assign(devices57);
    uint32_t iface57a_idx = interfaces57.Get(0).second;
    uint32_t iface57b_idx = interfaces57.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hlb-hs-1", iface57a_idx)] = "TenGigE0/0/0/18";
    nodeIfaceToNameMap[std::make_pair("lbg-ph-1", iface57b_idx)] = "TenGigE0/0/0/13";

    // Link 58: aal-hs-1(TenGigE0/0/0/13) <--> shl-hs-2(TenGigabitEthernet0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link58(nodeMap["aal-hs-1"], nodeMap["shl-hs-2"]);
    NetDeviceContainer devices58 = p2p.Install(link58);
    address.SetBase("10.1.59.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces58 = address.Assign(devices58);
    uint32_t iface58a_idx = interfaces58.Get(0).second;
    uint32_t iface58b_idx = interfaces58.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("aal-hs-1", iface58a_idx)] = "TenGigE0/0/0/13";
    nodeIfaceToNameMap[std::make_pair("shl-hs-2", iface58b_idx)] = "TenGigabitEthernet0/1/0";

    // Link 59: goe-hs-1(TenGigabitEthernet0/0/27) <--> gei-hs-1(TenGigabitEthernet0/0/27)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link59(nodeMap["goe-hs-1"], nodeMap["gei-hs-1"]);
    NetDeviceContainer devices59 = p2p.Install(link59);
    address.SetBase("10.1.60.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces59 = address.Assign(devices59);
    uint32_t iface59a_idx = interfaces59.Get(0).second;
    uint32_t iface59b_idx = interfaces59.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("goe-hs-1", iface59a_idx)] = "TenGigabitEthernet0/0/27";
    nodeIfaceToNameMap[std::make_pair("gei-hs-1", iface59b_idx)] = "TenGigabitEthernet0/0/27";

    // Link 60: ess-hs-1(TenGigE0/0/0/13) <--> goe-hs-1(TenGigabitEthernet0/0/26)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link60(nodeMap["ess-hs-1"], nodeMap["goe-hs-1"]);
    NetDeviceContainer devices60 = p2p.Install(link60);
    address.SetBase("10.1.61.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces60 = address.Assign(devices60);
    uint32_t iface60a_idx = interfaces60.Get(0).second;
    uint32_t iface60b_idx = interfaces60.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("ess-hs-1", iface60a_idx)] = "TenGigE0/0/0/13";
    nodeIfaceToNameMap[std::make_pair("goe-hs-1", iface60b_idx)] = "TenGigabitEthernet0/0/26";

    // Link 61: stu-eti-a99(HundredGigE0/1/0/0) <--> kar-rz-a99(HundredGigE0/1/0/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link61(nodeMap["stu-eti-a99"], nodeMap["kar-rz-a99"]);
    NetDeviceContainer devices61 = p2p.Install(link61);
    address.SetBase("10.1.62.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces61 = address.Assign(devices61);
    uint32_t iface61a_idx = interfaces61.Get(0).second;
    uint32_t iface61b_idx = interfaces61.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface61a_idx)] = "HundredGigE0/1/0/0";
    nodeIfaceToNameMap[std::make_pair("kar-rz-a99", iface61b_idx)] = "HundredGigE0/1/0/0";

    // Link 62: wei-hs-1(TenGigE0/0/0/9) <--> bib-hs-1(TenGigE0/0/0/10)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link62(nodeMap["wei-hs-1"], nodeMap["bib-hs-1"]);
    NetDeviceContainer devices62 = p2p.Install(link62);
    address.SetBase("10.1.63.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces62 = address.Assign(devices62);
    uint32_t iface62a_idx = interfaces62.Get(0).second;
    uint32_t iface62b_idx = interfaces62.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("wei-hs-1", iface62a_idx)] = "TenGigE0/0/0/9";
    nodeIfaceToNameMap[std::make_pair("bib-hs-1", iface62b_idx)] = "TenGigE0/0/0/10";

    // Link 63: hdl-rz-1(TenGigE0/0/0/2) <--> hdl-city-1(TenGigE0/0/0/3)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link63(nodeMap["hdl-rz-1"], nodeMap["hdl-city-1"]);
    NetDeviceContainer devices63 = p2p.Install(link63);
    address.SetBase("10.1.64.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces63 = address.Assign(devices63);
    uint32_t iface63a_idx = interfaces63.Get(0).second;
    uint32_t iface63b_idx = interfaces63.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hdl-rz-1", iface63a_idx)] = "TenGigE0/0/0/2";
    nodeIfaceToNameMap[std::make_pair("hdl-city-1", iface63b_idx)] = "TenGigE0/0/0/3";

    // Link 64: hdl-city-1(TenGigE0/0/0/4) <--> mos-dhbw-2(TenGigE0/0/0/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link64(nodeMap["hdl-city-1"], nodeMap["mos-dhbw-2"]);
    NetDeviceContainer devices64 = p2p.Install(link64);
    address.SetBase("10.1.65.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces64 = address.Assign(devices64);
    uint32_t iface64a_idx = interfaces64.Get(0).second;
    uint32_t iface64b_idx = interfaces64.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hdl-city-1", iface64a_idx)] = "TenGigE0/0/0/4";
    nodeIfaceToNameMap[std::make_pair("mos-dhbw-2", iface64b_idx)] = "TenGigE0/0/0/0";

    // Link 65: hlb-hs-1(TenGigE0/0/0/19) <--> mos-dhbw-2(TenGigE0/0/0/1)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link65(nodeMap["hlb-hs-1"], nodeMap["mos-dhbw-2"]);
    NetDeviceContainer devices65 = p2p.Install(link65);
    address.SetBase("10.1.66.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces65 = address.Assign(devices65);
    uint32_t iface65a_idx = interfaces65.Get(0).second;
    uint32_t iface65b_idx = interfaces65.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hlb-hs-1", iface65a_idx)] = "TenGigE0/0/0/19";
    nodeIfaceToNameMap[std::make_pair("mos-dhbw-2", iface65b_idx)] = "TenGigE0/0/0/1";

    // Link 66: stu-eti-a99(HundredGigE0/4/0/7) <--> fra-decix-a99(HundredGigE0/1/0/4)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link66(nodeMap["stu-eti-a99"], nodeMap["fra-decix-a99"]);
    NetDeviceContainer devices66 = p2p.Install(link66);
    address.SetBase("10.1.67.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces66 = address.Assign(devices66);
    uint32_t iface66a_idx = interfaces66.Get(0).second;
    uint32_t iface66b_idx = interfaces66.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface66a_idx)] = "HundredGigE0/4/0/7";
    nodeIfaceToNameMap[std::make_pair("fra-decix-a99", iface66b_idx)] = "HundredGigE0/1/0/4";

    // Link 67: kar-rz-a99(HundredGigE0/2/0/0) <--> fra-tc-a99(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link67(nodeMap["kar-rz-a99"], nodeMap["fra-tc-a99"]);
    NetDeviceContainer devices67 = p2p.Install(link67);
    address.SetBase("10.1.68.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces67 = address.Assign(devices67);
    uint32_t iface67a_idx = interfaces67.Get(0).second;
    uint32_t iface67b_idx = interfaces67.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-rz-a99", iface67a_idx)] = "HundredGigE0/2/0/0";
    nodeIfaceToNameMap[std::make_pair("fra-tc-a99", iface67b_idx)] = "HundredGigE0/0/1/0";

    // Link 68: kar-rz-a99(HundredGigE0/2/0/4) <--> stu-eti-a99(HundredGigE0/4/0/1)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link68(nodeMap["kar-rz-a99"], nodeMap["stu-eti-a99"]);
    NetDeviceContainer devices68 = p2p.Install(link68);
    address.SetBase("10.1.69.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces68 = address.Assign(devices68);
    uint32_t iface68a_idx = interfaces68.Get(0).second;
    uint32_t iface68b_idx = interfaces68.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-rz-a99", iface68a_idx)] = "HundredGigE0/2/0/4";
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface68b_idx)] = "HundredGigE0/4/0/1";

    // Link 69: kar-rz-a99(TenGigE0/0/0/4) <--> kar-nord-1(TenGigE0/0/0/4)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link69(nodeMap["kar-rz-a99"], nodeMap["kar-nord-1"]);
    NetDeviceContainer devices69 = p2p.Install(link69);
    address.SetBase("10.1.70.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces69 = address.Assign(devices69);
    uint32_t iface69a_idx = interfaces69.Get(0).second;
    uint32_t iface69b_idx = interfaces69.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-rz-a99", iface69a_idx)] = "TenGigE0/0/0/4";
    nodeIfaceToNameMap[std::make_pair("kar-nord-1", iface69b_idx)] = "TenGigE0/0/0/4";

    // Link 70: man-schl-1(TenGigE0/0/0/8) <--> kar-nord-1(TenGigE0/0/0/5)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link70(nodeMap["man-schl-1"], nodeMap["kar-nord-1"]);
    NetDeviceContainer devices70 = p2p.Install(link70);
    address.SetBase("10.1.71.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces70 = address.Assign(devices70);
    uint32_t iface70a_idx = interfaces70.Get(0).second;
    uint32_t iface70b_idx = interfaces70.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("man-schl-1", iface70a_idx)] = "TenGigE0/0/0/8";
    nodeIfaceToNameMap[std::make_pair("kar-nord-1", iface70b_idx)] = "TenGigE0/0/0/5";

    // Link 71: stu-eti-1(HundredGigE0/0/1/1) <--> stu-al30-1(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link71(nodeMap["stu-eti-1"], nodeMap["stu-al30-1"]);
    NetDeviceContainer devices71 = p2p.Install(link71);
    address.SetBase("10.1.72.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces71 = address.Assign(devices71);
    uint32_t iface71a_idx = interfaces71.Get(0).second;
    uint32_t iface71b_idx = interfaces71.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-1", iface71a_idx)] = "HundredGigE0/0/1/1";
    nodeIfaceToNameMap[std::make_pair("stu-al30-1", iface71b_idx)] = "HundredGigE0/0/1/0";

    // Link 72: frb-rz-1(TenGigE0/0/0/15) <--> frb-rz-2(TenGigabitEthernet0/0/26)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link72(nodeMap["frb-rz-1"], nodeMap["frb-rz-2"]);
    NetDeviceContainer devices72 = p2p.Install(link72);
    address.SetBase("10.1.73.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces72 = address.Assign(devices72);
    uint32_t iface72a_idx = interfaces72.Get(0).second;
    uint32_t iface72b_idx = interfaces72.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("frb-rz-1", iface72a_idx)] = "TenGigE0/0/0/15";
    nodeIfaceToNameMap[std::make_pair("frb-rz-2", iface72b_idx)] = "TenGigabitEthernet0/0/26";

    // Link 73: frb-rz-1(TenGigE0/0/0/16) <--> frb-rz-2(TenGigabitEthernet0/0/27)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link73(nodeMap["frb-rz-1"], nodeMap["frb-rz-2"]);
    NetDeviceContainer devices73 = p2p.Install(link73);
    address.SetBase("10.1.74.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces73 = address.Assign(devices73);
    uint32_t iface73a_idx = interfaces73.Get(0).second;
    uint32_t iface73b_idx = interfaces73.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("frb-rz-1", iface73a_idx)] = "TenGigE0/0/0/16";
    nodeIfaceToNameMap[std::make_pair("frb-rz-2", iface73b_idx)] = "TenGigabitEthernet0/0/27";

    // Link 74: frb-kg-1(TenGigE0/0/0/7) <--> frb-rz-2(TenGigabitEthernet0/0/25)
    p2p.SetDeviceAttribute("DataRate", StringValue("10Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link74(nodeMap["frb-kg-1"], nodeMap["frb-rz-2"]);
    NetDeviceContainer devices74 = p2p.Install(link74);
    address.SetBase("10.1.75.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces74 = address.Assign(devices74);
    uint32_t iface74a_idx = interfaces74.Get(0).second;
    uint32_t iface74b_idx = interfaces74.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("frb-kg-1", iface74a_idx)] = "TenGigE0/0/0/7";
    nodeIfaceToNameMap[std::make_pair("frb-rz-2", iface74b_idx)] = "TenGigabitEthernet0/0/25";

    // Link 75: fra-tc-a99(HundredGigE0/1/0/7) <--> fra-decix-a99(HundredGigE0/1/0/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link75(nodeMap["fra-tc-a99"], nodeMap["fra-decix-a99"]);
    NetDeviceContainer devices75 = p2p.Install(link75);
    address.SetBase("10.1.76.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces75 = address.Assign(devices75);
    uint32_t iface75a_idx = interfaces75.Get(0).second;
    uint32_t iface75b_idx = interfaces75.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("fra-tc-a99", iface75a_idx)] = "HundredGigE0/1/0/7";
    nodeIfaceToNameMap[std::make_pair("fra-decix-a99", iface75b_idx)] = "HundredGigE0/1/0/0";

    // Link 76: stu-eti-a99(HundredGigE0/4/0/11) <--> fra-decix-a99(HundredGigE0/1/0/3)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link76(nodeMap["stu-eti-a99"], nodeMap["fra-decix-a99"]);
    NetDeviceContainer devices76 = p2p.Install(link76);
    address.SetBase("10.1.77.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces76 = address.Assign(devices76);
    uint32_t iface76a_idx = interfaces76.Get(0).second;
    uint32_t iface76b_idx = interfaces76.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface76a_idx)] = "HundredGigE0/4/0/11";
    nodeIfaceToNameMap[std::make_pair("fra-decix-a99", iface76b_idx)] = "HundredGigE0/1/0/3";

    // Link 77: stu-eti-1(HundredGigE0/0/1/0) <--> stu-eti-a99(HundredGigE0/4/0/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link77(nodeMap["stu-eti-1"], nodeMap["stu-eti-a99"]);
    NetDeviceContainer devices77 = p2p.Install(link77);
    address.SetBase("10.1.78.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces77 = address.Assign(devices77);
    uint32_t iface77a_idx = interfaces77.Get(0).second;
    uint32_t iface77b_idx = interfaces77.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-1", iface77a_idx)] = "HundredGigE0/0/1/0";
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface77b_idx)] = "HundredGigE0/4/0/0";

    // Link 78: fra-decix-a99(HundredGigE0/1/0/10) <--> fra-tc-a99(HundredGigE0/1/0/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link78(nodeMap["fra-decix-a99"], nodeMap["fra-tc-a99"]);
    NetDeviceContainer devices78 = p2p.Install(link78);
    address.SetBase("10.1.79.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces78 = address.Assign(devices78);
    uint32_t iface78a_idx = interfaces78.Get(0).second;
    uint32_t iface78b_idx = interfaces78.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("fra-decix-a99", iface78a_idx)] = "HundredGigE0/1/0/10";
    nodeIfaceToNameMap[std::make_pair("fra-tc-a99", iface78b_idx)] = "HundredGigE0/1/0/0";

    // Link 79: kar-rz-a99(HundredGigE0/2/0/7) <--> fra-tc-a99(HundredGigE0/0/1/1)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link79(nodeMap["kar-rz-a99"], nodeMap["fra-tc-a99"]);
    NetDeviceContainer devices79 = p2p.Install(link79);
    address.SetBase("10.1.80.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces79 = address.Assign(devices79);
    uint32_t iface79a_idx = interfaces79.Get(0).second;
    uint32_t iface79b_idx = interfaces79.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-rz-a99", iface79a_idx)] = "HundredGigE0/2/0/7";
    nodeIfaceToNameMap[std::make_pair("fra-tc-a99", iface79b_idx)] = "HundredGigE0/0/1/1";

    // Link 80: stu-eti-a99(HundredGigE0/4/0/20) <--> tue-mor-1(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link80(nodeMap["stu-eti-a99"], nodeMap["tue-mor-1"]);
    NetDeviceContainer devices80 = p2p.Install(link80);
    address.SetBase("10.1.81.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces80 = address.Assign(devices80);
    uint32_t iface80a_idx = interfaces80.Get(0).second;
    uint32_t iface80b_idx = interfaces80.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("stu-eti-a99", iface80a_idx)] = "HundredGigE0/4/0/20";
    nodeIfaceToNameMap[std::make_pair("tue-mor-1", iface80b_idx)] = "HundredGigE0/0/1/0";

    // Link 81: tue-mor-1(HundredGigE0/0/1/1) <--> tue-wae-1(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link81(nodeMap["tue-mor-1"], nodeMap["tue-wae-1"]);
    NetDeviceContainer devices81 = p2p.Install(link81);
    address.SetBase("10.1.82.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces81 = address.Assign(devices81);
    uint32_t iface81a_idx = interfaces81.Get(0).second;
    uint32_t iface81b_idx = interfaces81.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("tue-mor-1", iface81a_idx)] = "HundredGigE0/0/1/1";
    nodeIfaceToNameMap[std::make_pair("tue-wae-1", iface81b_idx)] = "HundredGigE0/0/1/0";

    // Link 82: tue-wae-1(HundredGigE0/0/1/1) <--> kon-bib-1(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link82(nodeMap["tue-wae-1"], nodeMap["kon-bib-1"]);
    NetDeviceContainer devices82 = p2p.Install(link82);
    address.SetBase("10.1.83.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces82 = address.Assign(devices82);
    uint32_t iface82a_idx = interfaces82.Get(0).second;
    uint32_t iface82b_idx = interfaces82.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("tue-wae-1", iface82a_idx)] = "HundredGigE0/0/1/1";
    nodeIfaceToNameMap[std::make_pair("kon-bib-1", iface82b_idx)] = "HundredGigE0/0/1/0";

    // Link 83: kon-bib-1(HundredGigE0/0/1/1) <--> kon-rz-1(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link83(nodeMap["kon-bib-1"], nodeMap["kon-rz-1"]);
    NetDeviceContainer devices83 = p2p.Install(link83);
    address.SetBase("10.1.84.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces83 = address.Assign(devices83);
    uint32_t iface83a_idx = interfaces83.Get(0).second;
    uint32_t iface83b_idx = interfaces83.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kon-bib-1", iface83a_idx)] = "HundredGigE0/0/1/1";
    nodeIfaceToNameMap[std::make_pair("kon-rz-1", iface83b_idx)] = "HundredGigE0/0/1/0";

    // Link 84: kon-rz-1(HundredGigE0/0/1/1) <--> frb-kg-1(HundredGigE0/0/1/0)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link84(nodeMap["kon-rz-1"], nodeMap["frb-kg-1"]);
    NetDeviceContainer devices84 = p2p.Install(link84);
    address.SetBase("10.1.85.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces84 = address.Assign(devices84);
    uint32_t iface84a_idx = interfaces84.Get(0).second;
    uint32_t iface84b_idx = interfaces84.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kon-rz-1", iface84a_idx)] = "HundredGigE0/0/1/1";
    nodeIfaceToNameMap[std::make_pair("frb-kg-1", iface84b_idx)] = "HundredGigE0/0/1/0";

    // Link 85: frb-kg-1(HundredGigE0/0/1/1) <--> frb-rz-1(HundredGigE0/0/1/1)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link85(nodeMap["frb-kg-1"], nodeMap["frb-rz-1"]);
    NetDeviceContainer devices85 = p2p.Install(link85);
    address.SetBase("10.1.86.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces85 = address.Assign(devices85);
    uint32_t iface85a_idx = interfaces85.Get(0).second;
    uint32_t iface85b_idx = interfaces85.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("frb-kg-1", iface85a_idx)] = "HundredGigE0/0/1/1";
    nodeIfaceToNameMap[std::make_pair("frb-rz-1", iface85b_idx)] = "HundredGigE0/0/1/1";

    // Link 86: kar-rz-a99(HundredGigE0/4/0/6) <--> man-schl-1(HundredGigE0/0/1/1)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link86(nodeMap["kar-rz-a99"], nodeMap["man-schl-1"]);
    NetDeviceContainer devices86 = p2p.Install(link86);
    address.SetBase("10.1.87.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces86 = address.Assign(devices86);
    uint32_t iface86a_idx = interfaces86.Get(0).second;
    uint32_t iface86b_idx = interfaces86.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("kar-rz-a99", iface86a_idx)] = "HundredGigE0/4/0/6";
    nodeIfaceToNameMap[std::make_pair("man-schl-1", iface86b_idx)] = "HundredGigE0/0/1/1";

    // Link 87: man-schl-1(HundredGigE0/0/1/0) <--> man-rz-1(HundredGigE0/0/1/1)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link87(nodeMap["man-schl-1"], nodeMap["man-rz-1"]);
    NetDeviceContainer devices87 = p2p.Install(link87);
    address.SetBase("10.1.88.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces87 = address.Assign(devices87);
    uint32_t iface87a_idx = interfaces87.Get(0).second;
    uint32_t iface87b_idx = interfaces87.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("man-schl-1", iface87a_idx)] = "HundredGigE0/0/1/0";
    nodeIfaceToNameMap[std::make_pair("man-rz-1", iface87b_idx)] = "HundredGigE0/0/1/1";

    // Link 88: man-rz-1(HundredGigE0/0/1/0) <--> hdl-rz-1(HundredGigE0/0/1/1)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link88(nodeMap["man-rz-1"], nodeMap["hdl-rz-1"]);
    NetDeviceContainer devices88 = p2p.Install(link88);
    address.SetBase("10.1.89.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces88 = address.Assign(devices88);
    uint32_t iface88a_idx = interfaces88.Get(0).second;
    uint32_t iface88b_idx = interfaces88.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("man-rz-1", iface88a_idx)] = "HundredGigE0/0/1/0";
    nodeIfaceToNameMap[std::make_pair("hdl-rz-1", iface88b_idx)] = "HundredGigE0/0/1/1";

    // Link 89: hdl-rz-1(HundredGigE0/0/1/0) <--> fra-decix-a99(HundredGigE0/1/0/15)
    p2p.SetDeviceAttribute("DataRate", StringValue("100Gbps"));
    p2p.SetChannelAttribute("Delay", StringValue("1ms"));
    NodeContainer link89(nodeMap["hdl-rz-1"], nodeMap["fra-decix-a99"]);
    NetDeviceContainer devices89 = p2p.Install(link89);
    address.SetBase("10.1.90.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces89 = address.Assign(devices89);
    uint32_t iface89a_idx = interfaces89.Get(0).second;
    uint32_t iface89b_idx = interfaces89.Get(1).second;
    nodeIfaceToNameMap[std::make_pair("hdl-rz-1", iface89a_idx)] = "HundredGigE0/0/1/0";
    nodeIfaceToNameMap[std::make_pair("fra-decix-a99", iface89b_idx)] = "HundredGigE0/1/0/15";

    NS_LOG_INFO("--- 4. Calculating Routes & Adding Traffic ---");
    NS_LOG_INFO("--- 5. Installing Static Routes ---");

    NS_LOG_INFO("--- 6. Installing Traffic Applications ---");
    // Flow 0: aal-hs-1 -> kar-rz-1 (3.20Mbps)
    PacketSinkHelper sinkHelper0("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), 8080));
    ApplicationContainer sinkApp0 = sinkHelper0.Install(nodeMap["kar-rz-1"]);
    sinkApp0.Start(Seconds(1.0));
    sinkApp0.Stop(Seconds(15.0));
    OnOffHelper sourceHelper0("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address("10.1.18.2"), 8080));
    sourceHelper0.SetAttribute("DataRate", StringValue("3.20Mbps"));
    sourceHelper0.SetAttribute("PacketSize", UintegerValue(1500));
    sourceHelper0.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
    sourceHelper0.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
    ApplicationContainer sourceApp0 = sourceHelper0.Install(nodeMap["aal-hs-1"]);
    sourceApp0.Start(Seconds(2.0));
    sourceApp0.Stop(Seconds(2.0 + 10));

    // Flow 1: ess-hs-1 -> kar-rz-1 (3.20Mbps)
    PacketSinkHelper sinkHelper1("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), 8081));
    ApplicationContainer sinkApp1 = sinkHelper1.Install(nodeMap["kar-rz-1"]);
    sinkApp1.Start(Seconds(1.0));
    sinkApp1.Stop(Seconds(15.0));
    OnOffHelper sourceHelper1("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address("10.1.18.2"), 8081));
    sourceHelper1.SetAttribute("DataRate", StringValue("3.20Mbps"));
    sourceHelper1.SetAttribute("PacketSize", UintegerValue(1500));
    sourceHelper1.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
    sourceHelper1.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
    ApplicationContainer sourceApp1 = sourceHelper1.Install(nodeMap["ess-hs-1"]);
    sourceApp1.Start(Seconds(2.0));
    sourceApp1.Stop(Seconds(2.0 + 10));

    // Flow 2: ulm-n25-1 -> stu-eti-1 (2.40Mbps)
    PacketSinkHelper sinkHelper2("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), 8082));
    ApplicationContainer sinkApp2 = sinkHelper2.Install(nodeMap["stu-eti-1"]);
    sinkApp2.Start(Seconds(1.0));
    sinkApp2.Stop(Seconds(15.0));
    OnOffHelper sourceHelper2("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address("10.1.72.1"), 8082));
    sourceHelper2.SetAttribute("DataRate", StringValue("2.40Mbps"));
    sourceHelper2.SetAttribute("PacketSize", UintegerValue(1500));
    sourceHelper2.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
    sourceHelper2.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
    ApplicationContainer sourceApp2 = sourceHelper2.Install(nodeMap["ulm-n25-1"]);
    sourceApp2.Start(Seconds(2.0));
    sourceApp2.Stop(Seconds(2.0 + 10));

    // Flow 3: ulm-n26-1 -> kar-rz-1 (4.00Mbps)
    PacketSinkHelper sinkHelper3("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), 8083));
    ApplicationContainer sinkApp3 = sinkHelper3.Install(nodeMap["kar-rz-1"]);
    sinkApp3.Start(Seconds(1.0));
    sinkApp3.Stop(Seconds(15.0));
    OnOffHelper sourceHelper3("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address("10.1.18.2"), 8083));
    sourceHelper3.SetAttribute("DataRate", StringValue("4.00Mbps"));
    sourceHelper3.SetAttribute("PacketSize", UintegerValue(1500));
    sourceHelper3.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
    sourceHelper3.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
    ApplicationContainer sourceApp3 = sourceHelper3.Install(nodeMap["ulm-n26-1"]);
    sourceApp3.Start(Seconds(2.0));
    sourceApp3.Stop(Seconds(2.0 + 10));

    // Flow 5: kar-rz-1 -> ess-hs-1 (3.20Mbps)
    PacketSinkHelper sinkHelper5("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), 8084));
    ApplicationContainer sinkApp5 = sinkHelper5.Install(nodeMap["ess-hs-1"]);
    sinkApp5.Start(Seconds(1.0));
    sinkApp5.Stop(Seconds(15.0));
    OnOffHelper sourceHelper5("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address("10.1.6.2"), 8084));
    sourceHelper5.SetAttribute("DataRate", StringValue("3.20Mbps"));
    sourceHelper5.SetAttribute("PacketSize", UintegerValue(1500));
    sourceHelper5.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
    sourceHelper5.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
    ApplicationContainer sourceApp5 = sourceHelper5.Install(nodeMap["kar-rz-1"]);
    sourceApp5.Start(Seconds(2.0));
    sourceApp5.Stop(Seconds(2.0 + 10));


    NS_LOG_INFO("--- 7. Running Simulation ---");
    Simulator::Stop(Seconds(20.0));
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done.");
    return 0;
}