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
