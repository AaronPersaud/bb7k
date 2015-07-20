#include "residence.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int Residence::getTuition() {
  int count = 0;
  for(int i; i < 4; i++) {
    if(&owner == &(owners[i])) {
      count++;
    }
  }
  return pow(2,count) * 25;
}
