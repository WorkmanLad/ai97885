#include "pch.h"
#include "Node.h"

Node::Node(Maze* s, Node* p, Direction a) {
    state = s;
    parent = p;
    action = a;
}

Node::~Node() {
    delete state;
}

bool Node::operator==(Node& n) {
    pair<int, int> p1 = state->GetPlayerPos();
    pair<int, int> p2 = n.state->GetPlayerPos();

    return p1.first == p2.first and p1.second == p2.second;
}
