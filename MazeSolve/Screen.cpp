#include "pch.h"
#include "Screen.h"
#include <Maze.h>

void Screen::Display(Maze& maze) {
    int tile;

    wcout << "Maze:\n";
    for (int h = 0; h < maze._height; ++h) {
        for (int w = 0; w < maze._width; ++w) {
            tile = maze._maze[h][w];

            if (tile == WALL)
                wcout << "#";
            else if (tile == PATH)
                wcout << "_";
            else if (tile == START)
                wcout << "S";
            else if (tile == END)
                wcout << "X";
            else
                wcout << "*";
        }
        wcout << "\n";
    }
}
