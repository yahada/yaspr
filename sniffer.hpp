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
  
  private:
    std::string device_;
  };


}

#endif
