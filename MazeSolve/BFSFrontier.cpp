#include "pch.h"
#include "BFSFrontier.h"

BFSFrontier::BFSFrontier() {
    _frontier = {  };
}

Node* BFSFrontier::RemoveNode() {
    if (_frontier.empty())
        return nullptr;

    vector<Node*>::iterator i;

    Node* node = _frontier.front();
    _frontier.erase(i);
    return node;
}
