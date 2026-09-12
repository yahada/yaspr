#ifndef PACKET_HPP
#define PACKET_HPP

#include <pcap/pcap.h>
#include "linkLayer/linkLayerHeader.hpp"
#include "linkLayer/protocols/ethernet.hpp"
#include "networkLayer/networkLayerHeader.hpp"
#include "networkLayer/protocols/IPv4.hpp"
namespace yaspr
{

  constexpr uint16_t ETHERTYPE_IPV4 = 0x0800;
  constexpr uint16_t ETHERTYPE_IPV6 = 0x86DD;
  constexpr uint16_t ETHERTYPE_ARP = 0x0806;

  class Packet {
  public:
    Packet(pcap_t* descr, const u_char* packet, const pcap_pkthdr* pktinfo);

    void showLinkLayerInfo() const;
    void showNetworkLayerShortInfo() const;
    void showNetworkLayerFullInfo() const;
  private:
    LinkLayerHeader* llheader_;
    NetworkLayerHeader* nlheader_;
    // TransportLayerHeader* tlheader_;
    // std::vector<uint8_t> data_;

    void defineLinkLayerProtocol(pcap_t* descr, const u_char* packet, const pcap_pkthdr* pktinfo);
    void defineNetworkLayerProtocol(const u_char* packet, size_t LinkLayerPayload);
    // void defineTransportLayerProtocol();
  };
}
#endif
