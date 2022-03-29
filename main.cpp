#include <iostream>
#include "controller.h"

using namespace std;

int main() {
    Controller *c = new Controller();
    c->startPlay();
    delete c;
    return 0;
}
