#ifndef IPV4_HPP
#define IPV4_HPP
#include "../networkLayerHeader.hpp"
#include <sys/types.h>
#include <vector>
#include <array>
namespace yaspr
{
  class IPv4 final: public NetworkLayerHeader {
  public:
    std::string sourceAddr() const noexcept override;
    std::string destAddr() const noexcept override;

    IPv4(const u_char* bytes, size_t linkLayerPayload);
    uint8_t transportProtocol() const noexcept override;
    std::unordered_map< std::string, std::string > getFields() const noexcept override;
  private:
    uint8_t version_;
    uint8_t ihl_;
    uint8_t differentiatedServices_;

    uint16_t totalLength_;
    uint16_t identification_;

    uint8_t flags_;
    uint16_t fragmentOffset_;
    uint8_t timeToLive_;
    uint8_t protocol_;
    uint16_t checksum_;
    ipv4_t source_;
    ipv4_t dest_;
    std::vector<uint8_t> options_;

    std::string ipv4ToString(ipv4_t addr) const;
  };
}

#endif
