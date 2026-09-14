#include "linkLayerHeader.hpp"
#include <ostream>
#include <iomanip>
namespace yaspr
{
  std::ostream& operator<<(std::ostream& out, mac_t addr)
  {
    out << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(addr[0]);
    for (size_t byteNum = 1; byteNum < ETH_ALEN; ++byteNum)
    {
      out << ':';
      out << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(addr[byteNum]);
    }
    return out;
  }

}
