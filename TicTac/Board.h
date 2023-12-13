#pragma once
#include <pch.h>

enum TileType {
    EMPTY, X, O
};

class Board {
public:
    void AddPiece(TileType, int pos);
    statetype GetBoard() const { return _board; }

private:
    statetype _board = { 0 };
};