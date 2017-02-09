#include <iostream>
#include "Cube.h"

int main() {
    srand(time(0));
    Cube test(3);
    cout << "Unscrambled: " << test.isUnscrambled() << endl;
    for (int ii=0; ii<20; ii++) {
        int theMove;
        bool repeat;
        do {
            repeat=false;
            try {
                theMove = rand() % cubeMoves::MOVE_COUNT;
                test = test.makeMove(static_cast<cubeMoves>(theMove));
            } catch(exception e) {
                repeat=true;
            }
        } while (repeat);
        cout << theMove << endl << test << endl << "---" << endl;
    }
    cout << "Unscrambled: " << test.isUnscrambled() << endl;

    return 0;
}