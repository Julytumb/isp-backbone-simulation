import yaml

YAML_PATH = "scratch/parser/belwu_1.yaml"
CPP_OUTPUT_PATH = "scratch/belwu-topo/weathermap_generated_topo.cc"

CPP_HEADER = ['#include "ns3/core-module.h"',
    '#include "ns3/network-module.h"',
    '#include "ns3/internet-module.h"',
    '#include "ns3/point-to-point-module.h"',
    '#include "ns3/applications-module.h"',
    '#include "ns3/ipv4-global-routing-helper.h"',
    '',
    '#include <string>',
    '#include <map>',
    '',
    'using namespace ns3;',
    '',
    'NS_LOG_COMPONENT_DEFINE("GeneratedTopology");',
    '',
    'int main(int argc, char* argv[])',
    '{',
    '    NS_LOG_INFO("--- Initializing Helpers & Containers ---");',
    '    std::map<std::string, Ptr<Node>> nodeMap;',
    '    NodeContainer allNodes;',
    '    InternetStackHelper stack;',
    '    PointToPointHelper p2p;',
    '    Ipv4AddressHelper address;',
    ''
    ]

CPP_FOOTER = [
    '',
    '    NS_LOG_INFO("--- Running Simulation ---");',
    '    Simulator::Run();',
    '    Simulator::Destroy();',
    '    NS_LOG_INFO("Done.");',
    '    return 0;',
    '}'
]

with open(YAML_PATH, "r") as f: # r = ich will nur readen und blockiere damit nicht die file
    network_dict = yaml.safe_load(f)

topology = network_dict["topology"]

cpp_code_lines = []
cpp_code_lines.extend(CPP_HEADER)

# --------
# write nodes
# ........
cpp_code_lines.append("    NS_LOG_INFO(\"--- Creating Nodes ---\");")
nodes = topology["nodes"]
nodeList = []
for node in nodes.keys():
    kind = nodes[node]["kind"]
    if "switch" in kind :
        continue
    
    #TODO temp!!
    nodeList.append(node)

    #TODO Kinds einfügen!!

    cpp_code_lines.append(f'    {{')
    cpp_code_lines.append(f'    Ptr<Node> node = CreateObject<Node>();')
    cpp_code_lines.append(f'    nodeMap["{node}"] = node;')
    cpp_code_lines.append(f'    allNodes.Add(node);')
    cpp_code_lines.append(f'    Names::Add("{node}", node);')
    cpp_code_lines.append(f'    }}')

cpp_code_lines.append(f'    NS_LOG_INFO("Created " << allNodes.GetN() << " nodes.");')

cpp_code_lines.append("    NS_LOG_INFO(\"--- Installing Internet Stack Helper ---\");")
cpp_code_lines.append(f'    stack.Install(allNodes);')
# --------
# write links
# ........
links = topology["links"]

#TODO Whats with the latency? 4 ms

cpp_code_lines.append("    NS_LOG_INFO(\"--- Creating Links ---\");")
for i, link in enumerate(links):
    ip_counter = i + 1
    #TODO endpoints -> things behind the node names?? relevant? -- not now, when topology is bigger maybe 3 links to 1 node on different ports
    #relevant later!!
    endpoints_list = link["endpoints"]
    endpoint_string1 = endpoints_list[0]
    endpoint_string2 = endpoints_list[1]
    endpoint1 = endpoint_string1.split(":")[0]
    endpoint2 = endpoint_string2.split(":")[0]

    #TODO temp!!!!
    if endpoint1 not in nodeList or endpoint2 not in nodeList:
        print("WARNING: Endpoint missing in Nodes. Skipped Link!")
        continue

    #TODO capacity not data rate!! evtl anpassen?? bandwith of the link (max. capacitty)
    capacity = link["capacity_mbps"]
    cpp_code_lines.append(f'    p2p.SetDeviceAttribute("DataRate", StringValue("{capacity}Mbps"));')

    subnet_x = (ip_counter // 254) + 1
    subnet_y = (ip_counter % 254) + 1
    subnet = f"10.{subnet_x}.{subnet_y}.0"

    cpp_code_lines.append(f'    {{')
    cpp_code_lines.append(f'    NodeContainer link{ip_counter}(nodeMap["{endpoint1}"], nodeMap["{endpoint2}"]); ')
    cpp_code_lines.append(f'    NetDeviceContainer devices{ip_counter} = p2p.Install(link{ip_counter});')
    cpp_code_lines.append(f'    address.SetBase("{subnet}", "255.255.255.0");')
    cpp_code_lines.append(f'    Ipv4InterfaceContainer interfaces{ip_counter} = address.Assign(devices{ip_counter});')
    cpp_code_lines.append(f'    }}')

cpp_code_lines.extend(CPP_FOOTER)
final_cpp_code = "\n".join(cpp_code_lines)
with open(CPP_OUTPUT_PATH, "w") as f: 
    f.write(final_cpp_code)

print("Topology successfully generated!🕺")