import yaml
import os
import sys
import pandas as pd
import networkx as nx

# --- Konfiguration ---
BASE_PATH = "sources/"
ROUTERS_PATH = os.path.join(BASE_PATH, "routers.csv")
LINKS_PATH = os.path.join(BASE_PATH, "links.csv")
ROUTES_CSV_PATH = os.path.join(BASE_PATH, "routes.csv")
TRAFFIC_CSV_PATH = os.path.join(BASE_PATH, "traffic.csv")
CPP_OUTPUT_PATH = os.path.join(BASE_PATH, "generated_belwu_topo_v2.cc")

print(f"Lese Routers-CSV von: {ROUTERS_PATH}")
print(f"Lese Links-CSV von: {LINKS_PATH}")
print(f"Lese Routes-CSV von: {ROUTES_CSV_PATH}")
print(f"Lese Traffic-CSV von: {TRAFFIC_CSV_PATH}")

# --- C++ Boilerplate (Textbausteine) ---
CPP_HEADER = [
    '#include "ns3/core-module.h"',
    '#include "ns3/network-module.h"',
    '#include "ns3/internet-module.h"',
    '#include "ns3/point-to-point-module.h"',
    '#include "ns3/applications-module.h"',
    '#include "ns3/ipv4-static-routing-helper.h"',
    '#include "ns3/packet-sink.h"',
    '#include <string>',
    '#include <map>',

    '#include <cstdint>',  # Definiert uint32_t
    '#include <utility>',  # Definiert std::pair und std::make_pair
    '',
    'using namespace ns3;',
    'NS_LOG_COMPONENT_DEFINE("GeneratedBelwuTopology");',
    '',
    'int main(int argc, char* argv[])',
    '{',
    '    NS_LOG_INFO("--- 1. Initializing Helpers & Containers ---");',
    '    std::map<std::string, Ptr<Node>> nodeMap;',
    '    std::map<std::string, std::string> nodeKindMap;',
    
    # <--- NEU: Diese C++ Map speichert unsere Port-Namen für das Logging ---
    '    std::map<std::pair<std::string, uint32_t>, std::string> nodeIfaceToNameMap;',
    
    '    NodeContainer allNodes;',
    '    InternetStackHelper stack;',
    '    PointToPointHelper p2p;',
    '    Ipv4AddressHelper address;',
    '    Ipv4StaticRoutingHelper staticRoutingHelper;',
    ''
]

# (Footer with logging)
CPP_FOOTER = [
    '',
    '    // Enable logging for the applications actually used in this simulation      most important',
    '    ns3::LogComponentEnable("OnOffApplication", ns3::LOG_LEVEL_INFO);',
    '    ns3::LogComponentEnable("PacketSink", ns3::LOG_LEVEL_INFO);',
    '',
    '',
    '',
    '    // IPv4 protocol logs (shows packet forwarding, routing decisions)',
    '    ns3::LogComponentEnable("Ipv4L3Protocol", ns3::LOG_LEVEL_INFO);',
    '',
    '    // UDP protocol logs (shows UDP packet processing)',
    '    ns3::LogComponentEnable("UdpL4Protocol", ns3::LOG_LEVEL_INFO);',
    '',
    '    // If you have TCP flows instead/additionally:',
    '    ns3::LogComponentEnable("TcpL4Protocol", ns3::LOG_LEVEL_INFO);',
    '    ns3::LogComponentEnable("TcpSocketBase", ns3::LOG_LEVEL_INFO);',
    '',
    '    NS_LOG_INFO("--- 7. Running Simulation ---");',
    '    Simulator::Stop(Seconds(20.0));',
    '    Simulator::Run();',
    '    Simulator::Destroy();',
    '    NS_LOG_INFO("Done.");',
    '    return 0;',
    '}'
]

# --- 1. Alle Dateien laden ---
#with open(YAML_PATH, "r") as f:
#    network_dict = yaml.safe_load(f)
df_routers = pd.read_csv(ROUTERS_PATH)
df_links = pd.read_csv(LINKS_PATH)
df_routes = pd.read_csv(ROUTES_CSV_PATH)
df_traffic = pd.read_csv(TRAFFIC_CSV_PATH)


#topology = network_dict["topology"]
#links = topology["links"]
#nodes_from_yaml = topology.get("nodes", {})

cpp_code_lines = []
cpp_code_lines.extend(CPP_HEADER)

# --- 2. 'kind'-Map generieren (wie gehabt) ---
# ... (keine Änderungen hier, Code weggelassen) ...
cpp_code_lines.append("    NS_LOG_INFO(\"--- 1. Creating Nodes ---\");")
for index, row in df_routers.iterrows():
    node_name = row['node']
    #kind = row.get("kind")

    #if "switch" in kind:
        #continue
    #cpp_code_lines.append(f'    nodeKindMap["{node_name}"] = "{kind}";')
#cpp_code_lines.append("")

    cpp_code_lines.append(f'    {{')
    cpp_code_lines.append(f'    Ptr<Node> node = CreateObject<Node>();')
    cpp_code_lines.append(f'    nodeMap["{node_name}"] = node;')
    cpp_code_lines.append(f'    allNodes.Add(node);')
    cpp_code_lines.append(f'    Names::Add("{node_name}", node);')
    cpp_code_lines.append(f'    }}')

    cpp_code_lines.append(f'    NS_LOG_INFO("Created " << allNodes.GetN() << " nodes.");')

cpp_code_lines.append("    NS_LOG_INFO(\"--- Installing Internet Stack Helper ---\");")
cpp_code_lines.append(f'    stack.Install(allNodes);')


# --- 4. Links generieren & Maps für Routing erstellen ---
cpp_code_lines.append("    NS_LOG_INFO(\"--- 2. Creating Links & Predicting IPs ---\");")

# Python-Dictionaries, die wir füllen, um das Routing zu berechnen
node_ip_map = {}       # Key: node_name -> Value: primary_ip (für Ziel-IP)
next_hop_ip_map = {}   # Key: (node_a, node_b) -> Value: ip_of_b (für next_hop IP)
routing_iface_map = {} # <--- NEU: Key: (node_a, node_b) -> Value: cxx_variable_name_of_iface_index

for index, row in df_links.iterrows():
    link_num = index + 1
    
    # --- NEU: Port-Namen parsen ---
    # endpoint_a_full = "stu-al30-1:TenGigE0/0/0/16"
    node_a = row["a_node"]
    node_b = row["b_node"]
    
    capacity = row["capacity_mbps"] / 1000

    interface_a = row["a_iface"]
    interface_b = row ["b_iface"]

    for i in range(len(interface_a)):
        if interface_a[i] in ["0","1","2","3","4","5","6","7","8","9"]:
            port_a = interface_a[i:]
            break
    for i in range(len(interface_b)):
        if interface_b[i] in ["0","1","2","3","4","5","6","7","8","9"]:
            port_b = interface_b[i:]
            break
    
    # IP-Adressen vorhersagen (wie gehabt)
    subnet_x = (link_num // 254) + 1
    subnet_y = (link_num % 254) + 1
    subnet = f"10.{subnet_x}.{subnet_y}.0"
    ip_a = f"10.{subnet_x}.{subnet_y}.1"
    ip_b = f"10.{subnet_x}.{subnet_y}.2"

    # --- IP/Routing-Vorhersage-Logik ---
    next_hop_ip_map[(node_a, node_b)] = ip_b
    next_hop_ip_map[(node_b, node_a)] = ip_a
    
    if node_a not in node_ip_map: node_ip_map[node_a] = ip_a
    if node_b not in node_ip_map: node_ip_map[node_b] = ip_b
    
    # --- C++ Code-Generierung (mit Interface-Index) ---
    link_var = f"link{link_num}"
    devices_var = f"devices{link_num}"
    interfaces_var = f"interfaces{link_num}"
    
    cpp_code_lines.append(f'    // Link {link_num}: {node_a}({port_a}) <--> {node_b}({port_b})') # <--- NEU: Mit Port-Namen
    cpp_code_lines.append(f'    p2p.SetDeviceAttribute("DataRate", StringValue("{capacity}"));')
    cpp_code_lines.append(f'    p2p.SetChannelAttribute("Delay", StringValue("1ms"));')
    cpp_code_lines.append(f'    NodeContainer {link_var}(nodeMap["{node_a}"], nodeMap["{node_b}"]);')
    cpp_code_lines.append(f'    NetDeviceContainer {devices_var} = p2p.Install({link_var});')
    cpp_code_lines.append(f'    address.SetBase("{subnet}", "255.255.255.0");')
    cpp_code_lines.append(f'    Ipv4InterfaceContainer {interfaces_var} = address.Assign({devices_var});')

    # --- NEU: Den Interface-Index in einer C++ Variable speichern ---
    iface_a_idx_var = f"iface{link_num}a_idx" # z.B. iface1a_idx
    iface_b_idx_var = f"iface{link_num}b_idx" # z.B. iface1b_idx
    
    # interfaces_var.Get(0) ist der Port auf node_a. .GetInterface() holt seinen Index.
    cpp_code_lines.append(f'    uint32_t {iface_a_idx_var} = {interfaces_var}.Get(0).second;')
    cpp_code_lines.append(f'    uint32_t {iface_b_idx_var} = {interfaces_var}.Get(1).second;')
    
    # --- NEU: Die C++ Metadaten-Map füllen (für dein Logging) ---
    cpp_code_lines.append(f'    nodeIfaceToNameMap[std::make_pair("{node_a}", {iface_a_idx_var})] = "{port_a}";')
    cpp_code_lines.append(f'    nodeIfaceToNameMap[std::make_pair("{node_b}", {iface_b_idx_var})] = "{port_b}";')
    cpp_code_lines.append(f'') # Leerzeile
    
    # --- NEU: Python-Map für Routing-Logik füllen ---
    # Um von A nach B zu kommen, nutze das *lokale* Interface auf A
    routing_iface_map[(node_a, node_b)] = iface_a_idx_var # Speichert den C++ *Variablennamen*
    # Um von B nach A zu kommen, nutze das *lokale* Interface auf B
    routing_iface_map[(node_b, node_a)] = iface_b_idx_var # Speichert den C++ *Variablennamen*


# --- 5. Dijkstra-Graph aus physischen Links bauen ---
G = nx.DiGraph()

# Erstelle ein Dictionary für Routengewichte aus routes.csv
route_weights = {}
for row in df_routes.itertuples():
    route_weights[(row.srcrouter, row.nexthop)] = row.weight

# Baue Graph aus physischen Links der YAML-Topologie
for link in df_links:
    endpoint_a_full = link["endpoints"][0]
    endpoint_b_full = link["endpoints"][1]
    node_a = endpoint_a_full.split(":")[0]
    node_b = endpoint_b_full.split(":")[0]

    # Verwende Gewicht aus routes.csv falls vorhanden, sonst Default 10
    weight = route_weights.get((node_a, node_b), 10)
    G.add_edge(node_a, node_b, weight=weight)

    # Bidirektionale Gewichte
    weight_reverse = route_weights.get((node_b, node_a), 10)
    G.add_edge(node_b, node_a, weight=weight_reverse)

print("Dijkstra-Graph aus physischen YAML-Links erstellt.")

# --- 6. Traffic & Statisches Routing generieren ---
cpp_code_lines.append("    NS_LOG_INFO(\"--- 4. Calculating Routes & Adding Traffic ---\");")
cpp_routing_lines = []
cpp_traffic_lines = []
sink_port = 8080

for i, flow in enumerate(df_traffic.itertuples()):
    source = flow.SrcRouter
    dest = flow.DestRouter
    rate_mbps = (flow.Amount * 8) / (flow.Duration * 1000000.0)
    rate_str = f"{rate_mbps:.2f}Mbps"

    if dest not in node_ip_map or source not in node_ip_map:
        print(f"WARNUNG: Flow {i} ({source} -> {dest}) übersprungen. Knoten nicht in YAML-Links gefunden.")
        continue
    dest_ip = node_ip_map[dest]

    # --- 6a. Dijkstra-Pfadberechnung ---
    try:
        path = nx.shortest_path(G, source=source, target=dest, weight='weight')
        print(f"Flow {i}: {source} -> {dest}. Pfad: {' -> '.join(path)}")
    except nx.NetworkXNoPath:
        print(f"WARNUNG: Kein Pfad von {source} nach {dest} gefunden!")
        continue
        
    # --- 6b. Statische Routen generieren (JETZT KORREKT) ---
    for node_index in range(len(path) - 1):
        current_node_name = path[node_index]
        next_hop_node_name = path[node_index + 1]
        
        # Finde die 'Gateway' IP (wie gehabt)
        if (current_node_name, next_hop_node_name) not in next_hop_ip_map:
            print(f"FEHLER: Kann 'next_hop_ip' für Link {current_node_name} -> {next_hop_node_name} nicht finden!")
            continue
        next_hop_ip = next_hop_ip_map[(current_node_name, next_hop_node_name)]
        
        # --- GEÄNDERT: Finde den KORREKTEN Interface-Index ---
        if (current_node_name, next_hop_node_name) not in routing_iface_map:
            print(f"FEHLER: Kann 'iface_index' für Link {current_node_name} -> {next_hop_node_name} nicht finden!")
            continue
        # Holt den C++ *Variablennamen* (z.B. "iface1a_idx")
        iface_index_var_name = routing_iface_map[(current_node_name, next_hop_node_name)]
        
        # Generiere C++ Code für die statische Route
        route_line = (
            f'    Ptr<Ipv4StaticRouting> staticRouting{i}_{node_index} = ' # Eindeutiger Variablenname
            f'staticRoutingHelper.GetStaticRouting(nodeMap["{current_node_name}"]->GetObject<Ipv4>());'
        )
        cpp_routing_lines.append(route_line)
        
        # Route: Zum Ziel 'dest_ip' über 'next_hop_ip', nutze das lokale Interface 'iface_index_var_name'
        cpp_routing_lines.append(
            f'    staticRouting{i}_{node_index}->AddHostRouteTo(Ipv4Address("{dest_ip}"), '
            f'Ipv4Address("{next_hop_ip}"), {iface_index_var_name});' # <--- GEÄNDERT: (Nicht mehr '1')
        )

    # --- 6c. Traffic-Applikationen generieren (wie gehabt) ---
    # ... (keine Änderungen hier, Code weggelassen) ...
    cpp_traffic_lines.append(f'    // Flow {i}: {source} -> {dest} ({rate_str})')
    cpp_traffic_lines.append(f'    PacketSinkHelper sinkHelper{i}("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), {sink_port}));')
    cpp_traffic_lines.append(f'    ApplicationContainer sinkApp{i} = sinkHelper{i}.Install(nodeMap["{dest}"]);')
    cpp_traffic_lines.append(f'    sinkApp{i}.Start(Seconds(1.0));')
    cpp_traffic_lines.append(f'    sinkApp{i}.Stop(Seconds(15.0));')
    cpp_traffic_lines.append(f'    OnOffHelper sourceHelper{i}("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address("{dest_ip}"), {sink_port}));')
    cpp_traffic_lines.append(f'    sourceHelper{i}.SetAttribute("DataRate", StringValue("{rate_str}"));')
    cpp_traffic_lines.append(f'    sourceHelper{i}.SetAttribute("PacketSize", UintegerValue(1500));')
    cpp_traffic_lines.append(f'    sourceHelper{i}.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));')
    cpp_traffic_lines.append(f'    sourceHelper{i}.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));')
    cpp_traffic_lines.append(f'    ApplicationContainer sourceApp{i} = sourceHelper{i}.Install(nodeMap["{source}"]);')
    cpp_traffic_lines.append(f'    sourceApp{i}.Start(Seconds(2.0));') 
    cpp_traffic_lines.append(f'    sourceApp{i}.Stop(Seconds(2.0 + {flow.Duration}));')
    cpp_traffic_lines.append('')
    sink_port += 1

# --- 7. C++ Code zusammensetzen (wie gehabt) ---
cpp_code_lines.append("    NS_LOG_INFO(\"--- 5. Installing Static Routes ---\");")
cpp_code_lines.extend(cpp_routing_lines)
cpp_code_lines.append("")
cpp_code_lines.append("    NS_LOG_INFO(\"--- 6. Installing Traffic Applications ---\");")
cpp_code_lines.extend(cpp_traffic_lines)

cpp_code_lines.extend(CPP_FOOTER)

# --- 8. Finale C++ Datei schreiben (wie gehabt) ---
final_cpp_code = "\n".join(cpp_code_lines)
with open(CPP_OUTPUT_PATH, "w") as f:
    f.write(final_cpp_code)

print(f"---")
print(f"Erfolg! C++-Datei wurde generiert: {CPP_OUTPUT_PATH}")
print(f"Nächste Schritte:")
print(f"1. Kompilieren:   ./ns3 build")
print(f"2. Ausführen:     ./ns3 run {BASE_PATH}/generated_belwu_topo")