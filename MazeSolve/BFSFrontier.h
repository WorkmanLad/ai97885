#pragma once
#include <Frontier.h>

class BFSFrontier : public Frontier {
public:
    BFSFrontier();

    bool IsEmpty() override;
    void AddNode(Node*) override;
    virtual Node* RemoveNode() override;

private:
    deque<Node*> _frontier;

   
};
