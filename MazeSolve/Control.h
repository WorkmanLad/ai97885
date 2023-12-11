#pragma once
#include <Maze.h>

class Control {
public:
    Control();
    bool MovePlayer(Maze&, Direction);
    bool IsMoveAvailable(Maze&, Direction);

private:
    int _next_location_x;
    int _next_location_y;
};

