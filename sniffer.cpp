#include "sniffer.hpp"
#include <assert.h>
#include <stdio.h>
#include <iostream>
std::vector< std::string > yaspr::Sniffer::getAllDevs() const
{
  pcap_if_t* allDevs = nullptr;
  char errbuf[PCAP_ERRBUF_SIZE];

  std::vector< std::string > devs = {};

  if (pcap_findalldevs(&allDevs, errbuf) == -1)
  {
    std::cerr << "FIND ALL DEVS ERROR: " << errbuf << '\n'; // TODO: rewrite error text
    return devs;
  }

  for (pcap_if_t* i = allDevs; i != nullptr; i = i->next)
  {
   devs.emplace_back (i->name);
  }

  pcap_freealldevs(allDevs);
  return devs;
}


void yaspr::Sniffer::chooseDev(const std::string& devName)
{
  device_ = devName;
}

void yaspr::Sniffer::dropDev()
{
  device_.clear();
}

std::string yaspr::Sniffer::getDev() const
{
  return device_;
}


void packet_callback(u_char* user, const pcap_pkthdr* h, const u_char* packet)
{
//  static size_t packetNum = 0;
//  std::cout << packetNum++ << ":\n";
//  size_t count = 0;
//  for (size_t i = 0; i < h->len; ++i, ++count)
//  {
//    if (count % 10 == 0 && i != 0)
//    {
//      std::cout << '\n';
//    }
//    else if (i != 0 )
//    {
//      std::cout << ' ';
//    }
//
//
//    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(packet[i]);
//  }
//  std::cout << '\n';

//  std::cout << "i\n";
  auto* sniffer = reinterpret_cast<yaspr::Sniffer*> (user);
  yaspr::Packet pkt = sniffer->packetTranscript(h, packet);
  pkt.showLinkLayerInfo();
  pkt.showNetworkLayerShortInfo();
  std::cout << "------------------------\n";

}


void yaspr::Sniffer::startSniffing()
{
  assert(!device_.empty());

  char errbuf[PCAP_ERRBUF_SIZE];
  descr_ = pcap_open_live(device_.c_str(), BUFSIZ, 1, 10, errbuf);

 // std::cout << errbuf << '\n';
  pcap_loop(descr_, -1, packet_callback, reinterpret_cast<u_char*>(this));

}

yaspr::Packet yaspr::Sniffer::packetTranscript(const pcap_pkthdr* h, const u_char* packet)
{
  yaspr::Packet pkt(descr_, packet, h);
  return pkt;
}

