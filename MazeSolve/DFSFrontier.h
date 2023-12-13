#pragma once
#include <pch.h>
#include <Node.h>
#include <Frontier.h>

class DFSFrontier : public Frontier {
public:
    DFSFrontier();

    virtual bool IsEmpty() override;
    virtual bool ContainsState(Node*) override;
    virtual void AddNode(Node*) override;
    virtual Node* RemoveNode() override;
};
