#include "pch.h"
#include "Control.h"

bool Control::MovePlayer(Maze& maze, Direction direction) {
    int new_location_x = 0;
    int new_location_y = 0;
    int player_x = maze._player_x;
    int player_y = maze._player_y;

    switch (direction) {
    case NORTH:
        new_location_x = player_x;
        new_location_y = player_y - 1;
        break;

    case SOUTH:
        new_location_x = player_x;
        new_location_y = player_y + 1;
        break;

    case EAST:
        new_location_x = player_x + 1;
        new_location_y = player_y;
        break;

    case WEST:
        new_location_x = player_x - 1;
        new_location_y = player_y;
        break;
    }

    if (new_location_x < 0 || new_location_x >= SIZE)
        return false;
    if (new_location_y < 0 || new_location_y >= SIZE)
        return false;

    if (maze._maze[new_location_y][new_location_x] == WALL)
        return false;

    maze._maze[player_y][player_x] = VISITED_PATH;

    maze._player_x = new_location_x;
    maze._player_y = new_location_y;

    maze._maze[new_location_y][new_location_x] = PLAYER;

    return true;
}
