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
    stream.read(&c, 1);

    while (c != '\n') {
        stream.read(&c, 1);
        ++width;
    }

    stream.seekg(0);

    while (!stream.eof()) {
        if (c == '\n')
            ++height;
        stream.read(&c, 1);
    }
    
    wcout << "Width: " << width << endl;
    wcout << "Height: " << height << endl;

    stream.close();
    return true;
}
