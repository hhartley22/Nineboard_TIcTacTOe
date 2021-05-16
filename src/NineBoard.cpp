//
// Created by Hayden on 30/8/20.
//
#include "../includes/NineBoard.h"

#include <iostream>
#include <cstdlib>

using namespace std;

NineBoard::NineBoard() {
  int boardRow = rand()%3;
  int boardCol = rand()%3;

  this->currentBoard.row = boardRow;
  this->currentBoard.col = boardCol;
}

NineBoard::NineBoard(const NineBoard &toCopy) {
  for (int nbRow = 0; nbRow < 3; nbRow++) { //Nineboard row
    for (int nbCol = 0; nbCol < 3; nbCol++) { //Nineboard Column
      for (int tcRow = 0; tcRow < 3; tcRow++) { //TicTacToe Row
        for (int tcCol = 0; tcCol < 3; tcCol++) { //TicTacToe Column
          char toAdd = toCopy.getChar(nbRow, nbCol, tcRow, tcCol);
          if(toAdd == 'X' || toAdd == 'O') { //Only add move if the value at that location is a playerChar
            this->gameBoard[nbRow][nbCol].addMove(toAdd, tcRow, tcCol);
          }
        }
      }
    }
  }

  BoardCoordinate copiedBoardCurrent = toCopy.getCurrentBoard();

  this->currentBoard.row = copiedBoardCurrent.row;
  this->currentBoard.col = copiedBoardCurrent.col;
}

void NineBoard::display() {
  for(int i = 0; i < 3; i++) { //NineBoard Row
    //Top border of boards
    for (int c = 0; c < 3; c++) {
      if(c == currentBoard.col && i==currentBoard.row)
        cout << "  * * * * *  ";
      else
        cout << "  - - - - -  ";
    }
    cout << endl;

    for (int j = 0; j < 3; j++) { //TicTacToe Board Row
      for(int k = 0; k < 3; k++) { //Nineboard Column
        if(k == currentBoard.col && i == currentBoard.row) //Left border of boards
          cout << '*';
        else
          cout << '|';

        for(int l = 0; l < 3; l++) { //TicTacToe Board Column
          cout << ' ' << gameBoard[i][k].getCharAtPos(j, l) << ' ';
          if(l%3 < 2) //l == 0 || l == 1
            cout << '|'; //Column Separator
        } //End TicTacToe Bottom

        if(k == currentBoard.col && i == currentBoard.row) //Right border of boards
          cout << '*';
        else
          cout << '|';
      } //End Nineboard Column

      //Row separator for boards
      if(j%3 < 2) { // j==1 || j==2
        cout << endl;
        for (int r = 0; r < 3; r++) {
          if(i == currentBoard.row && r == currentBoard.col)
            cout << "* -   -   - *";
          else
            cout << "| -   -   - |";
        }
      }
      cout << endl;
    } //End TicTacToe Board Row

    //Bottom border of boards
    for (int c = 0; c < 3; c++) {
      if(c == currentBoard.col && i==currentBoard.row)
        cout << "  * * * * *  ";
      else
        cout << "  - - - - -  ";
    }
    cout << endl;
  } //End Nineboard Row
}

void NineBoard::switchBoard(int row, int col) {
  if(gameBoard[row][col].boardStatus() != 'D') {
    currentBoard.row = row;
    currentBoard.col = col;
  } else {
    row = rand()%3;
    col = rand()%3;
    switchBoard(row, col);
  }
}

void NineBoard::addMove(char player, int row, int col) {
  gameBoard[currentBoard.row][currentBoard.col].addMove(player, row, col);

  if(gameStatus() == 'C')
    switchBoard(row, col);
}

char NineBoard::gameStatus() {
  int numOfDraws = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if(gameBoard[i][j].boardStatus() == 'D')
        numOfDraws++;
      else if(gameBoard[i][j].boardStatus() != 'C')
        return gameBoard[i][j].boardStatus();
    }
  }

  if(numOfDraws >= 9)
    return 'D';
  else
    return 'C';
}

bool NineBoard::isValidMove(int &r, int &c) {
  return gameBoard[currentBoard.row][currentBoard.col].isValidMove(r, c);
}

char NineBoard::getChar(int boardR, int boardC, int row, int col) const{
  return gameBoard[boardR][boardC].getCharAtPos(row, col);
}

vector<int> NineBoard::getEmptyPositions() {
  vector<int> emptyPos;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if( gameBoard[currentBoard.row][currentBoard.col].getCharAtPos(i, j) == ' ' ) {
        emptyPos.push_back((3*i)+j);
      }
    }
  }
  random_shuffle(emptyPos.begin(), emptyPos.end());

  return emptyPos;
}

BoardCoordinate NineBoard::getCurrentBoard() const{
  return currentBoard;
}

