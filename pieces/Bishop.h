#ifndef FINALPROJECTMAJOR_GF_JN_BISHOP_H
#define FINALPROJECTMAJOR_GF_JN_BISHOP_H

#include "../ChessPiece.h"
#include <iostream>

class Bishop : public ChessPiece {
public:
    // Basic constructors from ChessPiece
    Bishop();
    Bishop(faction team, bool alive, int x, int y);

    /**
     * Overidden method to see if move is valid.
     */
    bool validMove(int boardIndex) override;
};


#endif //FINALPROJECTMAJOR_GF_JN_BISHOP_H
