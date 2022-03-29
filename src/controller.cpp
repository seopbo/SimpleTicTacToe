#include <iostream>
#include "controller.h"
#include "board.h"
#include "player.h"

using namespace std;

Controller::Controller() {
    cout << "Welcome to tic tac toe game world!" << endl;
    doInitialize();
}

Controller::~Controller() {
    cout << "See you later!" << endl;
    delete m_board;
    delete m_p1;
    delete m_p2;
}

void Controller::doInitialize() {
    string p1UserName;
    string p2UserName;
    cout << "Please enter 1P name" << endl;
    cin >> p1UserName;
    m_p1 = new Player(p1UserName);

    cout << "Please enter 2p name" << endl;
    cin >> p2UserName;
    m_p2 = new Player(p2UserName);
    m_board = new Board();
}

string Controller::getCurrentUsername() {
    if (m_board->getNumOfProcess() % 2 == 0) {
        return m_p1->getUsername();
    } else {
        return m_p2->getUsername();
    }
}


void Controller::startPlay() {
    int x, y, ret = 0;
    while (true) {
        m_board->showCurrentBoard();
        cout << "Now " << getCurrentUsername() << "'s turn" << endl;
        cin >> x >> y;

        ret = m_board->updateBoard(x, y);
        if (ret == m_board->getDidFindwinner()) {
            break;
        }
    }
    cout << "CONGRATULATION! " << getCurrentUsername() << " Won!" << endl;
    m_board->showCurrentBoard();
}
