//
// Created by Hayden on 6/9/20.
//

#ifndef ASSIGNMENT_1_MONTECARLOPLAYER_H
#define ASSIGNMENT_1_MONTECARLOPLAYER_H

#include "Player.h"

class MonteCarloPlayer: public Player {
private:
    char playerSymbol;
    double simulateGame(NineBoard board);
    double expandGame(NineBoard board, char playerChar);
public:
    void getMove(NineBoard& board, char playerChar, int& r, int& c) override;
};


#endif //ASSIGNMENT_1_MONTECARLOPLAYER_H
