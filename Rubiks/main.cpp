#include <iostream>
#include "Cube.h"

int main() {
    Cube test(3);                 // create a cube
    test=test.makeMove(LeftDown); // make a move
    cout << test << endl;         // print out the result
    return 0;
}