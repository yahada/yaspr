#ifndef PACKET_HPP
#ifndef PACKET_HPP
#define PACKET_HPP
namespace yaspr
{
  class Packet {
  public:

  private:
    LinkLayerHeader* llheader_;
    NetworkLayerHeader* nlheader_;
    TransportLayerHeader* tlheader_;
    u_char* data_;

    void defineLinkLayerProtocol();
    void defineNetworkLayerProtocol();
    void defineTransportLayerProtocol();
  }
}
#endif
