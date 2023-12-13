#include "pch.h"
#include "BFSFrontier.h"

BFSFrontier::BFSFrontier() {
    _frontier = {  };
}

Node* BFSFrontier::RemoveNode() {
    if (_frontier.empty())
        return nullptr;

    Node* node = _frontier.front();
    _frontier.pop_front();
    return node;
}

bool BFSFrontier::IsEmpty() {
    return _frontier.empty();
}

void BFSFrontier::AddNode(Node* n) {
    _frontier.emplace_back(n);
}