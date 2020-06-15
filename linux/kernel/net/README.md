# Linux Kernel Net

## Schedule

[link](https://www.bilibili.com/video/BV11E41197Yt?from=search&seid=6768077191923617362)

* Introduce to network Framework
* Write a network application
* Network diagnostic tools
* Options and Data I/O
* Socket File System
* Transport Layer(L4) implementation
  	* tcp /udp protocol, algorithm and optimization
  	* Timer
  	* Broadcast and multicast(only for UDP)
* Network Layer(L3) implementation
  	* ipv4/ipv6 protocol, algorithm and Optimization
  	* Input, Output, Route, Forward, Netfilter
  	* Fragment, bigdata, packet, cache, hash
  	* Neighboring
  	* ICMP, ARP, RARP, IGMP protocol, algorithm
   * Dynamic routing protocol
     	* RIP, OSPF, BGP, CIDR
* Link Layer(L2) implementation
  * 802.3 / 802.2 / 802.2-SNAP/Ethernet
  * Bridge, Spanning Tree Protocol, Vlan
* Project
  * Modify kernel code to Simulation big packet
  * High performance for generic NIC



## Net Subsystem

### Objectives

	* OSL and TCP/IP Overview
	* Network Subsystem
	* Client/Server Communication
	* 4 Layer Protocol Implementation
	* High-Performance Network Stacks
	* Kernel configure network
	* How to get help?



### ISO/OSI Reference model

	* Application
	* Presentation
	* Session
	* Transport
	* Network
	* Data link
	* Physical

Application: Protocols for different applications, HTTP, SMTP, FTP,etc

Presentation: Regulating data presentation(formatting, ASN/1)

Session: Handling structured message exchange, multiplexing sessions

Transport: End-to-end functions between applications. Flow control, packet ordering, etc.

Network: Connecting networks. Packet routing/forwarding

Data link: Moving data between to directly connected stations, Flow control error detection, etc. Shared medium: access control. LLC/MAC

Physical: Media types, coding methods, bit sequences vs. physical signals 

## Internet reference model

	* Application (HTTP, SMTP, SSH)
	* Transport (TCP/UDP)
	* Internet (IPv4/v6)
	* Data link (802 x, PPP, SLIP)



### Questions

sk_buff 是在什么时候分配的?