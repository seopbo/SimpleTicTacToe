#pragma once
#include <iostream>

using namespace std;

class Board {
    private:
        int didFindWinner = 1;
        int m_board[3][3];
        int m_numOfProcess;
        char convertNumberToOX(int input);
        int didWin();
    public:
        Board();
        ~Board();
        void doInitialize();
        void showCurrentBoard();
        int updateBoard(int x, int y);
        int getNumOfProcess();
        int getDidFindwinner();
};
