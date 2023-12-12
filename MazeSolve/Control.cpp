#include "pch.h"
#include "Control.h"

Control::Control() : _next_location_x(0), _next_location_y(0)
{
}

bool Control::MovePlayer(Maze& maze, Direction direction) {
    if (!IsMoveAvailable(maze, direction))
        return false;

    maze._maze[maze._player_y][maze._player_x] = VISITED_PATH;

    maze._player_x = _next_location_x;
    maze._player_y = _next_location_y;

    maze._maze[_next_location_y][_next_location_x] = PLAYER;

    return true;
}

bool Control::IsMoveAvailable(Maze& maze, Direction direction) {
    int player_x = maze._player_x;
    int player_y = maze._player_y;

    switch (direction) {
    case NORTH:
        _next_location_x = player_x;
        _next_location_y = player_y - 1;
        break;

    case SOUTH:
        _next_location_x = player_x;
        _next_location_y = player_y + 1;
        break;

    case EAST:
        _next_location_x = player_x + 1;
        _next_location_y = player_y;
        break;

    case WEST:
        _next_location_x = player_x - 1;
        _next_location_y = player_y;
        break;
    }

    if (_next_location_x < 0 || _next_location_x >= maze._width)
        return false;
    if (_next_location_y < 0 || _next_location_y >= maze._height)
        return false;

    if (maze._maze[_next_location_y][_next_location_x] == WALL)
        return false;

    return true;
}
