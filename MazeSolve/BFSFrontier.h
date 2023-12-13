#pragma once
#include <DFSFrontier.h>

class BFSFrontier : public DFSFrontier {
public:
    BFSFrontier();

    virtual Node* RemoveNode() override;
};

