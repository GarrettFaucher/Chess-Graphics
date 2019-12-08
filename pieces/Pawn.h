#ifndef FINALPROJECTMAJOR_GF_JN_PAWN_H
#define FINALPROJECTMAJOR_GF_JN_PAWN_H

#include "../ChessPiece.h"
#include <iostream>

class Pawn : public ChessPiece {
private:
    bool firstMove;
public:
    // Basic constructors from ChessPiece
    Pawn();
    Pawn(faction team, bool alive, int x, int y);

    /**
     * Overidden method to see if move is valid.
     */
    bool validMove(int boardIndex) override;
    void movePiece(int x, int y) override;
    void draw() override;
};


#endif //FINALPROJECTMAJOR_GF_JN_PAWN_H
