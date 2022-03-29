#pragma once
#include <iostream>

using namespace std;

class Player {
    private:
        string m_userName;
    public:
        Player(string name);
        string getUsername();
};
