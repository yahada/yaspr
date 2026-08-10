#include "ethernet.hpp"

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

void yaspr::Ethernet::showDestAddr() const noexcept
{
  for (size_t i = 0; i < 6; ++i)
  {
    if (i != 0)
    {
      std::cout << ':';
    }
    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(dhost_[i]);
  }
}

void yaspr::Ethernet::showSourceAddr() const noexcept
{
  for (size_t i = 0; i < 6; ++i)
  {
    if (i != 0)
    {
      std::cout << ':';
    }
    
    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(shost_[i]);


  }
}
