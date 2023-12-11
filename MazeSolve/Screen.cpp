#include "pch.h"
#include "Screen.h"
#include <Maze.h>

void Screen::Display(Maze& maze) {
    int tile = 0;

    wcout << "Maze:\n";
    for (int y = 0; y < maze._height; ++y) {
        for (int x = 0; x < maze._width; ++x) {
            tile = maze._maze[y][x];

            if (tile == WALL)
                wcout << "#";
            else if (tile == PLAYER)
                wcout << "P";
            else if (tile == PATH)
                wcout << "_";
            else if (tile == VISITED_PATH)
                wcout << "v";
            else if (tile == START)
                wcout << "S";
            else if (tile == END)
                wcout << "X";
        }
        wcout << "\n";
    }
}

// \u24D8, 25A1, 25B2