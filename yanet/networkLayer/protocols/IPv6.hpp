#ifndef IPV6_HPP
#define IPV6_HPP
#include "../networkLayerHeader.hpp"
#include <sys/types.h>
#include <vector>
#include <array>
namespace yaspr
{
  class IPv6 final: public NetworkLayerHeader {
  public:
    std::string sourceAddr() const noexcept override;
    std::string destAddr() const noexcept override;

    IPv6(const u_char* bytes, size_t linkLayerPayload);
    uint8_t transportProtocol() const noexcept override;
    std::unordered_map< std::string, std::string > getFields() const noexcept override;
  private:
    uint8_t version_;
    uint8_t trafficClass_;
    uint32_t flowLabel_;

    uint16_t payloadLength_;
    uint8_t nextHeader_;
    uint8_t hopLimit_;

    ipv6_t source_;
    ipv6_t dest_;

    std::string ipv6ToString(ipv6_t addr) const;
  };
}

#endif