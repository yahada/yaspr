#ifndef ETHERNET_HPP
#define ETHERNET_HPP

#include <sys/types.h>
#include <cstdint>
#include <cstddef>
#include "../linkLayerHeader.hpp"
namespace yaspr
{

  class Ethernet final: public LinkLayerHeader {
  public:
    Ethernet(const u_char* bytes, size_t len);
    mac_t destAddr() const noexcept override;
    mac_t sourceAddr() const noexcept override;
    uint16_t netProt() const noexcept override;
    size_t payload() const noexcept override;
  private:
    mac_t dhost_;
    mac_t shost_;
    uint16_t ether_type_;
  };
}

#endif
