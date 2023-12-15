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

boardstate Game::initialState() {
    if (_initialState != nullptr)
        delete _initialState;

    _initialState = new Board();
    return _initialState->GetBoard();
}

Player Game::player(boardstate& state) const {
    int xCount = 0;
    int oCount = 0;

    for (auto i : state) {
        if (i == X)
            ++xCount;
        else if (i == O)
            ++oCount;
    }

    if (oCount == xCount)
        return PlayerX;

    return PlayerO;
}

set<int> Game::actions(boardstate& state) const {
    set<int> availableMoves = { };
    int count = 0;

    for (auto i : state) {
        if (i == EMPTY)
            availableMoves.emplace(count);
        ++count;
    }

    return availableMoves;
}