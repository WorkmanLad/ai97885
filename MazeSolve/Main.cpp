#include <pch.h>
#include <Maze.h>
#include <Player.h>
#include <Screen.h>

int main() {
    Maze* maze = new Maze(10, 10);
    Player player;
    Screen* screen = new Screen();

    maze->AddStart(0, 1);
    maze->AddPath(1, 1);
    maze->AddPath(1, 2);
    maze->AddPath(1, 3);
    maze->AddPath(2, 3);
    maze->AddEnd(2, 4);

    screen->Display(*maze);

    delete screen;
    delete maze;
    return 0;
}