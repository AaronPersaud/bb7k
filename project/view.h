#ifndef __VIEW_H__
#define __VIEW_H__
#include <iostream>
#include <string>

class View {

 public:
    virtual void startGame() = 0;
    virtual void printBoard() = 0;
    virtual void setNumOfPlayers(int) = 0; 
    virtual void setPlayer(char*) = 0;
    virtual ~View() = 0;
    virtual void improvement(int, int) = 0;
};

#endif
