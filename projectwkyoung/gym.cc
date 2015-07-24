#include "gym.h"
#include <iostream>

using namespace std;

string Gym::getBuildingName() {
  return buildingName;
}

int Gym::getImprovements() {
  return improvement;
}

int Gym::getTuition() {
  int count = 0;
  for(int i; i < 2; i++) {
    if (&owner == &(owners[i])) {
      count++;
    }
  }
  if (count == 1) {
    return 4;
  }
  else if (count == 2) {
    return 10;
  }
  else{
    cout << "Error encountered" << endl;
  }
}

string Gym::getOwner() {
  if (owner == NULL) {
    return "BANK";
  }
  else{
    return owner->getName();
  }
}

void Gym::set(Player* player, int improves) {
  owner = player;
  improvement = improves;
//  if (owner == NULL) {
//    cout << "NULL" << " ";
//  }
//  else{
//    cout << owner->getName() << endl;
//  }
}
