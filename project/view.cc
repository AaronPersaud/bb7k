#include "view.h"

#include <iostream> // remove after testing

void View::setNumOfPlayers(int i) {}

void View::setPlayer(char *c,int size) {
  for (int i=0;i<size;i++) {
    std::cout << c[i] << std::endl;
  }
}
    
