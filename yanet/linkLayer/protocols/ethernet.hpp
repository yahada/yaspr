#ifndef ETHERNET_HPP
#define ETHERNET_HPP

#include "../linkLayerHeader.hpp"
#include <array>
#include <cstdint>
#include <iomanip>
#include <cstddef>
#include <iostream>
#include <pcap/pcap.h>
#include <cstring>
namespace yaspr
{

  class Ethernet final: public LinkLayerHeader {
  public:
    Ethernet(const u_char* bytes, size_t len);
    mac_t destAddr() const noexcept override;
    mac_t sourceAddr() const noexcept override;
  private:
    mac_t dhost_;
    mac_t shost_;
    uint16_t ether_type_; 
  };
}

#endif
