#include "packet.hpp"
yaspr::Packet::Packet(pcap_t* descr, const u_char* packet, const pcap_pkthdr* pktinfo)
{
  defineLinkLayerProtocol(descr, packet, pktinfo);
}


void yaspr::Packet::defineLinkLayerProtocol(pcap_t* descr, const u_char* packet, const pcap_pkthdr* pktinfo)
{
  int linkLayerProt = pcap_datalink(descr);
  switch (linkLayerProt)
  {
    case -1:
      return;

    case 1:
      std::cout << "ethernet: ";
      llheader_ = new Ethernet(packet, pktinfo->len);
      break;
    
    default:
      std::cout << "yet unknown prot: " << linkLayerProt << '\n';
  }
}

void yaspr::Packet::showLinkLayerInfo() const
{
  std::cout << llheader_->destAddr() << "<-" << llheader_->sourceAddr() << '\n';
}
