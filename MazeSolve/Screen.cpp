#include "pch.h"
#include "Screen.h"
#include <Maze.h>
#include <Player.h>

void Screen::Display(Maze& maze, Player& player) {
    int tile = 0;
    int player_x = player._position.first;
    int player_y = player._position.second;

    wcout << "Maze:\n";
    for (int h = 0; h < maze._height; ++h) {
        for (int w = 0; w < maze._width; ++w) {
            if (h == player_y && w == player_x) {
                wcout << "P";
                continue;
            }

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
