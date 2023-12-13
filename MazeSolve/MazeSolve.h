#pragma once
#include <Maze.h>
#include <Node.h>
#include <Frontier.h>

class MazeSolve {
public:
    ~MazeSolve();

    Maze* Solve(const char* mazeFilename, Frontier&);

    int GetNumberOfExploredStates() const { return _numberOfExplored; }

private:
    vector<Node*> Neighbors(Node*);
    Maze* Solution(deque<Direction> actions, const char* mazeFilename);
    void ClearExplored();

    set<Node*> explored;
    int _numberOfExplored = 0;
};

