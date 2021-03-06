#include "player.h"

using namespace std;

Player::Player(): money(0), RolluptheRimCup(0), DCTimsLine(true),DCTurns(0) {}

void Player::setMoney(int i) {
  money += i;
}

int Player::getMoney() {
  return money;
}

int Player::getTimsCup() {
  return RolluptheRimCup;
}

bool Player::getTimsLine() {
  return DCTimsLine;
}

int Player::getDCTurns() {
  return DCTurns;
}

void Player::setCurrentPosition(int i) {
  position = i;
} 
  
void Player::setPrevPosition(int i) {} //TODO
  
int Player::getCurrentPosition() {
  return position;
}

void Player::setName(string s) {
  name = s;
}
void Player::setToken(char c) {
  token = c;
}

string Player::getName() {
  return name;
}
char Player::getToken() {
  return token;
}

int Player::getTuition(int i) {}//TODO

void Player::set(int m,int R,int p,bool D,int DC) {
  money = m;
  RolluptheRimCup = R;
  position = p;
  DCTimsLine = D;
  DCTurns = DC;
}
