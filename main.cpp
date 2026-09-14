#include "sniffer.hpp"
#include <iostream>
int main()
{

  yaspr::Sniffer snf;
  // std::vector<std::string> devs = snf.getAllDevs();

  // for (size_t i = 0; i < devs.size(); ++i)
  // {
  //   std::cout << devs[i] << "\n";
  // }
  snf.chooseDev("en0");


  snf.startSniffing();
  //PART 1
  //TODO: packet sniffer begin stuff using:
  //-pcap
  //-tcpdump
  //...
  //GOAL -> look through paket and filter them using easy interface

  //TODO:make explanation  of packet data for some types of packets

  //TODO:make .pcap files reader and writer

  //TODO:make network statistics
  //
  //PART2

}
