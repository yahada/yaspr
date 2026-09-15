#include "IPv4.hpp"
#include <arpa/inet.h>


yaspr::IPv4::IPv4(const u_char* bytes, size_t linkLayerPayload)
{
  const u_char* shiftedBytes = bytes + linkLayerPayload;
  uint8_t firstByte;
  std::memcpy(&firstByte, shiftedBytes, 1);

  version_ = firstByte >> 4;
  ihl_ = firstByte & 0x0F;

  std::memcpy(&differentiatedServices_, shiftedBytes + 1, 1);

  std::memcpy(&totalLength_, shiftedBytes + 2, 2);
  totalLength_ = ntohs(totalLength_);
  std::memcpy(&identification_, shiftedBytes + 4, 2);
  identification_ = ntohs(identification_);

  uint16_t fragment;
  std::memcpy(&fragment, shiftedBytes + 6, 2);
  fragment = ntohs(fragment);
  flags_  = fragment >> 13;
  fragmentOffset_ = fragment & 0x1FFF;

  std::memcpy(&timeToLive_, shiftedBytes + 8, 1);
  std::memcpy(&protocol_, shiftedBytes + 9, 1);

  std::memcpy(&checksum_, shiftedBytes + 10, 2);
  checksum_ = ntohs(checksum_);

  std::memcpy(&source_, shiftedBytes + 12, 4);

  std::memcpy(&dest_, shiftedBytes + 16, 4);
  if (ihl_ > 5)
  {
    size_t optionsLen = (ihl_ - 5) * 4;
    options_.assign(shiftedBytes + 20, shiftedBytes + 20 + optionsLen);
  }
}


uint8_t yaspr::IPv4::transportProtocol() const noexcept
{
  return protocol_;
}

std::string yaspr::IPv4::sourceAddr() const noexcept
{
  return ipv4ToString(source_);
}

std::string yaspr::IPv4::destAddr() const noexcept
{
  return ipv4ToString(dest_);
}


std::string yaspr::IPv4::ipv4ToString(ipv4_t addr) const
{
  char buffer[INET_ADDRSTRLEN];

  inet_ntop(AF_INET, addr.data(), buffer,  INET_ADDRSTRLEN);
  return std::string(buffer);
}

std::unordered_map< std::string, std::string > yaspr::IPv4::getFields() const noexcept
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
  //TODO: read options;
  return fields;
}
