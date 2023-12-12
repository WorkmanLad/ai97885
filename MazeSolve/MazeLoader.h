#pragma once

class MazeLoader {
public:
    bool Load(const char* filename);

private:
    void GetWidthAndHeight(const char*, int& width, int& height);
};
