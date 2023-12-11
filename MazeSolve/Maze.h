#pragma once
#include <pch.h>

constexpr const int SIZE = 30;

enum MapSite {
    WALL = 0,
    PATH,
    VISITED_PATH,
    START,
    END,
    PLAYER
};

enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

class Maze {
    friend class Screen;
    friend class Control;
public:
    Maze(int width, int height);
    void AddPath(int x, int y);
    void AddStart(int x, int y);
    void AddEnd(int x, int y);

private:
    int _player_x, _player_y;
    int _width, _height;
    int _maze[SIZE][SIZE] = { 0 };
};
