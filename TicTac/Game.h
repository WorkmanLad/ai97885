#pragma once
#include <pch.h>
#include <Board.h>

class Game {
public:
    Game();
    ~Game();
    boardstate InitialState();

private:
    Board* _initialState;
};

