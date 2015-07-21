#include "rolluptherim.h"
#include <cstdlib>
#include <iostream>

using namespace std;

RollUpTheRim* RollUpTheRim::Cup1 = NULL;
RollUpTheRim* RollUpTheRim::Cup2 = NULL;
RollUpTheRim* RollUpTheRim::Cup3 = NULL;
RollUpTheRim* RollUpTheRim::Cup4 = NULL; 

RollUpTheRim* RollUpTheRim::getinstance() { 
  atexit(cleanup);
  if (Cup1==NULL) {
    Cup1 = new RollUpTheRim;
    return Cup1;
  }
  else if(Cup2 == NULL) {
    Cup2 = new RollUpTheRim;
    return Cup2;
  } 
  else if(Cup3 == NULL) {
    Cup3 = new RollUpTheRim;
    return Cup3;
  }
  else if(Cup4 == NULL) {
    Cup4 = new RollUpTheRim;
    return Cup4;
  }
  else{
    cout << "Maximum number of cups created!" << endl;
    return NULL;
  }
}

void RollUpTheRim::cleanup() {
  delete Cup1;
  delete Cup2;
  delete Cup3;
  delete Cup4;
}

