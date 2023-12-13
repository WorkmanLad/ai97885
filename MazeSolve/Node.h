#pragma once
#include <Maze.h>

class Node {
public:
    Node(Maze* state, Node* parent, Direction = {});
    ~Node();

    bool operator==(Node&);

    Maze* state;
    Node* parent;
    Direction action;
};