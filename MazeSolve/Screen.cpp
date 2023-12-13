#include "pch.h"
#include "Screen.h"
#include <Maze.h>

void Screen::Display(Maze& maze, bool showAllVisitedPaths = false) const {
    int tile = 0;

    wcout << "Maze:\n";
    for (int y = 0; y < maze._height; ++y) {
        for (int x = 0; x < maze._width; ++x) {
            tile = maze._maze[y][x];
            maze._maze[maze._goal_y][maze._goal_x] = END;
            maze._maze[maze._start_y][maze._start_x] = START;

            if (tile == WALL)
                wcout << "#";
            else if (tile == PLAYER)
                wcout << "P";
            else if (tile == PATH)
                wcout << " ";
            else if (tile == VISITED_PATH)
                wcout << "*";
            else if (tile == START)
                wcout << "A";
            else if (tile == END)
                wcout << "B";
        }
        wcout << "\n";
    }
}

// \u24D8, 25A1, 25B2