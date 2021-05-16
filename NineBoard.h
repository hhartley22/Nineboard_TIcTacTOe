//
// Created by Hayden on 30/8/20.
//

#ifndef ASSIGNMENT_1_NINEBOARD_H
#define ASSIGNMENT_1_NINEBOARD_H

#include <vector>
#include "BoardCoordinate.h"
#include "TicTacToe.h"
#include "GameStatus.h"

class NineBoard {
private:
    BoardCoordinate currentBoard;
    TicTacToe gameBoard[3][3];
    void switchBoard(int row, int col);
public:
    NineBoard();
    NineBoard(const NineBoard &toCopy);
    void display();
    void addMove(char player, int row, int col);
    bool isValidMove(int &r, int &c);
    char gameStatus();
    char getChar(int boardR, int boardC, int row, int col) const;
    std::vector<int> getEmptyPositions();
    BoardCoordinate getCurrentBoard() const;
};

#endif //ASSIGNMENT_1_NINEBOARD_H
