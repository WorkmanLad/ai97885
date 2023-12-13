#pragma once
#include <pch.h>
#include <Board.h>

class Game {
public:
    statetype InitialState() const { return board.GetBoard(); }

private:
    Board board;
};

