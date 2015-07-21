#ifndef GYM
#define GYM
#include "square.h"
#include "player.h"

class Gym: public Square{
  int getTuition();
  Player *owner;
  Player *owners[2];
//  std::string getOwner() {}
//  std::string getBlock() {}
};

#endif
