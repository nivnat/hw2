//
// Created by Ari on 2/5/17.
//


// FACE
#include <ostream>
#include "Cube.h"

/**
 * Concatenates 4 faces to the output stream
 */
void  concatFaces(std::ostream& os, const Cube &cube,
                 const faceNames& face1,
                 const faceNames& face2=BLANK,
                 const faceNames& face3=BLANK,
                 const faceNames& face4=BLANK) {

    for (int xx=0; xx<cube.getLen(); xx++)
        os << cube.getFace(face1).printYY(xx) << " "
           << cube.getFace(face2).printYY(xx) << " "
           << cube.getFace(face3).printYY(xx) << " "
           << cube.getFace(face4).printYY(xx) << " "
           << endl;
}

std::ostream& operator<<(std::ostream& os, const Cube &cube) {
    // output the cube
    concatFaces(os, cube, BLANK, TOP); os << endl;
    concatFaces(os, cube, LEFT, FRONT, RIGHT, BACK); os << endl;
    concatFaces(os, cube, BLANK, BOTTOM); os << endl;

    return os;
}

// CELL
std::ostream& operator<<(std::ostream& os, const Cell &cell) {
    switch (cell.myColor) {
        case Cell::WHITE:     os << 'W'; break;
        case Cell::BLUE:      os << 'B'; break;
        case Cell::YELLOW:    os << 'Y'; break;
        case Cell::GREEN:     os << 'G'; break;
        case Cell::RED:       os << 'R'; break;
        case Cell::ORANGE:    os << 'O'; break;
        default: // render as blank
            os << ' ';
    }
    return os;
}