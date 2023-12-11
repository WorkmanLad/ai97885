#include "pch.h"
#include "MazeLoader.h"


bool MazeLoader::Load(const char* filename) {
    ifstream stream(filename, ios::in);

    if (!stream)
        return false;

    stream.close();
    return true;
}
