#include "pch.h"
#include <Game.h>
#include <Board.h>

int main() {
    Game game;
    Board board;

    boardstate state = board.GetBoard();
    state[1] = X;

    // PLAYER
    cout << "Player: ";
    if (game.player(state) == PlayerX)
        cout << "X";
    else
        cout << "O";
    cout << endl;

    // ACTIONS
    cout << "Available moves: ";
    set<int> moves = game.actions(state);
    for (auto i : moves) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}