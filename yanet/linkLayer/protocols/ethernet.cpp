#include "ethernet.hpp"
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
yaspr::Ethernet::Ethernet(const u_char* bytes, size_t len) 
{
  if (len < 14)
  {
    std::cerr << "invalid packet\n"; // TODO: handle invalid packet somehow
  }
  const uint8_t* newBytes = static_cast<const uint8_t*>(bytes);
  std::memcpy(dhost_.data(), newBytes, 6);
  std::memcpy(shost_.data(), newBytes + 6, 6);
  std::memcpy(&ether_type_, newBytes + 12, sizeof(ether_type_));
  ether_type_ = ntohs(ether_type_);
}


yaspr::mac_t yaspr::Ethernet::destAddr() const noexcept
{
  return dhost_;
}

yaspr::mac_t yaspr::Ethernet::sourceAddr() const noexcept
{
  return shost_;
}

uint16_t yaspr::Ethernet::netProt() const noexcept
{
  return ether_type_;
}
