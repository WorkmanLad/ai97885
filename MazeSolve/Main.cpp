#include <pch.h>
#include <MazeSolve.h>
#include <Screen.h>
#include <DFSFrontier.h>
#include <BFSFrontier.h>

int main() {
    Screen screen;
    MazeSolve solve;
    BFSFrontier frontier;

    wcout << "Solving...\n";
    Maze* maze = solve.Solve("Maze2.txt", frontier);
    wcout << "States explored: " << solve.GetNumberOfExploredStates() << endl;
    wcout << "Solution:\n";

    if (maze == nullptr) {
        wcout << "Maze unsolved." << endl;
        return 0;
    }

    screen.Display(*maze, false);

    delete maze;
    return 0;
}
