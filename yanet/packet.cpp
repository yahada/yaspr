#include "packet.hpp"
yaspr::Packet::Packet(pcap_t* descr, const u_char* packet, const pcap_pkthdr* pktinfo)
{
  defineLinkLayerProtocol(descr, packet, pktinfo);
}


void yaspr::Packet::defineLinkLayerProtocol(pcap_t* descr, const u_char* packet, const pcap_pkthdr* pktinfo)
{
  int linkLayerProt = pcap_datalink(descr);

  if (linkLayerProt == -1)
  {
    return;
  }
 
  if (linkLayerProt == DLT_EN10MB)
  {
    llheader_ = new Ethernet(packet, pktinfo->len);
    std::cout << "EHTER PACKET\n";
  }

  if (linkLayerProt != DLT_EN10MB)
  {
    std::cout << "other packet\n";
  }
}

void yaspr::Packet::showLinkLayerInfo() const
{
  std::cout << "ll->";
  llheader_->showDestAddr();
  std::cout << "<-";
  llheader_->showSourceAddr();
  std::cout << '\n';
}
