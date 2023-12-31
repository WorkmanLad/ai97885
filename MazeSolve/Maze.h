#pragma once
#include <pch.h>

constexpr const int SIZE = 30;

enum MapSite {
    WALL = 0,
    PATH,
    VISITED_PATH,
    START,
    END,
    PLAYER,
    SOLUTION
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
    void SetStart(int x, int y);
    void SetGoal(int x, int y);
    void SetSolution(int x, int y);

    pair<int, int> GetPlayerPos();
    int GetWidth() const { return _width; }
    int GetHeight() const { return _height; }

    bool ReachedGoal() const;

private:
    int _goal_x, _goal_y;
    int _start_x, _start_y;
    int _player_x, _player_y;
    int _width, _height;
    int _maze[SIZE][SIZE] = { 0 };
};
