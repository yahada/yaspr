#include "IPv4.hpp"


yaspr::IPv4::IPv4(const u_char* bytes, size_t linkLayerPayload)
{
  uin8_t firstByte;
  std::memcpy(&firstByte, bytes + linkLayerPayload, 1);
  
  version_ = firstByte >> 4;
  ihl_ = firstByte & 0x0F;

  std::memcpy(&differentiatedServices_, bytes + linkLayerPayload + 1, 1);
  std::memcpy(&totalLength_, bytes + linkLayerPayload + 2, 2);
  std::memcpy(&identification_, bytes + linkLayerPayload + 4, 2);

  uint16_t fragment;
  std::memcpy(&fragment, bytes + linkLayerPayload + 6, 2);

  flags_  = fragment >> 13;
  fragmentOffset = fragment & 0x0FFF;

  std::memcpy(&timeToLive_, bytes + linkLayerPayload + 8, 1);
  std::memcpy(&protocol_, bytes + linkLayerPayload + 9, 1);

  std::memcpy(&checksum_, bytes + linkLayerPayload + 10, 2);
  std::memcpy(&source_, bytes + linkLayerPayload + 12, 4);
  
  std::memcpy(&dest_, bytes + linkLayerPayload + 16, 4);

}


uint8_t yaspr::IPv4::transportProtocol() const noexcept
{
  return protocol_;
}

std::string yaspr::IPv4::ipv4ToString(ipv4_addr_t addr) const
{
  std::string strAddr;
  strAddr += addr[0];
  for (size_t i = 1; i < 4; ++i)
  {
    strAddr += '.';
    strAddr += addr[i];
  }

  return strAddr;
}

std::unordered_map< std::string, std::string > yaspr::IPv4::getFields() const
{
  std::unordered_map< std::string, std::string > fields;
  fields["Version"] = std::to_string(version_);
  fields["Header Length"] = std::to_string(ihl_ * 4);
  fields["Differentiated Services"] = std::to_string(differentiatedServices_);

  fields["Total Length"] = std::to_string(totalLength_);
  fields["Identification"] = std::to_string(identification_);
  fields["Flags"] = std::to_string(flags_);
  fields["Fragment Offset"] = std::to_string(fragmentOffset_);
  fields["Time To Live"] = std::to_string(timeToLive_);
  fields["Protocol"] = std::to_string(protocol_);
  fields["Checksum"] = std::to_string(checksum_);
  
  fields["Source"] = ipv4ToString(source_);
  fields["Destination"] = ipv4ToString(dest_);
  
  fields["Options Length"] = std::to_string(options_.size());
}
