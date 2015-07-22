#include "gym.h"
#include <iostream>

using namespace std;

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

void Gym::set(Player* player, int improves) {
  owner = player;
//  if (owner == NULL) {
//    cout << "NULL" << " ";
//  }
//  else{
//    cout << owner->getName() << endl;
//  }
}
