//
// Created by Ari on 2/4/17.
//

#ifndef RUBIKS_CUBE_H
#define RUBIKS_CUBE_H

#include <vector>
#include <sstream>
#include "Cell.h"
#include "Face.h"

using namespace std;

/**
* Faces of the cube, from the perspective of someone looking at the front of the cube.
*/
enum faceNames {
    FRONT, LEFT, RIGHT, TOP, BOTTOM, BACK,
    BLANK,       // a black face
    FACE_COUNT // a placeholder that maintains the number of faces
};

/**
 * The types of moves that can be made on the cube.
 */
enum cubeMoves {
    LeftDown, LeftUp,
    RightDown, RightUp,
    TopLeft, TopRight,
    BottomLeft, BottomRight,
    OverLeft, OverRight,
    OverFarLeft, OverFarRight,
    MOVE_COUNT // a placeholder that maintains the number of moves
};

/**
 * Represents a configuration of a Rubik's cube.  The cube represents an
 * immutable three-dimensional n x n x n structure, where n is specified
 * in the constructor.
 */
class Cube {
public:

    // Constructors
    /**
     * Constructs a [len] x [len] x [len] cube in standard coloring order.
     * @param len The linear length of any cube size.
     */
    Cube(int len);

    // Manipulators
    /**
     * Makes a move and returns the corresponding cube
     * @param theMove the move to make
     * @return a new cube representing the given move from the current cube.
     */
    Cube makeMove(cubeMoves theMove);

    // Informational

    /**
     *
     * @return true iff the cube is in its original form (i.e. each face has
     * only cells of one color.
     */
    bool isUnscrambled();

    /**
     * @return The linear length of the cube.
     */
    int getLen() const { return cubeLen; }

    /**
     * @param theFace the name of the face to return
     * @return a specific face of the cube
     */
    const Face &getFace(faceNames theFace) const { return faces[theFace]; }

    /**
     * Sets the face of a cube to the given fase
     * Note:  no checking is done that this is still a valid Rubk cube!
     * @param theFace the name of the face to change
     * @param newFace the new version of the face
     */
    void setFace(faceNames theFace, Face newFace) { faces[theFace]=newFace; }

    /**
     * Copy assignment operator
     */
    Cube& operator=(const Cube &rhs) {
        if (this!= &rhs) {
            cubeLen = rhs.cubeLen;
            for (int ii=0; ii<FACE_COUNT; ii++)
                faces[ii] = rhs.faces[ii];
        }
        return *this;
    }

private:

    // FIELDS
    int cubeLen; // linear dimension of one side

    /** the faces of the cube */
    Face faces[FACE_COUNT];


};

// public methods
// ... stream output
std::ostream &operator<<(std::ostream &os, const Cube &cube);

#endif //RUBIKS_CUBE_H
