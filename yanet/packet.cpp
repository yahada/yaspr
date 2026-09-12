#include "packet.hpp"
#include <iostream>
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
      llheader_ = nullptr;
      break;
  }
}

void yaspr::Packet::showLinkLayerInfo() const
{
  if (!llheader_)
  {
    std::cout << "unsupported protocol\n";
    return;
  }
#if 0
  std::cout << llheader_->destAddr() << "<-" << llheader_->sourceAddr() << '\n';
#endif
  std::cout << "next layer protocol: " <<  llheader_->netProt() << '\n';
}


void yaspr::Packet::defineNetworkLayerProtocol(const u_char* packet, size_t LinkLayerPayload)
{
  uint16_t NetworkLayerProt = llheader_->netProt();

  switch (NetworkLayerProt)
  {
  case(ETHERTYPE_IPV4):
    nlheader_ = new IPv4(packet, LinkLayerPayload);
    break;
  default:
    nlheader_ = nullptr;
        break;
  }

}


