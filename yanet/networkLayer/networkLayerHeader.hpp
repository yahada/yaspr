#ifndef NETWORK_LAEYER_HEADER_HPP
#define NETWORK_LAEYER_HEADER_HPP
#include <unordered_map>
namespace yaspr
{
  using ipv4_t = std::array<uint8_t, 4>;
  using ipv6_t = std::array<uint16_t, 8>;

  struct NetworkLayerHeader {
    virtual uint8_t transportProtocol() const noexcept = 0;
    virtual std::string sourceAddr() const noexcept = 0;
    virtual std::string destAddr() const noexcept = 0;

    virtual std::unordered_map< std::string, std::string > getFields() const noexcept = 0;
    virtual ~NetworkLayerHeader() = default;
  };
}


#endif
