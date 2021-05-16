//
// Created by Hayden on 31/8/20.
//

#ifndef ASSIGNMENT_1_NBGAME_H
#define ASSIGNMENT_1_NBGAME_H

#include "NineBoard.h"
#include "Player.h"
#include "RandomPlayer.h"

class NBGame {
private:
    NineBoard game;
    Player *players[2] = {};
public:
    NBGame(Player* player1, Player* player2);
    void play();
};


#endif //ASSIGNMENT_1_NBGAME_H
