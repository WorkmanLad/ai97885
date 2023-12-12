#include "pch.h"
#include "Screen.h"
#include <Maze.h>

void Screen::Display(Maze& maze, bool showAllVisitedPaths = false) const {
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
                wcout << " ";
            else if (tile == SOLUTION)
                wcout << "*";
            else if (tile == START)
                wcout << "S";
            else if (tile == END)
                wcout << "X";

            if (showAllVisitedPaths)
                if (tile == VISITED_PATH)
                    wcout << "w";
        }
        wcout << "\n";
    }
}

// \u24D8, 25A1, 25B2