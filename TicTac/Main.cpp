#include "pch.h"
#include <Game.h>
#include <Board.h>

void Players(Game&, boardstate&);
void Actions(Game&, boardstate&);
void Results(Game&, boardstate&, int);
void Winners(Game&, boardstate&);

int main() {
    Game game;
    Board board;

    boardstate state = board.GetBoard();
    state[3] = state[6] = state[5] = state[7] = O;
    state[0] = state[1] = state[2] = state[5] = state[8] = X;

    Players(game, state);
    Actions(game, state);
    //Results(game, state, 8);
    Winners(game, state);

    bool ended = game.Terminal(state);
    cout << "Game ended: " << (ended ? "true" : "false");
    cout << endl;

    if (ended) {
        int utility = game.Utility(state);
        cout << "Utility: " << utility << endl;
    }
    
    return 0;
}

static void Players(Game& game, boardstate& state) {
    cout << "Player: ";
    if (game.Player(state) == X)
        cout << "X";
    else
        cout << "O";
    cout << endl;
}
static void Actions(Game& game, boardstate& state) {
    cout << "Available moves: ";
    set<int> moves = game.Actions(state);
    for (auto i : moves) {
        cout << i << " ";
    }
    cout << endl;
}
static void Results(Game& game, boardstate& state, int actionPosition) {
    cout << "Results after playing on position " << actionPosition << ":\n";
    boardstate s = game.Result(state, actionPosition);
    int count = 0;
    for (auto i : s) {
        cout << i << " ";
        if (++count == 3) {
            count = 0;
            cout << "\n";
        }
    }
        
    cout << endl;
}
static void Winners(Game& game, boardstate& state) {
    cout << "Winner: ";
    if (game.Winner(state) == EMPTY)
        cout << "none";
    else if (game.Winner(state) == X)
        cout << "X";
    else
        cout << "O";

    cout << endl;
}
