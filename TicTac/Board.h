#pragma once
#include <pch.h>

enum TileType {
    EMPTY, X, O
};

class Board {
public:
    void AddPiece(TileType, int pos);
    boardstate GetBoard() const { return _board; }

private:
    boardstate _board = { 0 };
};