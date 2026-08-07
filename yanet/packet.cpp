#include "packet.hpp"

void Packet::defineLinkLayerProtocol(pcap_t* pkt)
{
  int linkLayerProt = pcap_datalink(pkt);

  if (linkLayerProt == -1)
  {
    return;
  }


}
