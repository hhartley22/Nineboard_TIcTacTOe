//
// Created by Hayden on 17/8/20.
//
#include "TicTacToe.h"

#include <iostream>

using namespace std;

TicTacToe::TicTacToe() {
  //Initial values
  this->numOfMoves = 0;

  //Initialize array (set default values)
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      this->board[i][j] = ' ';
    }
  }
}

void TicTacToe::addMove(char player, int r, int c) {
  this->board[r][c] = player;
  this->numOfMoves++;
}

bool TicTacToe::isValidMove(int r, int c) {
  bool rowInBounds = (r >= 0) && (r <= 2);
  bool colInBounds = (c >= 0) && (c <= 2);

  if(rowInBounds && colInBounds) {
    if(this->board[r][c] == ' ') {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

char TicTacToe::boardStatus() {
  //Check Rows
  for (int i = 0; i < 3; i++) {
    if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
      return board[i][0];
  }

  // Check Columns
  for (int i = 0; i < 3; i++) {
    if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
      return board[0][i];
  }

  /* CHECK DIAGONALS */
  // Left-To-Right
  if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return board[0][0];

  //Right-To-Left
  if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0] )
    return board[0][2];

  if (this->numOfMoves >= 9) {
    return 'D';
  } else {
    return 'C';
  }
}

char TicTacToe::getCharAtPos(int r, int c) const{
  return board[r][c];
}
