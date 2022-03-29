#include "board.h"
#include <iostream>

using namespace std;

Board::Board() {
    doInitialize();
}

Board::~Board() {

}

void Board::doInitialize() {
    m_numOfProcess = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            m_board[i][j] = 0;
        }
    }
}

char Board::convertNumberToOX(int input) {
    if (input == 0) {
        return ' ';
    } else if (input == 1) {
        return 'O';
    } else if (input == -1) {
        return 'X';
    } else {
        cout << "Invalid input format" << endl;
        return 'N';
    }
}

void Board::showCurrentBoard() {
    // 0|0|0
    // -----
    // 0|0|0
    // -----
    // 0|0|0
    for (int i=0; i<5; i++) {
        if (i % 2 == 1) {
            cout << "-----";
        } else {
            for (int j=0; j<5; j++) {
                if (j % 2 == 1) {
                    cout << "|";
                } else {
                    cout << convertNumberToOX(m_board[i/2][j/2]);
                }
            }
        }
        cout << endl;
    }
}

// return 1: Find winner!
// return 0: Keep playing!
int Board::didWin() {
    // find row
    for (int i=0; i<3; i++) {
        if (m_board[i][0] != 0 && m_board[i][0] == m_board[i][1] && m_board[i][1] == m_board[i][2]) {
            return didFindWinner;
        }
    }
    // find column
    for (int i=0; i<3; i++) {
        if (m_board[0][i] != 0 && m_board[0][i] == m_board[1][i] && m_board[1][i] == m_board[2][i]) {
            return didFindWinner;
        }        
    }

    // find diagonal 
    if (m_board[0][0] != 0 && m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2]) {
        return didFindWinner;
    }

    if (m_board[2][0] != 0 && m_board[2][0] == m_board[1][1] && m_board[1][1] == m_board[0][2]) {
        return didFindWinner;
    }
    return 0;
}

// return 1: Find winner!
// return -1: Invalid input, try again!
int Board::updateBoard(int x, int y) {
    if (x < 0 || x >=3 || y < 0 || y >= 3) {
        cout << "Out of index on the board. index: " << x << " " << y << endl;
        cout << "Please try again" << endl;
        return -1;
    }

    if (m_numOfProcess > 9) {
        cout << "Unable to play anymore" << endl;
        return -2;
    }

    if (m_board[x][y] == 1 || m_board[x][y] == -1) {
        cout << "Invalid index: " << x << ", " << y << endl;
        return -1;
    }

    if (m_numOfProcess % 2 == 0) {
        m_board[x][y] = 1;
    } else {
        m_board[x][y] = -1;
    }

    if (didWin() == didFindWinner) {
        return didFindWinner; // didFindWinner
    }
    m_numOfProcess++;
    return 0;
}

int Board::getNumOfProcess() {
    return m_numOfProcess;
}

int Board::getDidFindwinner() {
    return didFindWinner;
}
