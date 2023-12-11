#pragma once
#include <pch.h>

enum MapSite {
    WALL = 0,
    PATH,
    START,
    END
};

class Maze {
    friend class Screen;
public:
    Maze(int width, int height);
    void AddPath(int x, int y);
    void AddStart(int x, int y);
    void AddEnd(int x, int y);

private:
    int _width, _height;
    int _maze[30][30] = { 0 };
};

