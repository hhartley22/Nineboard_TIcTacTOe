//
// Created by Hayden on 31/8/20.
//

#ifndef ASSIGNMENT_1_PLAYER_H
#define ASSIGNMENT_1_PLAYER_H

#include "NineBoard.h"

class Player {
public:
    virtual void getMove(NineBoard& board, char playerChar, int& r, int& c) = 0;
};


#endif //ASSIGNMENT_1_PLAYER_H
