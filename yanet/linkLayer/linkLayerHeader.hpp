#ifndef LINK_LAYER_HEADER_HPP
#define LINK_LAYER_HEADER_HPP
#include <cstddef>
#include <array>
#include <cstdint>
namespace yaspr
{
  constexpr size_t ETH_ALEN = 6;
  using mac_t = std::array<uint8_t, ETH_ALEN>;
  

  class LinkLayerHeader {
  public:
    virtual mac_t destAddr() const noexcept = 0;
    virtual mac_t sourceAddr() const noexcept = 0;
    virtual void showDestAddr() const noexcept = 0;
    virtual void showSourceAddr() const noexcept = 0;
    // virtual void getPayload() = 0;
    virtual ~LinkLayerHeader() = default;
  };
}


#endif
