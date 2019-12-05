#ifndef FINALPROJECTMAJOR_GF_JN_KNIGHT_H
#define FINALPROJECTMAJOR_GF_JN_KNIGHT_H

#include "../ChessPiece.h"
#include <iostream>

class Knight : public ChessPiece {
public:
    // Basic constructors from ChessPiece
    Knight();
    Knight(faction team, bool alive, int x, int y);

    /**
     * Overidden method to see if move is valid.
     */
    bool validMove(int boardIndex) override;

    void draw() override;
};


#endif //FINALPROJECTMAJOR_GF_JN_KNIGHT_H
