#ifndef PACKET_HPP
#define PACKET_HPP

#include <pcap/pcap.h>

namespace yaspr
{
  class Packet {
  public:

  private:
    LinkLayerHeader* llheader_;
    NetworkLayerHeader* nlheader_;
    TransportLayerHeader* tlheader_;
    std::vector<uint8_t> data_;

    void defineLinkLayerProtocol(pcap_t* pkt);
    void defineNetworkLayerProtocol();
    void defineTransportLayerProtocol();
  }
}
#endif
