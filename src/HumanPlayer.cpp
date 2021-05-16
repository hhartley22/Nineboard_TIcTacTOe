//
// Created by Hayden on 3/9/20.
//

#include "../includes/HumanPlayer.h"

#include <iostream>

using namespace std;

void HumanPlayer::getMove(NineBoard& board, char playerChar, int& r, int& c) {

  cout << "Player " << playerChar << " move: " << endl;
  board.display();

  do{
    cout << "Player " << playerChar << " enter move: ";
    cin >> r >> c;

    r--;
    c--;
  } while( !board.isValidMove(r, c) );
}