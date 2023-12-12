#include "pch.h"
#include "Maze.h"

Maze::Maze(int width, int height) : _width(width), _height(height)
{ }

void Maze::AddPath(int x, int y) {
    _maze[y][x] = PATH;
}

void Maze::SetStart(int x, int y) {
    _maze[y][x] = START;
    _player_x = x;
    _player_y = y;
}

void Maze::SetGoal(int x, int y) {
    _maze[y][x] = END;
    _goal_x = x;
    _goal_y = y;
}

void Maze::SetSolution(int x, int y) {
    _maze[y][x] = SOLUTION;
}

bool Maze::ReachedGoal() const {
    return _player_x == _goal_x && _player_y == _goal_y;
}
