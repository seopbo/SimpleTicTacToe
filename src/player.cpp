#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string name) {
    m_userName = name;
}
string Player::getUsername() {
    return m_userName;
}
