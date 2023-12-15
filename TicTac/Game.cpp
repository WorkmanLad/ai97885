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

Player Game::player(boardstate& state) {
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
