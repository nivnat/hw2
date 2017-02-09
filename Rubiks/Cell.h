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
    color getColor() const { return myColor; }
    bool operator==(const Cell& other) const {return getColor()==other.getColor();}
    bool operator!=(const Cell& other) const {return !operator==(other);}
    friend std::ostream& operator<<(std::ostream& os, const Cell &cell);

private:
    color myColor;
};

#endif //RUBIKS_COLOR_H
