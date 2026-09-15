#include "IPv6.hpp"
#include <arpa/inet.h>

yaspr::IPv6::IPv6(const u_char* bytes, size_t linkLayerPayload)
{
  const u_char* shiftedBytes = bytes + linkLayerPayload;
  uint32_t fragment;
  std::memcpy(&fragment, shiftedBytes, 4);
  version_ = fragment >> 28;
  trafficClass_ = (fragment >> 20) & 0xFF;
  flowLabel_ = fragment & 0xFFFFF;

  std::memcpy(&payloadLength_, shiftedBytes + 4, 2);
  std::memcpy(&nextHeader_, shiftedBytes + 6, 1);
  std::memcpy(&hopLimit_, shiftedBytes + 7, 1);
  std::memcpy(&source_, shiftedBytes + 8, 16);
  std::memcpy(&dest_, shiftedBytes + 24, 16);
}


std::string yaspr::IPv6::ipv6ToString(ipv6_t addr) const
{
  char buffer[INET6_ADDRSTRLEN];

  inet_ntop(AF_INET6, addr.data(), buffer, sizeof(buffer));

  return std::string(buffer);
}

std::string yaspr::IPv6::sourceAddr() const noexcept
{
  return ipv6ToString(source_);
}

std::string yaspr::IPv6::destAddr() const noexcept
{
  return ipv6ToString(dest_);
}

uint8_t yaspr::IPv6::transportProtocol() const noexcept
{
  return 0;
}


std::unordered_map<std::string, std::string> yaspr::IPv6::getFields() const noexcept
{
  std::unordered_map<std::string, std::string> fields;

  fields["Version"] = std::to_string(version_);
  fields["Traffic Class"] = std::to_string(trafficClass_);
  fields["Flow Label"] = std::to_string(flowLabel_);
  fields["Payload Length"] = std::to_string(payloadLength_);
  fields["Next Header"] = std::to_string(nextHeader_);
  fields["Hop Limit"] = std::to_string(hopLimit_);
  fields["Source"] = ipv6ToString(source_);
  fields["Destination"] = ipv6ToString(dest_);

  return fields;
}

