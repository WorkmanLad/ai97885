#pragma once
#include <pch.h>
#include <Board.h>

enum Player {
    PlayerX, PlayerO
};

class Game {
public:
    Game();
    ~Game();

    boardstate initialState();
    Player player(boardstate& state) const;
    set<int> actions(boardstate& state) const;

private:
    Board* _initialState;
};

