#ifndef LINK_LAYER_HEADER_HPP
#define LINK_LAYER_HEADER_HPP

namespace yaspr
{
  class LinkLayerHeader {
  public:
    virtual void destAddr() = 0;
    virtual void sourceAddr() = 0;
    // virtual void getPayload() = 0;
    virtual ~LinkLayerHeader = default;
  }
}


#endif
