//
// Created by Ari on 2/5/17.
//

#ifndef RUBIKS_FACE_H
#define RUBIKS_FACE_H

#include <vector>
#include <sstream>
#include "Cell.h"

using namespace std;

    class Face {
    public:
        // CONSTRUCTORS / COPY
        /**
         * Represents one [len] x [len] face of a cube.
         * @param len The linear dimension of the face.
         */
        Face(int len, Cell::color theColor) : faceLen(len) {
            cells.resize (len, vector< Cell > (len, theColor));
        }

        Face& operator=(const Face& rhs) {
            cells=rhs.cells;
            faceLen=rhs.faceLen;
            return *this;
        }

        // ACCESSORS / SETTERS
        /**
         * Gets a cell on the face
         * @param xx x-coordinate of the cell
         * @param yy y-coordinate of the cell
         * @return
         */
        Cell get(int xx, int yy) const { return cells[xx][yy];}

        /**
         * Change a cell on the face
         * @param xx  x-coordinate of the cell
         * @param yy  y-coordinate of the cell
         * @param newCell The new contents to put into the cell
         */
        void set(int xx, int yy, Cell newCell) { cells[xx][yy]=newCell; }

        /**
         * Accessor for faceLen
         */
         int length() const { return faceLen; }

        // INFORMATIONAL
        /**
         * @param yy the yy-row of the face to return, between 0 and faceLen-1 inclusive
         * @return a human-readable string representing a row of the face
         */
        string printYY(int yy) const {
            stringstream result;
            for (int xx=0; xx<faceLen; xx++)
                result << get(xx,yy) << " ";
            return result.str();
        }
    private:
        vector < vector < Cell > > cells; /** cells on the face. */
        int faceLen; /** linear dimension of the face */
    };

#endif //RUBIKS_FACE_H
