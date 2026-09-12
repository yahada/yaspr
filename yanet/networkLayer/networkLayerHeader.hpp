#ifndef NETWORK_LAEYER_HEADER_HPP
#define NETWORK_LAEYER_HEADER_HPP
#include <unordered_map>
namespace yaspr
{
  struct NetworkLayerHeader {
    virtual uint8_t transportProtocol() const noexcept = 0;
    virtual std::string getSourseAddr() const noexcept = 0;
    virtual std::string getDestAddr() const noexcept = 0;

    virtual std::unordered_map< std::string, std::string > getFields() const = 0;
    virtual ~NetworkLayerHeader() = default;
  };
}


#endif
