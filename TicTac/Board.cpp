#include "pch.h"
#include "Board.h"

void Board::AddPiece(TileType t, int p) {
    _board[p] = t;
}
