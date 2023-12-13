#pragma once
class Node;

class Frontier {
public:
    virtual bool IsEmpty() = 0;
    virtual void AddNode(Node*) = 0;
    virtual Node* RemoveNode() = 0;
};
