#include "pch.h"
#include "MazeLoader.h"
#include <Maze.h>

Maze* MazeLoader::Load(const char* filename) {
    ifstream stream(filename, ios::in);

    if (!stream)
        return nullptr;

    int width = 0;
    int height = 0;
    char c;
    
    GetWidthAndHeight(filename, width, height);

    Maze* maze = new Maze(width, height);
    int x = 0;
    int y = 0;

    while (!stream.eof()) {
        stream.read(&c, 1);
        
        if (c == '#') {
            ++x;
            continue;
        }

        else if (c == ' ')
            maze->AddPath(x, y);
        else if (c == 'A')
            maze->SetStart(x, y);
        else if (c == 'B')
            maze->SetGoal(x, y);

        else if (c == '\n') {
            x = 0;
            ++y;
            continue;
        }

        ++x;
    }

    stream.close();
    return maze;
}

void MazeLoader::GetWidthAndHeight(const char* filename, int& width, int& height) {
    int w = 0;
    int h = 0;
    char c;

    ifstream stream(filename, ios::in);
    stream.read(&c, 1);

    while (c != '\n') {
        stream.read(&c, 1);
        ++w;
    }
    stream.seekg(0);

    while (!stream.eof()) {
        if (c == '\n')
            ++h;
        stream.read(&c, 1);
    }

    width = w;
    height = h;

    stream.close();
}
