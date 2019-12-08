#ifndef FINALPROJECTMAJOR_GF_JN_CHESSPIECE_H
#define FINALPROJECTMAJOR_GF_JN_CHESSPIECE_H

#include <vector>
#include <string>
#include "Quad.h"
#include <iostream>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

enum pieceType {PAWN, KING, KNIGHT, BISHOP, ROOK, QUEEN};
enum faction {BLACK, WHITE};

class ChessPiece {
protected:
    pieceType type;
    faction team;
    bool alive;
    int x;
    int y;
    std::vector<int> validMoves;
public:
    /**
     * Default constructor for ChessPiece
     * Sets:
     * type to PAWN
     * team to BLACK
     * alive to true
     * x to 0
     * y to 0
     */
    ChessPiece();
    /**
     * Constructor for ChessPiece with specifics
     * @param piece sets type
     * @param team sets team
     * @param alive sets alive
     * @param x sets x
     * @param y sets y
     */
    ChessPiece(pieceType piece, faction team, bool alive, int x, int y);


    /**
     * Gets the type of the piece
     * @return the type of the piece
     */
    pieceType getType() const;
    /**
     * Gets the team of the piece
     * @return the team of the piece
     */
    faction getTeam() const;
    /**
     * Gets the alive status of the piece
     * @return the alive status of the piece
     */
    bool getAlive() const;
    /**
     * Gets the x of the piece
     * @return the x of the piece
     */
    int getX() const;
    /**
     * Gets the y of the piece
     * @return the y of the piece
     */
    int getY() const;
    //TODO comment
    std::vector<int> getValidMoves() const;

    /**
     * Sets the type
     * @param type
     */
    void setType(pieceType type);
    /**
     * Sets the team
     * @param team
     */
    void setTeam(faction team);
    /**
     * Sets the alive status
     * @param alive
     */
    void setAlive(bool alive);
    /**
     * Sets the x
     * @param x
     */
    void setX(int x);
    /**
     * Sets the y
     * @param y
     */
    void setY(int y);

    /**
     * Prints the info of the chess piece to cout
     */
    void printChessPiece() const;
    /**
     * Creates a string that represents the piece
     * @return string to be displayed one the board
     */
    std::string toStringBoardInfo() const;
    // TODO comment
    std::string toStringValidMoves() const;

    /**
     * Changes x and y coords together
     * @param x
     * @param y
     */
    virtual void movePiece(int x, int y);

    void moveToValidMove(int index);

    /**
     * The index that a ChessPiece should be at in a vector is calculated
     * from a ChessPiece's coordinates stored in the object.
     * @return int that is where its index would be
     */
    int getBoardIndex();

    int indexToX(int index) const;

    int indexToY(int index) const;

    /**
     * validMove is a virtual method that needs to be implemented in other classes
     * Determines if a piece can move to given coords
     * @param x
     * @param y
     * @return true if it can make the move
     */
    virtual bool validMove(int boardIndex) = 0;

    /**
    * Populates validMoves vector with any indicies that the piece can move to.
    */
    virtual void findValidMoves();

    /**
     * Draw is a virtual method that needs to be implemented in child classes
     * draws the ChessPiece through openGL
     */
    virtual void draw() = 0;
};


#endif //FINALPROJECTMAJOR_GF_JN_CHESSPIECE_H
