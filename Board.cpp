#include "Board.h"

Board::Board() {
    resetBoard();
}

ChessPiece* Board::getPiece(int x, int y, faction team) {
    if (team == WHITE) {
        int index = (x * 8) + y;
        return whiteBoard[index];
    } else {
        int index = (x * 8) + y;
        return blackBoard[index];
    }
}

bool Board::getWhiteTurn() const {
    return whiteTurn;
}

void Board::setWhiteTurn(bool whiteTurn) {
    this->whiteTurn = whiteTurn;
}

void Board::resetBoard() {
    whiteBoard.clear();
    whiteBoard.resize(64);
    blackBoard.clear();
    blackBoard.resize(64);
    for (int i = 0; 64 > i; i++) {
        whiteBoard[i] = nullptr;
        blackBoard[i] = nullptr;
    }
}

void Board::setPiece(ChessPiece* piece) {
    if(piece->getTeam() == WHITE) {
        int setIndex = (piece->getX() * 8) + piece->getY();
        whiteBoard[setIndex] = piece;
    } else {
        int setIndex = (piece->getX() * 8) + piece->getY();
        blackBoard[setIndex] = piece;
    }
}

void Board::checkCollisions() {
    for (int i = 0; 64 > i; i++) {
        if (whiteBoard[i] != NULL && blackBoard[i] != NULL) {
            if (whiteTurn) {
                blackBoard[i] = NULL;
            } else {
                whiteBoard[i] = NULL;
            }
        }
    }
}

void Board::fileToBoard(std::string filename) {
    std::ifstream fIn; // Creating in files
    fIn.open(filename); // "../boards/default.csv"
    std::vector<std::string> fileContents; // Will store string representation of pieces
    if (fIn.is_open()) { // Error handling if file doesn't open
        std::string tempPiece; // Will store a line of data from CSV
        std::string piece; // Accumulates the string representation of the piece
        char comma = ',';
        while(fIn >> tempPiece) { // Loops for each line of CSV
            // Loops through the line of the CSV
            for(unsigned i = 0; tempPiece.length() > i; i++) {
                if(tempPiece.at(i) != comma) { // Makes sure the character isn't a comma
                    if(tempPiece.at(i) == '\\' && tempPiece.at(i+1) == 'n') { // Makes sure it is not a new line
                        piece = "";
                        i++;
                    } else {
                        piece += tempPiece.at(i);
                    }
                } else { // If the char is a comma it pushes the piece to the vec and clears the accumulated chars
                    fileContents.push_back(piece);
                    piece = "";
                }
            }
            fileContents.push_back(piece);
            piece = "";
        }
    } else {
        std::cout << "ERROR: File not open." << std::endl;
    }
    // This loop will create piece objects and push them to the board based on fileContents
    for (int i = 0; fileContents.size() > i; i++) {
        if (fileContents[i] != "") {
            if (fileContents[i].at(0) == 'W') {
                if (fileContents[i] == "WP") {
                    setPiece(new Pawn(WHITE, true, i / 8, i % 8));
                } else if (fileContents[i] == "WB") {
                    setPiece(new Bishop(WHITE, true, i / 8, i % 8));
                } else if (fileContents[i] == "WKG") {
                    setPiece(new King(WHITE, true, i / 8, i % 8));
                } else if (fileContents[i] == "WKN") {
                    setPiece(new Knight(WHITE, true, i / 8, i % 8));
                } else if (fileContents[i] == "WQ") {
                    setPiece(new Queen(WHITE, true, i / 8, i % 8));
                } else if (fileContents[i] == "WR") {
                    setPiece(new Rook(WHITE, true, i / 8, i % 8));
                }
            } else {
                if (fileContents[i] == "BP") {
                    setPiece(new Pawn(BLACK, true, i / 8, i % 8));
                } else if (fileContents[i] == "BB") {
                    setPiece(new Bishop(BLACK, true, i / 8, i % 8));
                } else if (fileContents[i] == "BKG") {
                    setPiece(new King(BLACK, true, i / 8, i % 8));
                } else if (fileContents[i] == "BKN") {
                    setPiece(new Knight(BLACK, true, i / 8, i % 8));
                } else if (fileContents[i] == "BQ") {
                    setPiece(new Queen(BLACK, true, i / 8, i % 8));
                } else if (fileContents[i] == "BR") {
                    setPiece(new Rook(BLACK, true, i / 8, i % 8));
                }
            }
        }
    }
    fIn.close();
}

void Board::popPiece(int x, int y, faction team) {
    if (team == WHITE) {
        int setIndex = (x * 8) + y;
        whiteBoard[setIndex] = nullptr;
    } else {
        int setIndex = (x * 8) + y;
        blackBoard[setIndex] = nullptr;
    }
}

void Board::movePieceToOption(ChessPiece* piece, int choice) {
    std::vector<int> pieceOptions = piece->getValidMoves();
    int indexToMoveTo = pieceOptions[choice-1];
    faction team = piece->getTeam();
    int x = indexToMoveTo / 8;
    int y = indexToMoveTo % 8;
    popPiece(x, y, team);
    piece->setX(x);
    piece->setY(y);
    setPiece(piece);
}

std::string Board::toString() {
    int line = 0;
    std::string outString;
    for (unsigned i = 0; whiteBoard.size() > i;  i++) {
        if (whiteBoard[i] != nullptr) {
            outString += whiteBoard[i]->toStringBoardInfo();
        } else if (blackBoard[i] != nullptr) {
            outString += blackBoard[i]->toStringBoardInfo();
        } else {
            outString += "    ";
        }

        line += 1;
        if (line == 8) {
            line = 0;
            outString += "\n";
        }
    }
    return outString;
}