//
// Created by Ari on 2/4/17.
//

#include "Cube.h"

Cube::Cube(int len) : cubeLen(len),
                      faces{Face(cubeLen, Cell::GREEN),  // the six faces of the cube
                             Face(cubeLen, Cell::ORANGE),
                             Face(cubeLen, Cell::RED),
                             Face(cubeLen, Cell::WHITE),
                             Face(cubeLen, Cell::YELLOW),
                             Face(cubeLen, Cell::BLUE),
                             Face(cubeLen, Cell::BLANK)} {
}

bool Cube::isUnscrambled() {
    for (int theFace=0; theFace<faceNames::FACE_COUNT; theFace++) {
        for (int xx=0; xx<cubeLen; xx++)
            for (int yy=0; yy<cubeLen; yy++)
                if (faces[theFace].get(xx,yy)!=faces[theFace].get(0,0))
                            return false;}
    return true;
}

Cube Cube::makeMove(cubeMoves theMove) {
    const int leftCol = 0;
    const int topRow = 0;
    const int rightCol = cubeLen - 1;
    const int bottomRow = cubeLen - 1;

    Cube result(*this);
    switch (theMove) {
        case LeftDown: // front left column goes down
            // shift down
            for (int yy = 0; yy < cubeLen; yy++) {
                result.faces[FRONT].put(leftCol, yy, faces[TOP].get(leftCol, yy));
                result.faces[TOP].put(leftCol, yy, faces[BACK].get(rightCol, cubeLen - 1 - yy));
                result.faces[BACK].put(rightCol, yy, faces[BOTTOM].get(leftCol, cubeLen - 1 - yy)); // the back is reversed
                result.faces[BOTTOM].put(leftCol, yy, faces[FRONT].get(leftCol, yy));
            }
            // rotate side -- see also http://stackoverflow.com/questions/42519/how-do-you-rotate-a-two-dimensional-array
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[LEFT].put(cubeLen - 1 - yy, xx, faces[LEFT].get(xx, yy));

            break;
        case RightDown: // front right column goes down
            // shift down
            for (int yy = 0; yy < cubeLen; yy++) {
                result.faces[FRONT].put(rightCol, yy, faces[TOP].get(rightCol, yy));
                result.faces[TOP].put(rightCol, yy, faces[BACK].get(leftCol, cubeLen - 1 - yy));
                result.faces[BACK].put(leftCol, yy, faces[BOTTOM].get(rightCol, cubeLen - 1 - yy)); // the back is reversed
                result.faces[BOTTOM].put(rightCol, yy, faces[FRONT].get(rightCol, yy));
            }
            // rotate side
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[RIGHT].put(cubeLen - 1 - yy, xx, faces[RIGHT].get(xx, yy));
            break;
        case TopLeft: // top row goes left
            // shift left
            for (int xx=0; xx<cubeLen; xx++) {
                result.faces[FRONT].put(xx,topRow, faces[RIGHT].get(xx,topRow));
                result.faces[RIGHT].put(xx,topRow, faces[BACK].get(xx,topRow));
                result.faces[BACK].put(xx,topRow, faces[LEFT].get(xx,topRow)); // the back is reversed
                result.faces[LEFT].put(xx,topRow, faces[FRONT].get(xx,topRow));
            }

            // rotate top
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[TOP].put(cubeLen - 1 - yy, xx, faces[TOP].get(xx, yy));
            break;
        case BottomLeft: // bottom row goes left
            // shift left
            for (int xx=0; xx<cubeLen; xx++) {
                result.faces[FRONT].put(xx,bottomRow, faces[RIGHT].get(xx,bottomRow));
                result.faces[RIGHT].put(xx,bottomRow, faces[BACK].get(xx,bottomRow));
                result.faces[BACK].put(xx,bottomRow, faces[LEFT].get(xx,bottomRow)); // the back is reversed
                result.faces[LEFT].put(xx,bottomRow, faces[FRONT].get(xx,bottomRow));
            }

            // rotate bottom
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[BOTTOM].put(cubeLen - 1 - yy, xx, faces[BOTTOM].get(xx, yy));
            break;
        default:
            throw out_of_range("ERR:  I don't know how to do that yet ... sorry!");
    }
    return result;
}
