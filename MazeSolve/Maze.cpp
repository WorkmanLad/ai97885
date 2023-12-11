#include "pch.h"
#include "Maze.h"

Maze::Maze(int width, int height) : _width(width), _height(height) { }

void Maze::AddPath(int x, int y) {
    _maze[x][y] = PATH;
}

void Maze::AddStart(int x, int y) {
    _maze[x][y] = START;
    _player_x = x;
    _player_y = y;
}

void Maze::AddEnd(int x, int y) {
    _maze[x][y] = END;
}

