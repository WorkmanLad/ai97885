#pragma once
#include <pch.h>

class Player {
public:
    Player();

    void SetPosition(int x, int y);
    pair<int, int> GetPosition() const { return _position; }

private:
    pair<int, int> _position;
};