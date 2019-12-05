#ifndef FINALPROJECTMAJOR_GF_JN_ROOK_H
#define FINALPROJECTMAJOR_GF_JN_ROOK_H

#include "../ChessPiece.h"
#include <iostream>

class Rook : public ChessPiece {
public:
    // Basic constructors from ChessPiece
    Rook();
    Rook(faction team, bool alive, int x, int y);

    /**
     * Overidden method to see if move is valid.
     */
    bool validMove(int boardIndex) override;
    
    void draw() override;
};

#endif //FINALPROJECTMAJOR_GF_JN_ROOK_H
