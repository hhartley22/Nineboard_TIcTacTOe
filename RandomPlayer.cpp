//
// Created by Hayden on 3/9/20.
//

#include "RandomPlayer.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void RandomPlayer::getMove(NineBoard& board, char playerChar, int& r, int& c) {
  cout << "Player " << playerChar << " move: " << endl;

  do{
    r = (rand() % 3);
    c = (rand() % 3);

  } while( !board.isValidMove(r, c) );
}