#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv4-global-routing-helper.h"

#include <string>
#include <map>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("GeneratedTopology");

int main(int argc, char* argv[])
{
    NS_LOG_INFO("--- Initializing Helpers & Containers ---");
    std::map<std::string, Ptr<Node>> nodeMap;
    NodeContainer allNodes;
    InternetStackHelper stack;
    PointToPointHelper p2p;
    Ipv4AddressHelper address;

    NS_LOG_INFO("--- Creating Nodes ---");
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["aal-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("aal-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["alb-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("alb-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["bib-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("bib-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["boe-1"] = node;
    allNodes.Add(node);
    Names::Add("boe-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["ess-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("ess-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["fdh-dhbw-1"] = node;
    allNodes.Add(node);
    Names::Add("fdh-dhbw-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["fds-stw-1"] = node;
    allNodes.Add(node);
    Names::Add("fds-stw-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["fra-decix-a99"] = node;
    allNodes.Add(node);
    Names::Add("fra-decix-a99", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["fra-tc-a99"] = node;
    allNodes.Add(node);
    Names::Add("fra-tc-a99", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["frb-kg-1"] = node;
    allNodes.Add(node);
    Names::Add("frb-kg-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["frb-rz-1"] = node;
    allNodes.Add(node);
    Names::Add("frb-rz-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["frb-rz-2"] = node;
    allNodes.Add(node);
    Names::Add("frb-rz-2", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["fuw-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("fuw-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["gei-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("gei-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["goe-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("goe-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["hdh-dhbw-1"] = node;
    allNodes.Add(node);
    Names::Add("hdh-dhbw-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["hdl-city-1"] = node;
    allNodes.Add(node);
    Names::Add("hdl-city-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["hdl-rz-1"] = node;
    allNodes.Add(node);
    Names::Add("hdl-rz-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["hlb-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("hlb-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["hor-dhbw-1"] = node;
    allNodes.Add(node);
    Names::Add("hor-dhbw-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["kar-bib-1"] = node;
    allNodes.Add(node);
    Names::Add("kar-bib-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["kar-nord-1"] = node;
    allNodes.Add(node);
    Names::Add("kar-nord-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["kar-rz-1"] = node;
    allNodes.Add(node);
    Names::Add("kar-rz-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["kar-rz-a99"] = node;
    allNodes.Add(node);
    Names::Add("kar-rz-a99", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["keh-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("keh-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["kon-bib-1"] = node;
    allNodes.Add(node);
    Names::Add("kon-bib-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["kon-rz-1"] = node;
    allNodes.Add(node);
    Names::Add("kon-rz-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["kue-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("kue-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["lbg-ph-1"] = node;
    allNodes.Add(node);
    Names::Add("lbg-ph-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["loe-dhbw-1"] = node;
    allNodes.Add(node);
    Names::Add("loe-dhbw-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["man-rz-1"] = node;
    allNodes.Add(node);
    Names::Add("man-rz-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["man-schl-1"] = node;
    allNodes.Add(node);
    Names::Add("man-schl-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["mar-dla-1"] = node;
    allNodes.Add(node);
    Names::Add("mar-dla-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["mos-dhbw-2"] = node;
    allNodes.Add(node);
    Names::Add("mos-dhbw-2", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["nue-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("nue-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["ofg-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("ofg-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["pfo-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("pfo-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["rav-dhbw-1"] = node;
    allNodes.Add(node);
    Names::Add("rav-dhbw-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["reu-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("reu-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["rot-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("rot-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["sgd-ph-1"] = node;
    allNodes.Add(node);
    Names::Add("sgd-ph-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["shl-hs-2"] = node;
    allNodes.Add(node);
    Names::Add("shl-hs-2", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["sig-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("sig-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["stu-al30-1"] = node;
    allNodes.Add(node);
    Names::Add("stu-al30-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["stu-eti-1"] = node;
    allNodes.Add(node);
    Names::Add("stu-eti-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["stu-eti-a99"] = node;
    allNodes.Add(node);
    Names::Add("stu-eti-a99", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["tro-mh-1"] = node;
    allNodes.Add(node);
    Names::Add("tro-mh-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["tue-mor-1"] = node;
    allNodes.Add(node);
    Names::Add("tue-mor-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["tue-wae-1"] = node;
    allNodes.Add(node);
    Names::Add("tue-wae-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["tut-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("tut-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["ulm-n25-1"] = node;
    allNodes.Add(node);
    Names::Add("ulm-n25-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["ulm-n26-1"] = node;
    allNodes.Add(node);
    Names::Add("ulm-n26-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["vis-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("vis-hs-1", node);
    }
    {
    Ptr<Node> node = CreateObject<Node>();
    nodeMap["wei-hs-1"] = node;
    allNodes.Add(node);
    Names::Add("wei-hs-1", node);
    }
    NS_LOG_INFO("Created " << allNodes.GetN() << " nodes.");
    NS_LOG_INFO("--- Installing Internet Stack Helper ---");
    stack.Install(allNodes);
    NS_LOG_INFO("--- Creating Links ---");
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link1(nodeMap["stu-eti-a99"], nodeMap["ulm-n25-1"]); 
    NetDeviceContainer devices1 = p2p.Install(link1);
    address.SetBase("10.1.2.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces1 = address.Assign(devices1);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link2(nodeMap["ulm-n25-1"], nodeMap["ulm-n26-1"]); 
    NetDeviceContainer devices2 = p2p.Install(link2);
    address.SetBase("10.1.3.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces2 = address.Assign(devices2);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link3(nodeMap["hlb-hs-1"], nodeMap["kue-hs-1"]); 
    NetDeviceContainer devices3 = p2p.Install(link3);
    address.SetBase("10.1.4.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces3 = address.Assign(devices3);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link4(nodeMap["kue-hs-1"], nodeMap["shl-hs-2"]); 
    NetDeviceContainer devices4 = p2p.Install(link4);
    address.SetBase("10.1.5.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces4 = address.Assign(devices4);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link5(nodeMap["stu-eti-a99"], nodeMap["ess-hs-1"]); 
    NetDeviceContainer devices5 = p2p.Install(link5);
    address.SetBase("10.1.6.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces5 = address.Assign(devices5);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link6(nodeMap["stu-al30-1"], nodeMap["pfo-hs-1"]); 
    NetDeviceContainer devices6 = p2p.Install(link6);
    address.SetBase("10.1.7.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces6 = address.Assign(devices6);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link7(nodeMap["kar-bib-1"], nodeMap["pfo-hs-1"]); 
    NetDeviceContainer devices7 = p2p.Install(link7);
    address.SetBase("10.1.8.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces7 = address.Assign(devices7);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link8(nodeMap["kon-rz-1"], nodeMap["fdh-dhbw-1"]); 
    NetDeviceContainer devices8 = p2p.Install(link8);
    address.SetBase("10.1.9.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces8 = address.Assign(devices8);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link9(nodeMap["fdh-dhbw-1"], nodeMap["rav-dhbw-1"]); 
    NetDeviceContainer devices9 = p2p.Install(link9);
    address.SetBase("10.1.10.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces9 = address.Assign(devices9);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link10(nodeMap["wei-hs-1"], nodeMap["rav-dhbw-1"]); 
    NetDeviceContainer devices10 = p2p.Install(link10);
    address.SetBase("10.1.11.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces10 = address.Assign(devices10);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link11(nodeMap["sig-hs-1"], nodeMap["rav-dhbw-1"]); 
    NetDeviceContainer devices11 = p2p.Install(link11);
    address.SetBase("10.1.12.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces11 = address.Assign(devices11);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link12(nodeMap["nue-hs-1"], nodeMap["reu-hs-1"]); 
    NetDeviceContainer devices12 = p2p.Install(link12);
    address.SetBase("10.1.13.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces12 = address.Assign(devices12);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link13(nodeMap["ulm-n26-1"], nodeMap["hdh-dhbw-1"]); 
    NetDeviceContainer devices13 = p2p.Install(link13);
    address.SetBase("10.1.14.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces13 = address.Assign(devices13);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link14(nodeMap["hdh-dhbw-1"], nodeMap["aal-hs-1"]); 
    NetDeviceContainer devices14 = p2p.Install(link14);
    address.SetBase("10.1.15.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces14 = address.Assign(devices14);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link15(nodeMap["reu-hs-1"], nodeMap["tue-wae-1"]); 
    NetDeviceContainer devices15 = p2p.Install(link15);
    address.SetBase("10.1.16.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces15 = address.Assign(devices15);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link16(nodeMap["ess-hs-1"], nodeMap["nue-hs-1"]); 
    NetDeviceContainer devices16 = p2p.Install(link16);
    address.SetBase("10.1.17.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces16 = address.Assign(devices16);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link17(nodeMap["kar-rz-a99"], nodeMap["kar-rz-1"]); 
    NetDeviceContainer devices17 = p2p.Install(link17);
    address.SetBase("10.1.18.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces17 = address.Assign(devices17);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link18(nodeMap["aal-hs-1"], nodeMap["sgd-ph-1"]); 
    NetDeviceContainer devices18 = p2p.Install(link18);
    address.SetBase("10.1.19.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces18 = address.Assign(devices18);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link19(nodeMap["hor-dhbw-1"], nodeMap["fds-stw-1"]); 
    NetDeviceContainer devices19 = p2p.Install(link19);
    address.SetBase("10.1.20.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces19 = address.Assign(devices19);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link20(nodeMap["keh-hs-1"], nodeMap["fds-stw-1"]); 
    NetDeviceContainer devices20 = p2p.Install(link20);
    address.SetBase("10.1.21.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces20 = address.Assign(devices20);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("1000Mbps"));
    {
    NodeContainer link21(nodeMap["kue-hs-1"], nodeMap["shl-hs-2"]); 
    NetDeviceContainer devices21 = p2p.Install(link21);
    address.SetBase("10.1.22.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces21 = address.Assign(devices21);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link22(nodeMap["tro-mh-1"], nodeMap["vis-hs-1"]); 
    NetDeviceContainer devices22 = p2p.Install(link22);
    address.SetBase("10.1.23.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces22 = address.Assign(devices22);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link23(nodeMap["tut-hs-1"], nodeMap["tro-mh-1"]); 
    NetDeviceContainer devices23 = p2p.Install(link23);
    address.SetBase("10.1.24.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces23 = address.Assign(devices23);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link24(nodeMap["tue-wae-1"], nodeMap["tut-hs-1"]); 
    NetDeviceContainer devices24 = p2p.Install(link24);
    address.SetBase("10.1.25.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces24 = address.Assign(devices24);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link25(nodeMap["tut-hs-1"], nodeMap["kon-bib-1"]); 
    NetDeviceContainer devices25 = p2p.Install(link25);
    address.SetBase("10.1.26.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces25 = address.Assign(devices25);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link26(nodeMap["vis-hs-1"], nodeMap["fuw-hs-1"]); 
    NetDeviceContainer devices26 = p2p.Install(link26);
    address.SetBase("10.1.27.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces26 = address.Assign(devices26);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link27(nodeMap["ofg-hs-1"], nodeMap["fuw-hs-1"]); 
    NetDeviceContainer devices27 = p2p.Install(link27);
    address.SetBase("10.1.28.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces27 = address.Assign(devices27);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link28(nodeMap["alb-hs-1"], nodeMap["tue-wae-1"]); 
    NetDeviceContainer devices28 = p2p.Install(link28);
    address.SetBase("10.1.29.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces28 = address.Assign(devices28);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link29(nodeMap["kar-bib-1"], nodeMap["ofg-hs-1"]); 
    NetDeviceContainer devices29 = p2p.Install(link29);
    address.SetBase("10.1.30.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces29 = address.Assign(devices29);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link30(nodeMap["shl-hs-2"], nodeMap["sgd-ph-1"]); 
    NetDeviceContainer devices30 = p2p.Install(link30);
    address.SetBase("10.1.31.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces30 = address.Assign(devices30);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link31(nodeMap["frb-rz-1"], nodeMap["ofg-hs-1"]); 
    NetDeviceContainer devices31 = p2p.Install(link31);
    address.SetBase("10.1.32.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces31 = address.Assign(devices31);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link32(nodeMap["kon-rz-1"], nodeMap["loe-dhbw-1"]); 
    NetDeviceContainer devices32 = p2p.Install(link32);
    address.SetBase("10.1.33.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces32 = address.Assign(devices32);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link33(nodeMap["frb-kg-1"], nodeMap["loe-dhbw-1"]); 
    NetDeviceContainer devices33 = p2p.Install(link33);
    address.SetBase("10.1.34.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces33 = address.Assign(devices33);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link34(nodeMap["kon-rz-1"], nodeMap["rav-dhbw-1"]); 
    NetDeviceContainer devices34 = p2p.Install(link34);
    address.SetBase("10.1.35.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces34 = address.Assign(devices34);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link35(nodeMap["stu-al30-1"], nodeMap["ulm-n26-1"]); 
    NetDeviceContainer devices35 = p2p.Install(link35);
    address.SetBase("10.1.36.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces35 = address.Assign(devices35);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link36(nodeMap["stu-eti-a99"], nodeMap["lbg-ph-1"]); 
    NetDeviceContainer devices36 = p2p.Install(link36);
    address.SetBase("10.1.37.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces36 = address.Assign(devices36);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link37(nodeMap["tue-wae-1"], nodeMap["rot-hs-1"]); 
    NetDeviceContainer devices37 = p2p.Install(link37);
    address.SetBase("10.1.38.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces37 = address.Assign(devices37);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link38(nodeMap["tue-mor-1"], nodeMap["rot-hs-1"]); 
    NetDeviceContainer devices38 = p2p.Install(link38);
    address.SetBase("10.1.39.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces38 = address.Assign(devices38);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link39(nodeMap["stu-eti-a99"], nodeMap["boe-1"]); 
    NetDeviceContainer devices39 = p2p.Install(link39);
    address.SetBase("10.1.40.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces39 = address.Assign(devices39);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link40(nodeMap["hor-dhbw-1"], nodeMap["boe-1"]); 
    NetDeviceContainer devices40 = p2p.Install(link40);
    address.SetBase("10.1.41.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces40 = address.Assign(devices40);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link41(nodeMap["alb-hs-1"], nodeMap["sig-hs-1"]); 
    NetDeviceContainer devices41 = p2p.Install(link41);
    address.SetBase("10.1.42.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces41 = address.Assign(devices41);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link42(nodeMap["stu-eti-a99"], nodeMap["hor-dhbw-1"]); 
    NetDeviceContainer devices42 = p2p.Install(link42);
    address.SetBase("10.1.43.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces42 = address.Assign(devices42);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link43(nodeMap["hor-dhbw-1"], nodeMap["keh-hs-1"]); 
    NetDeviceContainer devices43 = p2p.Install(link43);
    address.SetBase("10.1.44.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces43 = address.Assign(devices43);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link44(nodeMap["ofg-hs-1"], nodeMap["keh-hs-1"]); 
    NetDeviceContainer devices44 = p2p.Install(link44);
    address.SetBase("10.1.45.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces44 = address.Assign(devices44);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link45(nodeMap["kar-rz-1"], nodeMap["kar-bib-1"]); 
    NetDeviceContainer devices45 = p2p.Install(link45);
    address.SetBase("10.1.46.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces45 = address.Assign(devices45);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link46(nodeMap["kar-bib-1"], nodeMap["stu-al30-1"]); 
    NetDeviceContainer devices46 = p2p.Install(link46);
    address.SetBase("10.1.47.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces46 = address.Assign(devices46);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link47(nodeMap["tut-hs-1"], nodeMap["vis-hs-1"]); 
    NetDeviceContainer devices47 = p2p.Install(link47);
    address.SetBase("10.1.48.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces47 = address.Assign(devices47);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link48(nodeMap["kar-rz-a99"], nodeMap["frb-rz-1"]); 
    NetDeviceContainer devices48 = p2p.Install(link48);
    address.SetBase("10.1.49.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces48 = address.Assign(devices48);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link49(nodeMap["lbg-ph-1"], nodeMap["mar-dla-1"]); 
    NetDeviceContainer devices49 = p2p.Install(link49);
    address.SetBase("10.1.50.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces49 = address.Assign(devices49);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link50(nodeMap["hlb-hs-1"], nodeMap["mar-dla-1"]); 
    NetDeviceContainer devices50 = p2p.Install(link50);
    address.SetBase("10.1.51.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces50 = address.Assign(devices50);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link51(nodeMap["stu-eti-a99"], nodeMap["hlb-hs-1"]); 
    NetDeviceContainer devices51 = p2p.Install(link51);
    address.SetBase("10.1.52.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces51 = address.Assign(devices51);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link52(nodeMap["stu-eti-a99"], nodeMap["hlb-hs-1"]); 
    NetDeviceContainer devices52 = p2p.Install(link52);
    address.SetBase("10.1.53.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces52 = address.Assign(devices52);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link53(nodeMap["ulm-n26-1"], nodeMap["bib-hs-1"]); 
    NetDeviceContainer devices53 = p2p.Install(link53);
    address.SetBase("10.1.54.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces53 = address.Assign(devices53);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link54(nodeMap["ulm-n25-1"], nodeMap["gei-hs-1"]); 
    NetDeviceContainer devices54 = p2p.Install(link54);
    address.SetBase("10.1.55.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces54 = address.Assign(devices54);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link55(nodeMap["hlb-hs-1"], nodeMap["lbg-ph-1"]); 
    NetDeviceContainer devices55 = p2p.Install(link55);
    address.SetBase("10.1.56.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces55 = address.Assign(devices55);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link56(nodeMap["aal-hs-1"], nodeMap["shl-hs-2"]); 
    NetDeviceContainer devices56 = p2p.Install(link56);
    address.SetBase("10.1.57.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces56 = address.Assign(devices56);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link57(nodeMap["goe-hs-1"], nodeMap["gei-hs-1"]); 
    NetDeviceContainer devices57 = p2p.Install(link57);
    address.SetBase("10.1.58.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces57 = address.Assign(devices57);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link58(nodeMap["ess-hs-1"], nodeMap["goe-hs-1"]); 
    NetDeviceContainer devices58 = p2p.Install(link58);
    address.SetBase("10.1.59.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces58 = address.Assign(devices58);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link59(nodeMap["stu-eti-a99"], nodeMap["kar-rz-a99"]); 
    NetDeviceContainer devices59 = p2p.Install(link59);
    address.SetBase("10.1.60.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces59 = address.Assign(devices59);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link60(nodeMap["wei-hs-1"], nodeMap["bib-hs-1"]); 
    NetDeviceContainer devices60 = p2p.Install(link60);
    address.SetBase("10.1.61.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces60 = address.Assign(devices60);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link61(nodeMap["hdl-rz-1"], nodeMap["hdl-city-1"]); 
    NetDeviceContainer devices61 = p2p.Install(link61);
    address.SetBase("10.1.62.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces61 = address.Assign(devices61);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link62(nodeMap["hdl-city-1"], nodeMap["mos-dhbw-2"]); 
    NetDeviceContainer devices62 = p2p.Install(link62);
    address.SetBase("10.1.63.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces62 = address.Assign(devices62);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link63(nodeMap["hlb-hs-1"], nodeMap["mos-dhbw-2"]); 
    NetDeviceContainer devices63 = p2p.Install(link63);
    address.SetBase("10.1.64.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces63 = address.Assign(devices63);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link64(nodeMap["stu-eti-a99"], nodeMap["fra-decix-a99"]); 
    NetDeviceContainer devices64 = p2p.Install(link64);
    address.SetBase("10.1.65.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces64 = address.Assign(devices64);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link65(nodeMap["kar-rz-a99"], nodeMap["fra-tc-a99"]); 
    NetDeviceContainer devices65 = p2p.Install(link65);
    address.SetBase("10.1.66.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces65 = address.Assign(devices65);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link66(nodeMap["kar-rz-a99"], nodeMap["stu-eti-a99"]); 
    NetDeviceContainer devices66 = p2p.Install(link66);
    address.SetBase("10.1.67.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces66 = address.Assign(devices66);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link67(nodeMap["kar-rz-a99"], nodeMap["kar-nord-1"]); 
    NetDeviceContainer devices67 = p2p.Install(link67);
    address.SetBase("10.1.68.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces67 = address.Assign(devices67);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link68(nodeMap["man-schl-1"], nodeMap["kar-nord-1"]); 
    NetDeviceContainer devices68 = p2p.Install(link68);
    address.SetBase("10.1.69.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces68 = address.Assign(devices68);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link69(nodeMap["stu-eti-1"], nodeMap["stu-al30-1"]); 
    NetDeviceContainer devices69 = p2p.Install(link69);
    address.SetBase("10.1.70.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces69 = address.Assign(devices69);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link70(nodeMap["frb-rz-1"], nodeMap["frb-rz-2"]); 
    NetDeviceContainer devices70 = p2p.Install(link70);
    address.SetBase("10.1.71.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces70 = address.Assign(devices70);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link71(nodeMap["frb-rz-1"], nodeMap["frb-rz-2"]); 
    NetDeviceContainer devices71 = p2p.Install(link71);
    address.SetBase("10.1.72.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces71 = address.Assign(devices71);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("10000Mbps"));
    {
    NodeContainer link72(nodeMap["frb-kg-1"], nodeMap["frb-rz-2"]); 
    NetDeviceContainer devices72 = p2p.Install(link72);
    address.SetBase("10.1.73.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces72 = address.Assign(devices72);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link73(nodeMap["fra-tc-a99"], nodeMap["fra-decix-a99"]); 
    NetDeviceContainer devices73 = p2p.Install(link73);
    address.SetBase("10.1.74.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces73 = address.Assign(devices73);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link74(nodeMap["stu-eti-a99"], nodeMap["fra-decix-a99"]); 
    NetDeviceContainer devices74 = p2p.Install(link74);
    address.SetBase("10.1.75.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces74 = address.Assign(devices74);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link75(nodeMap["stu-eti-1"], nodeMap["stu-eti-a99"]); 
    NetDeviceContainer devices75 = p2p.Install(link75);
    address.SetBase("10.1.76.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces75 = address.Assign(devices75);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link76(nodeMap["fra-decix-a99"], nodeMap["fra-tc-a99"]); 
    NetDeviceContainer devices76 = p2p.Install(link76);
    address.SetBase("10.1.77.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces76 = address.Assign(devices76);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link77(nodeMap["kar-rz-a99"], nodeMap["fra-tc-a99"]); 
    NetDeviceContainer devices77 = p2p.Install(link77);
    address.SetBase("10.1.78.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces77 = address.Assign(devices77);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link78(nodeMap["stu-eti-a99"], nodeMap["tue-mor-1"]); 
    NetDeviceContainer devices78 = p2p.Install(link78);
    address.SetBase("10.1.79.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces78 = address.Assign(devices78);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link79(nodeMap["tue-mor-1"], nodeMap["tue-wae-1"]); 
    NetDeviceContainer devices79 = p2p.Install(link79);
    address.SetBase("10.1.80.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces79 = address.Assign(devices79);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link80(nodeMap["tue-wae-1"], nodeMap["kon-bib-1"]); 
    NetDeviceContainer devices80 = p2p.Install(link80);
    address.SetBase("10.1.81.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces80 = address.Assign(devices80);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link81(nodeMap["kon-bib-1"], nodeMap["kon-rz-1"]); 
    NetDeviceContainer devices81 = p2p.Install(link81);
    address.SetBase("10.1.82.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces81 = address.Assign(devices81);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link82(nodeMap["kon-rz-1"], nodeMap["frb-kg-1"]); 
    NetDeviceContainer devices82 = p2p.Install(link82);
    address.SetBase("10.1.83.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces82 = address.Assign(devices82);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link83(nodeMap["frb-kg-1"], nodeMap["frb-rz-1"]); 
    NetDeviceContainer devices83 = p2p.Install(link83);
    address.SetBase("10.1.84.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces83 = address.Assign(devices83);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link84(nodeMap["kar-rz-a99"], nodeMap["man-schl-1"]); 
    NetDeviceContainer devices84 = p2p.Install(link84);
    address.SetBase("10.1.85.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces84 = address.Assign(devices84);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link85(nodeMap["man-schl-1"], nodeMap["man-rz-1"]); 
    NetDeviceContainer devices85 = p2p.Install(link85);
    address.SetBase("10.1.86.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces85 = address.Assign(devices85);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link86(nodeMap["man-rz-1"], nodeMap["hdl-rz-1"]); 
    NetDeviceContainer devices86 = p2p.Install(link86);
    address.SetBase("10.1.87.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces86 = address.Assign(devices86);
    }
    p2p.SetDeviceAttribute("DataRate", StringValue("100000Mbps"));
    {
    NodeContainer link87(nodeMap["hdl-rz-1"], nodeMap["fra-decix-a99"]); 
    NetDeviceContainer devices87 = p2p.Install(link87);
    address.SetBase("10.1.88.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces87 = address.Assign(devices87);
    }

    NS_LOG_INFO("--- Running Simulation ---");
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done.");
    printf("Run successful!");
    return 0;
}