#include "pch.h"
#include "MazeLoader.h"
#include <Maze.h>

bool MazeLoader::Load(const char* filename) {
    ifstream stream(filename, ios::in);

    if (!stream)
        return false;

    int width = 0;
    int height = 0;
    char c;
    GetWidthAndHeight(filename, width, height);

    while (!stream.eof()) {
        stream.read(&c, 1);
        cout << c;
    }

    stream.close();
    return true;
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
