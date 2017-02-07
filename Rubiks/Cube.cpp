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

Cube Cube::makeMove(cubeMoves theMove) {
    Cube result(*this);
    switch (theMove) {
        case LeftDown: // front left column goes down
            // shift down
            for (int yy = 0; yy < cubeLen; yy++) {
                result.faces[FRONT].put(0, yy, faces[TOP].get(0, yy));
                result.faces[TOP].put(0, yy, faces[BACK].get(cubeLen - 1, cubeLen - 1 - yy));
                result.faces[BACK].put(cubeLen - 1, yy, faces[BOTTOM].get(0, cubeLen - 1 - yy)); // the back is reversed
                result.faces[BOTTOM].put(0, yy, faces[FRONT].get(0, yy));
            }
            // rotate side -- see also http://stackoverflow.com/questions/42519/how-do-you-rotate-a-two-dimensional-array
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[LEFT].put(cubeLen - 1 - yy, xx, faces[LEFT].get(xx, yy));

            break;
        case LeftUp: // front left column goes up
            // shift up
            for (int yy=0; yy<cubeLen; yy++) {
                result.faces[FRONT].put(0, yy, faces[BOTTOM].get(0, yy));
                result.faces[BOTTOM].put(0, yy, faces[BACK].get(cubeLen - 1, cubeLen - 1 - yy));
                result.faces[BACK].put(cubeLen - 1, yy, faces[TOP].get(0, cubeLen - 1 - yy)); // the back is reversed
                result.faces[TOP].put(0, yy, faces[FRONT].get(0, yy));
            }
            // rotate side
            for (int xx=0; xx<cubeLen; xx++)
                for (int yy=0; yy<cubeLen; yy++)
                    result.faces[LEFT].put(xx,yy,faces[LEFT].get(cubeLen-1-yy,xx));
            break;
        case TopLeft: // top row goes left
            // shift left
            for (int xx=0; xx<cubeLen; xx++) {
                result.faces[FRONT].put(xx,0, faces[RIGHT].get(xx,0));
                result.faces[RIGHT].put(xx,0, faces[BACK].get(xx,0));
                result.faces[BACK].put(xx,0, faces[LEFT].get(xx,0)); // the back is reversed
                result.faces[LEFT].put(xx,0, faces[FRONT].get(xx,0));
            }

            // rotate top
            for (int xx = 0; xx < cubeLen; xx++)
                for (int yy = 0; yy < cubeLen; yy++)
                    result.faces[TOP].put(cubeLen - 1 - yy, xx, faces[TOP].get(xx, yy));
    }
    return result;
}
