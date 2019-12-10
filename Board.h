#ifndef FINALPROJECTMAJOR_GF_JN_BOARD_H
#define FINALPROJECTMAJOR_GF_JN_BOARD_H

#include "ChessPiece.h"
#include "pieces/King.h"
#include "pieces/Queen.h"
#include "pieces/Bishop.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "Button.h"
#include <algorithm>
#include <vector>
#include <string>
#include <optional>
#include <memory>
#include <fstream>
#include <iostream>


class Board {
private:
    std::vector<ChessPiece*> whiteBoard;
    std::vector<ChessPiece*> blackBoard;
    std:: vector<Button> squares;
    bool whiteTurn = true;
public:
    Board();

    /**
     * Returns a pointer to a chess piece at given coords.
     */
    ChessPiece* getPiece(int x, int y, faction team);

    /**
     * Gets turns status
     * @return true if it is white teams turn
     */
    bool getWhiteTurn() const;


    /**
     * Sets turn status
     * @param whiteTurn bool with white turn as true
     */
    void setWhiteTurn(bool whiteTurn);

    /**
     * Sets all of board to nullptr
     */
    void resetBoard();
    /**
     * Sets piece to be in a certain location based on its x, y value.
     * Converts x, y into index for vector.
     * @param piece
     */
    void setPiece(ChessPiece* piece);

    /**
     * Checks to see if a piece of both teams overlaps.
     * Keeps the piece from the current moving team.
     */
    void checkCollisions();

    /**
     * fileToBoard takes a filename that corresponds to a CSV file and converts
     * the contents of a CSV file to a board. An example of a row of black pieces
     * would be represented by the line:
     * BR,BKN,BB,BQ,BKG,BB,BKN,BR
     * @param filename directory and name of file
     */
    void fileToBoard(std::string filename);
    /**
     * Sets vector point to nullptr
     * @param x
     * @param y
     */
    void popPiece(int x, int y, faction team);

    void movePieceToOption(ChessPiece* piece, int choice);

    /**
     * CleanValidMoves takes the coordinates and faction of a team and returns
     * a vector of moves that a piece can move to by its ruleset and takes away the
     * indices where an allied piece stands.
     * @param x
     * @param y
     * @param team
     * @return vector of board indicies where validMove for piece and not on allied team space
     */
    std::vector<int> cleanValidMoves(int x, int y, faction team);

    /**
     * Returns a string of the board for printing purposes
     * @return string of board
     */
    std::string toString();

    /**
     * Draws the squares of a chess board
     */
     void draw();

     std::vector<Button>* getSquares();

};


#endif //FINALPROJECTMAJOR_GF_JN_BOARD_H
