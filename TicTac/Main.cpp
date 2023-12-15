#include "pch.h"
#include <Board.h>

int main() {
    Board board;

    boardstate state = board.GetBoard();

    cout << "State: ";
    if (state[0] == EMPTY)
        cout << "EMPTY" << endl;

    return 0;
}