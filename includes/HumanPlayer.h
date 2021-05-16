//
// Created by Hayden on 3/9/20.
//

#ifndef ASSIGNMENT_1_HUMANPLAYER_H
#define ASSIGNMENT_1_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer: public Player {
public:
    void getMove(NineBoard& board, char playerChar, int& r, int& c) override;
};


#endif //ASSIGNMENT_1_HUMANPLAYER_H
