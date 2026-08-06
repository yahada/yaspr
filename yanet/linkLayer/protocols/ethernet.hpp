#ifndef ETHERNET_HPP
#define ETHERNET_HPP

#include "linkLayerHeader.hpp"
#include <array>
#include <cstdint>


namespace yaspr
{
  using ETH_ALEN = 6;

  class Ethernet: public LinkLayerHeader final {
  public:
    Ethernet(const u_char* bytes);
    override void destAddr();
    override void sourceAddr();
  private:
    uint8_t dhost_[ETH_ALEN];
    uint8_t shost_[ETH_ALEN];
    uint16_t ether_type_; };
}

#endif
