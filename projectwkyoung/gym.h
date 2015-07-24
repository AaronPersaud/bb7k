#ifndef GYM
#define GYM
#include "square.h"
#include "player.h"
#include <string>

class Gym: public Square{
  std::string buildingName;
  Player *owner;
  Player *owners[2];
  int improvement;
  public:
  int getTuition();
  int getImprovements();
  std::string getOwner();
//  std::string getBlock() {}
  void set(Player* player, int improves);
  std::string getBuildingName();
};

#endif
