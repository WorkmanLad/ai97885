#include <pch.h>
#include <Maze.h>
#include <Input.h>
#include <Screen.h>
#include <Control.h>

int main() {
    Maze* maze = new Maze(10, 10);
    Screen* screen = new Screen();
    Control control;
    Input input;

    maze->AddStart(3, 0);
    maze->AddPath(3, 1);
    maze->AddPath(4, 1);
    maze->AddPath(5, 1);
    maze->AddPath(5, 2);
    maze->AddEnd(6, 2);

    input.DisplayTutorial();

    control.MovePlayer(*maze, input.Move());
    control.MovePlayer(*maze, input.Move());
    control.MovePlayer(*maze, input.Move());

    screen->Display(*maze);

    delete screen;
    delete maze;
    return 0;
}