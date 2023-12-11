#include "pch.h"
#include "Input.h"

void Input::DisplayTutorial() {
    wcout << "Move player\n0 to North, 1 to South, 2 to East and 3 to west.\n";
}

Direction Input::Move() {
    wcout << "Move >> ";
    int direction = -1;

    while (direction < 0 || direction > 4)
        cin >> direction;
    
    if (direction == 0)
        return NORTH;
    else if (direction == 1)
        return SOUTH;
    else if (direction == 2)
        return EAST;
    else if (direction == 3)
        return WEST;

    return NORTH;
}
