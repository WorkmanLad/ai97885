#include "pch.h"
#include "DFSFrontier.h"

DFSFrontier::DFSFrontier() {
    _frontier = {  };
}

bool DFSFrontier::IsEmpty() {
    return _frontier.empty();
}

bool DFSFrontier::ContainsState(Node* node) {
    for (int i = 0; i < _frontier.size(); ++i)
        if (*_frontier[i] == *node)
            return true;

    return false;
}

void DFSFrontier::AddNode(Node* node) {
    _frontier.emplace_back(node);
}

Node* DFSFrontier::RemoveNode() {
    if (_frontier.empty())
        return nullptr;

    Node* node = _frontier.back();
    _frontier.pop_back();
    return node;
}

