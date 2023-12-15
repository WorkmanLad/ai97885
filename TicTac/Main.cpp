#include "pch.h"
#include <Game.h>
#include <Board.h>

int main() {
    Game game;
    Board board;

    boardstate state = board.GetBoard();
    state[1] = X;

    cout << "State: ";
    if (state[0] == EMPTY)
        cout << "EMPTY" << endl;

    cout << "Player: ";
    if (game.player(state) == PlayerX)
        cout << "X";
    else
        cout << "O";

    cout << endl;

    return 0;
}