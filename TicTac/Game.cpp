#include "pch.h"
#include "Game.h"

Game::Game() {
    _initialState = nullptr;
}

Game::~Game() {
    if (_initialState != nullptr)
        delete _initialState;

    _initialState = 0;
}

boardstate Game::InitialState() {
    if (_initialState != nullptr)
        delete _initialState;

    _initialState = new Board();
    return _initialState->GetBoard();
}

TileType Game::Player(boardstate& state) const {
    int xCount = 0;
    int oCount = 0;

    for (auto i : state) {
        if (i == X)
            ++xCount;
        else if (i == O)
            ++oCount;
    }

    if (oCount == xCount)
        return X;

    return O;
}

set<int> Game::Actions(boardstate& state) const {
    set<int> availableMoves = { };
    int count = 0;

    for (auto i : state) {
        if (i == EMPTY)
            availableMoves.emplace(count);
        ++count;
    }

    return availableMoves;
}

boardstate Game::Result(boardstate& state, int actionPosition) const {
    if (state[actionPosition] != EMPTY)
        throw;

    boardstate resultBoard = state;

    resultBoard[actionPosition] = Player(state);
    return resultBoard;
}

TileType Game::Winner(boardstate& s) {
    if (s[0] != EMPTY)
        if ((s[0] == s[1] and s[0] == s[2]) or (s[0] == s[3] and s[0] == s[6]) or (s[0] == s[4] and s[0] == s[8]))
            return TileType(s[0]);

    if (s[8] != EMPTY)
        if ((s[8] == s[7] and s[8] == s[6]) or (s[8] == s[5] and s[8] == s[2]))
            return TileType(s[8]);

    if (s[4] != EMPTY)
        if ((s[4] == s[3] and s[4] == s[5]) or (s[4] == s[1] and s[4] == s[7]))
            return TileType(s[4]);

    return EMPTY;
}
