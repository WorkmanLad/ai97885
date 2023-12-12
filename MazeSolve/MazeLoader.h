#pragma once
class Maze;

class MazeLoader {
public:
    Maze* Load(const char* filename);

private:
    void GetWidthAndHeight(const char*, int& width, int& height);
};
