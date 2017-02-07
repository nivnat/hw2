//
// Created by Ari on 2/4/17.
//

#ifndef RUBIKS_COLOR_H
#define RUBIKS_COLOR_H

#include <iostream>
/**
 * One cell of the cube
 */
class Cell {
public:
    enum color { WHITE, BLUE, YELLOW, GREEN, RED, ORANGE, BLANK };
    Cell(color theColor) : myColor(theColor) {}
    friend std::ostream& operator<<(std::ostream& os, const Cell &cell);

private:
    color myColor;
};

#endif //RUBIKS_COLOR_H
