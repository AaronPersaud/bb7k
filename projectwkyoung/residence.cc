#include "residence.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

string Residence::getOwner() {
  if (owner == NULL) {
    return "BANK";
  }
  else{
    return owner->getName();
  }
}

int Residence::getImprovements() {
  return improvement;
}

string Residence::getBuildingName() {
  return buildingName;
}

int Residence::getTuition() {
  int count = 0;
  for(int i; i < 4; i++) {
    if(&owner == &(owners[i])) {
      count++;
    }
  }
  return pow(2,count) * 25;
}

void Residence::set(Player* player, int improves) {
  owner = player;
  improvement = improves;
} 
