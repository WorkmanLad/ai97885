#pragma once
#include <pch.h>
#include <Board.h>

class Game {
public:
    Game();
    ~Game();

    boardstate InitialState();
    TileType Player(boardstate& state) const;
    set<int> Actions(boardstate& state) const;
    boardstate Result(boardstate& state, int actionPosition) const;
    TileType Winner(boardstate& state);

private:
    Board* _initialState;
};

