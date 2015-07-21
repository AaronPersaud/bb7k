#include "building.h"
#include <iostream>

using namespace std;

void Building::notify(std::string buildingName,int improvement) {
  theController->notify(improvement,location);
}  

void Building::setEverything(string bN,string bl,int loc,int c,int t,int t0,int t1,int t2,int t3,int t4,int t5,int nI,bool isitowned,bool mor,char *pl,bool mon,int cOI) {
  buildingName = bN;
  block = bl;
  location = loc;
  cost = c;
  tuition = t;
  tuition0 = t0;
  tuition1 = t1;
  tuition2 = t2;
  tuition3 = t3;
  tuition4 = t4;
  tuition5 = t5;
  numImprovements = nI;
  owned = isitowned;
 // theController = tC;
 // owner = own;
  mortgaged = mor;
  players = pl;
  monopolied = mon;
  costOfImprovement = cOI; 
}

void Building::setMonopolied() {monopolied = true; }

void Building::changeOwner(Player * newOwner){
  owner = newOwner;
}
void Building::changeMortgage() {
  mortgaged = !mortgaged;
}
void Building::improve() {
  if(owned == false) {
    cout << "This building is unowned. Improvement not possible." << endl;
  }
  else if (monopolied == false) {
    cout << "You do not own all buildings on this block. Improvement not allowed." << endl;
  }
  else if (mortgaged == true) {
    cout << "Property is mortgaged. Cannot improve." << endl;
  }
  else if (numImprovements == 5) {
    cout << "You've hit the max number of improvements!" << endl;
  }
  else if (numImprovements == 0) {
    tuition = tuition1;
    numImprovements++;
    notify(buildingName,1);
  }
  else if (numImprovements == 1) {
    tuition = tuition2;
    numImprovements++;
    notify(buildingName,2);
  }
  else if (numImprovements == 2) {
    tuition = tuition3;
    numImprovements++;
    notify(buildingName,3);
  }
  else if (numImprovements == 3) {
    tuition = tuition4;
    numImprovements++;
    notify(buildingName,4);
  }
  else if (numImprovements == 4) {
    tuition = tuition5;
    numImprovements++;
    notify(buildingName,5);
  }
  else {
    cout << "Error occured." << endl;
  }
}

void Building::unimprove() {
  if(owned == false) {
    cout << "This building is unowned. Unimprovement not possible." << endl;
  }
  else if (monopolied == false) {
    cout << "You do not own all buildings on this block. Unimprovement not allowed." << endl;
  }
  else if (mortgaged == true) {
    cout << "Property is mortgaged. Nothing to unimprove." << endl;
  }
  else if (numImprovements == 0) {
    cout << "You've have no improvements!" << endl;
  }
  else if (numImprovements == 1) {
    tuition = tuition0;
    numImprovements--;
    notify(buildingName,0);
  }
  else if (numImprovements == 2) {
    tuition = tuition1;
    numImprovements--;
    notify(buildingName,1);
  }
  else if (numImprovements == 3) {
    tuition = tuition2;
    numImprovements--;
    notify(buildingName,2);
  }
  else if (numImprovements == 4) {
    tuition = tuition3;
    numImprovements--;
    notify(buildingName,3);
  }
  else if (numImprovements == 5) {
    tuition = tuition4;
    numImprovements--;
    notify(buildingName,4);
  }
  else {
    cout << "Error occured." << endl;
  }
}

int Building::getTuition() {
  if (owned == false) {
    cout << "Building not owned." << endl;
    return 0;
  }
  else if (mortgaged == true) {
    cout << "Property is mortgaged." << endl;
    return 0;
  }
  else if (monopolied == false) {
    cout << "Tuition: " << tuition0 << endl;
    return tuition0;
  }
  else if (monopolied == true && numImprovements == 0) {
    cout << "Tuition: " << tuition0*2 << endl;
    return tuition0*2;
  }
  else{
    cout << "Tuition: " << tuition << endl;
    return tuition;
  }
}
