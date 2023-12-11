#include <pch.h>
#include <Maze.h>
#include <Input.h>
#include <Screen.h>
#include <Control.h>

void test1();

int main() {
    

    return 0;
}

void test1() {
    Maze* maze = new Maze(10, 10);
    Screen* screen = new Screen();
    Control control;
    Input input;

    maze->SetStart(3, 0);
    maze->AddPath(3, 1);
    maze->AddPath(4, 1);
    maze->AddPath(5, 1);
    maze->AddPath(5, 2);
    maze->SetGoal(6, 2);

    screen->Display(*maze);
    wcout << endl;
    input.DisplayTutorial();

    while (!maze->ReachedGoal()) {
        control.MovePlayer(*maze, input.Move());
        wcout << "\n";
        screen->Display(*maze);
    }

    delete screen;
    delete maze;
}