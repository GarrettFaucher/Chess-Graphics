#ifndef FINALPROJECTMAJOR_GF_JN_KING_H
#define FINALPROJECTMAJOR_GF_JN_KING_H

#include "../ChessPiece.h"
#include <iostream>

class King : public ChessPiece {
private:
    bool inCheck;
public:
    // Basic constructors from ChessPiece
    King();
    King(faction team, bool alive, int x, int y);

    /**
     * @return bool if piece is in check
     */
    bool getInCheck() const;
    /**
     * @param inCheck bool value if piece is in check
     */
    void setInCheck(bool inCheck);

    /**
    * Overidden method to see if move is valid.
    */
    bool validMove(int boardIndex) override;
};


#endif //FINALPROJECTMAJOR_GF_JN_KING_H
