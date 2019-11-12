#ifndef FINALPROJECTMAJOR_GF_JN_QUEEN_H
#define FINALPROJECTMAJOR_GF_JN_QUEEN_H

#include "../ChessPiece.h"
#include <iostream>

class Queen : public ChessPiece {
public:
    // Basic constructors from ChessPiece
    Queen();
    Queen(faction team, bool alive, int x, int y);

    /**
     * Overidden method to see if move is valid.
     */
    bool validMove(int boardIndex) override;
};


#endif //FINALPROJECTMAJOR_GF_JN_QUEEN_H
