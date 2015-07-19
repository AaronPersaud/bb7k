#include "player.h"

using namespace std;

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
void Player::improve(){}//TODO
void Player::mortgage(){}//TODO
void Player::unmortgage(){}//TODO
void Player::bankrupt(){}//TODO
void Player::assets(){}//TODO
void Player::trade(){}//TODO
void Player::roll(){}//TODO
