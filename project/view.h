#ifndef __VIEW_H__
#define __VIEW_H__
#include <iostream>
#include <string>

class View {

 public:
    virtual void printBoard() = 0;
    virtual void setNumOfPlayers() = 0; 
    virtual void setPlayer(char*) = 0;
};

#endif
