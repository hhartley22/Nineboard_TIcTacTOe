//
// Created by Hayden on 31/8/20.
//
#include "NBGame.h"

#include <iostream>

using namespace std;

NBGame::NBGame(Player* player1, Player* player2) {
  players[0] = player1;
  players[1] = player2;
}

void NBGame::play() {

  char currentPlayer = 'X';
  int r, c;

  while(game.gameStatus() == 'C') {
    if(currentPlayer == 'X') {
      players[0]->getMove(game, currentPlayer, r, c);
      game.addMove(currentPlayer, r, c);
      game.display();
      currentPlayer = 'O';
    } else {
      players[1]->getMove(game, currentPlayer, r, c);
      game.addMove(currentPlayer, r, c);
      game.display();
      currentPlayer = 'X';
    }
  }

  if(game.gameStatus() == 'D')
    cout << "The game is a draw!" << endl;
  else
    cout << "Player " << game.gameStatus() << " has won!" << endl;

  game.display();
}