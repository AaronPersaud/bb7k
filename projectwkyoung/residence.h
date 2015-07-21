#ifndef RESIDENCE
#define RESIDENCE
#include "square.h"
#include "player.h"

class Residence: public Square{
  int getTuition();
  Player *owner;
  Player *owners[4];
//  std::string getOwner() {} //TODO
//  std::string getBlock() {} //TODO
    
};

#endif
