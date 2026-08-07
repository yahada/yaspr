#include <ethernet.hpp>

yaspr::Ethernet::Ethernet(const uint8_t* bytes, size_t len) 
{
  if (len != 14)
  {
    std::cerr << "invalid packet\n" // TODO: handle invalid packet somehow
  }

  std::memcpy(dhost_.data(), bytes, 6);
  std::memcpy(shost_.data(), bytes + 6, 6);
  std::memcpy(&ether_type_, bytes + 12, sizeof(ether_type_));
  ether_type_ = ntohs(ether_type_);
}


yaspr::mac_t Ethernet::destAddr() const noexcept
{
  return dhost_;
}

yaspr::mac_t Ethernet::sourceAddr() const noexcept
{
  return shost_;
}
