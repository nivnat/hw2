//
// Created by Ari on 2/4/17.
//

#include <stdexcept>
#include "Cube.h"

Cube::Cube(int len) : cubeLen(len) {
    faces.clear(); // the six faces of the cube
    faces.push_back(Face(cubeLen, Cell::GREEN));
    faces.push_back(Face(cubeLen, Cell::ORANGE));
    faces.push_back(Face(cubeLen, Cell::RED));
    faces.push_back(Face(cubeLen, Cell::WHITE));
    faces.push_back(Face(cubeLen, Cell::YELLOW));
    faces.push_back(Face(cubeLen, Cell::BLUE));
    faces.push_back(Face(cubeLen, Cell::BLANK));
}

bool Cube::isUnscrambled() const {
    for (int theFace=0; theFace<FACE_COUNT; theFace++) {
        for (int xx=0; xx<cubeLen; xx++)
            for (int yy=0; yy<cubeLen; yy++)
                if (faces[theFace].get(xx,yy)!=faces[theFace].get(0,0))
                            return false;}
    return true;
}

Cube Cube::makeMove(cubeMoves theMove) const {
    const int leftCol = 0;
    const int topRow = 0;
    const int rightCol = cubeLen - 1;
    const int bottomRow = cubeLen - 1;

    Cube result(*this);
    switch (theMove) {
        case LeftDown: // front left column goes down
            // shift down
            for (int yy = 0; yy < cubeLen; yy++) {
                result.faces[FRONT].set(leftCol, yy, faces[TOP].get(leftCol, yy));
                result.faces[TOP].set(leftCol, yy, faces[BACK].get(rightCol, cubeLen - 1 - yy));
                result.faces[BACK].set(rightCol, yy, faces[BOTTOM].get(leftCol, cubeLen - 1 - yy)); // the back is reversed
                result.faces[BOTTOM].set(leftCol, yy, faces[FRONT].get(leftCol, yy));
            }
            // rotate side -- see also http://stackoverflow.com/questions/42519/how-do-you-rotate-a-two-dimensional-array
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[LEFT].set(cubeLen - 1 - yy, xx, faces[LEFT].get(xx, yy));

            break;
        case RightDown: // front right column goes down
            // shift down
            for (int yy = 0; yy < cubeLen; yy++) {
                result.faces[FRONT].set(rightCol, yy, faces[TOP].get(rightCol, yy));
                result.faces[TOP].set(rightCol, yy, faces[BACK].get(leftCol, cubeLen - 1 - yy));
                result.faces[BACK].set(leftCol, yy, faces[BOTTOM].get(rightCol, cubeLen - 1 - yy)); // the back is reversed
                result.faces[BOTTOM].set(rightCol, yy, faces[FRONT].get(rightCol, yy));
            }
            // rotate side
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[RIGHT].set(cubeLen - 1 - yy, xx, faces[RIGHT].get(xx, yy));
            break;
        case TopLeft: // top row goes left
            // shift left
            for (int xx=0; xx<cubeLen; xx++) {
                result.faces[FRONT].set(xx, topRow, faces[RIGHT].get(xx, topRow));
                result.faces[RIGHT].set(xx, topRow, faces[BACK].get(xx, topRow));
                result.faces[BACK].set(xx, topRow, faces[LEFT].get(xx, topRow)); // the back is reversed
                result.faces[LEFT].set(xx, topRow, faces[FRONT].get(xx, topRow));
            }

            // rotate top
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[TOP].set(cubeLen - 1 - yy, xx, faces[TOP].get(xx, yy));
            break;
        case BottomLeft: // bottom row goes left
            // shift left
            for (int xx=0; xx<cubeLen; xx++) {
                result.faces[FRONT].set(xx, bottomRow, faces[RIGHT].get(xx, bottomRow));
                result.faces[RIGHT].set(xx, bottomRow, faces[BACK].get(xx, bottomRow));
                result.faces[BACK].set(xx, bottomRow, faces[LEFT].get(xx, bottomRow)); // the back is reversed
                result.faces[LEFT].set(xx, bottomRow, faces[FRONT].get(xx, bottomRow));
            }

            // rotate bottom
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[BOTTOM].set(cubeLen - 1 - yy, xx, faces[BOTTOM].get(xx, yy));
            break;
        default:
            throw out_of_range("ERR:  I don't know how to do that yet ... sorry!");
    }
    return result;
}
