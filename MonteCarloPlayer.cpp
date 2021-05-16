//
// Created by Hayden on 6/9/20.
//

#include "MonteCarloPlayer.h"
#include <iostream>

using namespace std;

const int SIMULATION_TIMES = 1000;

void MonteCarloPlayer::getMove(NineBoard& board, char playerChar, int& r, int& c) {
  cout << "Player " << playerChar << " move: " << endl;

  playerSymbol = playerChar;

  vector<int> emptyPos = board.getEmptyPositions();

  double highestUtility = -1.0;

  for (int i = 0; i < emptyPos.size(); i++) {
    int x = emptyPos.at(i) / 3;
    int y = emptyPos.at(i) % 3;

    NineBoard tempBoard(board);
    tempBoard.addMove(playerSymbol, x, y);

    double utility = simulateGame(tempBoard);

    if(utility > highestUtility) {
      highestUtility = utility;

      r = x;
      c = y;
    }

  }

  cout << "Monte Carlo Utility: " << highestUtility << endl;
}

double MonteCarloPlayer::simulateGame(NineBoard board) {

  char playerChar;
  if(playerSymbol == 'X')
    playerChar = 'O';
  else
    playerChar = 'X';

  double winningChance = 0.0;

  for (int i = 0; i < SIMULATION_TIMES; i++) {
    NineBoard temporaryBoard(board);
    winningChance += expandGame(temporaryBoard, playerChar);
  }

  return winningChance/SIMULATION_TIMES;
}

double MonteCarloPlayer::expandGame(NineBoard board, char playerChar) {
  if (board.gameStatus() == playerSymbol) {
    //cout << "Win!" << endl;
    return 1.0;
  }else if(board.gameStatus() == 'D') {
    //cout << "Draw!" << endl;
    return 0.5;
  } else if(board.gameStatus() != 'C') {
    //cout << "Loss!" << endl;
    return 0;
  }

  vector<int> emptyCells = board.getEmptyPositions();
  int index = emptyCells[rand() % emptyCells.size()];
  int row = index/3;
  int col = index%3;
  emptyCells.clear();
  board.addMove(playerChar, row, col);

  if(playerChar == 'X')
    playerChar = 'O';
  else
    playerChar = 'X';

  return expandGame(board, playerChar);
}
