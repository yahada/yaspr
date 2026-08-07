#ifndef ETHERNET_HPP
#define ETHERNET_HPP

#include "linkLayerHeader.hpp"
#include <array>
#include <cstdint>
#include <cstddef>

namespace yaspr
{
  constexpr size_t ETH_ALEN = 6;
  using mac_t = std::array<uint8_t, ETH_ALEN>;
  class Ethernet: public LinkLayerHeader final {
  public:
    Ethernet(const uint8_t* bytes, size_t len);
    override mac_t destAddr() const noexcept;
    override mac_t sourceAddr() const noexcept;
    
  private:
    mac_t dhost_;
    mac_t shost_;
    uint16_t ether_type_; 
  };
}

#endif
