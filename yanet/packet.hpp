#ifndef PACKET_HPP
#define PACKET_HPP

#include <pcap/pcap.h>
#include "linkLayer/linkLayerHeader.hpp"
#include "linkLayer/protocols/ethernet.hpp"
namespace yaspr
{
  class Packet {
  public:
    Packet(pcap_t* descr, const u_char* packet, const pcap_pkthdr* pktinfo);

    void showLinkLayerInfo() const;
  private:
    LinkLayerHeader* llheader_;
    NetworkLayerHeader* nlheader_;
    // TransportLayerHeader* tlheader_;
    // std::vector<uint8_t> data_;

    void defineLinkLayerProtocol(pcap_t* descr, const u_char* packet, const pcap_pkthdr* pktinfo);
    void defineNetworkLayerProtocol();
    // void defineTransportLayerProtocol();
  };
}
#endif
