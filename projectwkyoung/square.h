#ifndef SQUARE
#define SQUARE
#include <string>
#include "player.h" // had to add this

class Square{
  protected:
  virtual int getTuition() {} // was pure virtual, might need to change back
  public: // might need to remove
  virtual std::string getOwner() {} //where did this come from?
 // bool monopolied; //where'd this come from?
  virtual std::string getBlock() {} //where did this come from?
  virtual void setEverything(std::string, std::string, int, int, int, int, int, int, int, int, int, int, bool, bool, char*, bool, int) {}
  virtual void setMonopolied() {}
  Square();
  ~Square();
  virtual std::string getBuildingName();
  virtual void setOwner(Player* player);
  virtual void set(Player* player, int improves);
  virtual int getImprovements() {}
};

#endif
