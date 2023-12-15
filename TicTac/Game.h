#pragma once
#include <pch.h>
#include <Board.h>

class Game {
public:
    Game();
    ~Game();

    boardstate InitialState();
    TileType Player(boardstate&) const;
    set<int> Actions(boardstate&) const;
    boardstate Result(boardstate&, int actionPosition) const;
    TileType Winner(boardstate&);
    bool Terminal(boardstate&);

private:
    Board* _initialState;
};

