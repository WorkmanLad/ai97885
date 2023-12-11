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

void Maze::MovePlayer(Direction direction) {
    int new_location_x = 0;
    int new_location_y = 0;

    switch (direction) {
    case NORTH:
        new_location_x = _player_x;
        new_location_y = _player_y - 1;
        break;

    case SOUTH:
        new_location_x = _player_x;
        new_location_y = _player_y + 1;
        break;

    case EAST:
        new_location_x = _player_x + 1;
        new_location_y = _player_y;
        break;

    case WEST:
        new_location_x = _player_x - 1;
        new_location_y = _player_y;
        break;
    }

    if (new_location_x < 0 || new_location_x >= SIZE)
        return;
    if (new_location_y < 0 || new_location_y >= SIZE)
        return;

    if (_maze[new_location_x][new_location_y] == WALL)
        return;

    _maze[_player_x][_player_y] = VISITED_PATH;

    _player_x = new_location_x;
    _player_y = new_location_y;

    _maze[_player_x][_player_y] = PLAYER;
}
