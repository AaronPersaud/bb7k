#include "player.h"

using namespace std;

void Player::setMoney(int i) {} //TODO

void Player::setCurrentPosition(int i) {} //TODO
  
void Player::setPrevPosition(int i) {} //TODO
  
int Player::getCurrentPosition() {} //TODO

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
