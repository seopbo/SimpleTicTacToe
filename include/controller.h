#pragma once
#include <iostream>
#include "board.h"
#include "player.h"

using namespace std;

class Controller {
    private:
        Board *m_board;
        Player *m_p1;
        Player *m_p2;        
    public:
        Controller();
        ~Controller();
        void doInitialize();
        void startPlay();
        string getCurrentUsername();
};
