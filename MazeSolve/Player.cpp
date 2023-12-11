#include "pch.h"
#include "Player.h"

Player::Player() {
    _position = make_pair<int, int>(0, 0);
}

void Player::SetPosition(int x, int y) {
    _position = make_pair(x, y);
}
