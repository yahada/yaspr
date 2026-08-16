#ifndef SNIFFER_HPP
#define SNIFFER_HPP


#include <pcap/pcap.h>
#include <sys/types.h>
#include <vector>
#include <string>


#include "yanet/packet.hpp"

namespace yaspr
{
  class Sniffer {
  public:
    std::vector< std::string > getAllDevs() const;
    void chooseDev(const std::string& devName);
    void dropDev();
    std::string getDev() const;
    
    void startSniffing();
    Packet packetTranscript(const pcap_pkthdr* h, const u_char* packet);
    void stopSniffing();
  private:
    std::string device_;
    pcap_t* descr_;

  };


}

#endif
