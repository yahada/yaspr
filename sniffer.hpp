#ifndef SNIFFER_HPP
#define SNIFFER_HPP


#include <vector>
#include <pcap/pcap.h>
#include <string>

namespace yaspr
{
  class Sniffer {
  public:
    std::vector< std::string > getAllDevs() const;
    void chooseDev(const std::string& devName);
    void dropDev();
    std::string getDev() const;
    
    void startSniffing();
    Packet packetTranscript(const u_char* bytes);
    void stopSniffing();
  private:
    std::string device_;
    pcap_t* descr_;

  };


}

#endif
