#include "pch.h"
#include "MazeSolve.h"
#include <Control.h>
#include <MazeLoader.h>

MazeSolve::~MazeSolve() {
    ClearExplored();
}

Maze* MazeSolve::Solve(const char* mazeFilename, Frontier& frontier) {
    ClearExplored();

    Maze* maze = MazeLoader().Load(mazeFilename);
    Maze* solution = nullptr;

    Node* initialState = new Node(maze, nullptr);
    frontier.AddNode(initialState);

    _numberOfExplored = 0;

    while (true) {
        // Check if there is no solution
        if (frontier.IsEmpty()) {
            for (auto n : explored)
                delete n;

            delete maze;
            return nullptr;
        }

        // Remove a node from the frontier
        Node* node = frontier.RemoveNode();
        ++_numberOfExplored;

        // Goal test
        if (node->state->ReachedGoal()) {
            deque<Direction> actions;

            while (node->parent != nullptr) {
                actions.emplace_front(node->action);
                node = node->parent;
            }

            solution = Solution(actions, mazeFilename);
            break;
        }

        // Add node to explored
        explored.emplace(node);

        // Add neighbors to the frontier, expand the node
        for (auto n : Neighbors(node)) {
            bool inExplored = false;

            for (auto e : explored)
                if (*e == *n) {
                    inExplored = true;
                    delete n;
                    break;
                }

            if (!inExplored) {
                frontier.AddNode(n);
            }
        }
    }

    return solution;
}

vector<Node*> MazeSolve::Neighbors(Node* state) {
    Control control;
    vector<Node*> neighbors = {};
    vector<Direction> directions = {};
    Maze* maze = state->state;

    if (control.IsMoveAvailable(*maze, NORTH))
        directions.emplace_back(NORTH);
    if (control.IsMoveAvailable(*maze, SOUTH))
        directions.emplace_back(SOUTH);
    if (control.IsMoveAvailable(*maze, EAST))
        directions.emplace_back(EAST);
    if (control.IsMoveAvailable(*maze, WEST))
        directions.emplace_back(WEST);

    for (auto d : directions) {
        Maze* newMaze = new Maze(*maze);
        control.MovePlayer(*newMaze, d);

        neighbors.emplace_back(new Node(newMaze, state, d));
    }

    return neighbors;
}

Maze* MazeSolve::Solution(deque<Direction> actions, const char* mazeFilename) {
    MazeLoader loader;
    Control control;
    Maze* maze = loader.Load(mazeFilename);

    for (auto a : actions) {
        control.MovePlayer(*maze, a);
    }

    return maze;
}

void MazeSolve::ClearExplored() {
    if (explored.empty())
        return;

    for (auto n : explored)
        delete n;

    explored.clear();
}
