#ifndef SQUARE
#define SQUARE
#include <string>

class Square{
  protected:
  int getTuition(); // was pure virtual, might need to change back
  public: // might need to remove
  std::string getOwner(); //where did this come from?
  bool monopolied; //where'd this come from?
  std::string getBlock(); //where did this come from?
};

#endif
