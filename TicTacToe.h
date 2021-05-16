//
// Created by Hayden on 17/8/20.
//
#ifndef PRAC4_TICTACTOE_H
#define PRAC4_TICTACTOE_H

class TicTacToe {
private:
    char board[3][3];
    int numOfMoves;
public:
    TicTacToe();
    void addMove(char player, int r, int c);
    bool isValidMove(int r, int c);
    char getCharAtPos(int r, int c) const;
    char boardStatus();
};

#endif //PRAC4_TICTACTOE_H
