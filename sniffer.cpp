#include "sniffer.hpp"
#include <iostream>
std::vector< std::string > yaspr::Sniffer::getAllDevs() const
{
  pcap_if_t* allDevs = nullptr;
  char errBuf[PCAP_ERRBUF_SIZE];
  
  std::vector< std::string > devs = {};

  if (pcap_findalldevs(&allDevs, errBuf) == -1)
  {
    std::cerr << "FIND ALL DEVS ERROR: " << errBuf << '\n'; // TODO: rewrite error text
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
