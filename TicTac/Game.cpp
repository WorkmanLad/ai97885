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