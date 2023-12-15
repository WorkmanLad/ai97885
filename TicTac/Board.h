#pragma once
#include <pch.h>

enum TileType {
    EMPTY = 0, X = 1, O = -1
};

class Board {
public:
    void AddPiece(TileType, int pos);
    boardstate GetBoard() const { return _board; }

private:
    boardstate _board = { 0 };
};