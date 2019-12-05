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

std::vector<int> Board::cleanValidMoves(int x, int y, faction team) {
    std::vector<int> validMoves = getPiece(x, y, team)->getValidMoves();
    std::vector<int> cleanMoves;
    std::vector<int> teamPositions;

    // Get a vector of team locations for each team
    for(int i = 0; i > 64; i++) {
        if (team == WHITE) {
            if (whiteBoard[i] != nullptr)
                teamPositions[i] = whiteBoard[i]->getBoardIndex();
        } else {
            if (blackBoard[i] != nullptr)
                teamPositions[i] = blackBoard[i]->getBoardIndex();
        }
    }

    for(int i = 0; validMoves.size() > i; i++) {
        bool valid = true;
        for (int j = 0; teamPositions.size() > j && valid; j++) {
            if (validMoves[i] == teamPositions[j]) {
                valid = false;
            }
        }
        if (valid) { cleanMoves.push_back(validMoves[i]); }
    }
    return cleanMoves;
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

void Board::draw() {
    glColor3f(1.0f,1.0f,1.0f);
    glRecti(0,0,800,800);
    glColor3f(0.0, 0.0, 0.0);
    glRecti(0,0,100,100);
    glRecti(200,0,300,100);
    glRecti(400,0,500,100);
    glRecti(600,0,700,100);
    glRecti(100,100,200,200);
    glRecti(300,100,400,200);
    glRecti(500,100,600,200);
    glRecti(700,100,800,200);
    glRecti(0,200,100,300);
    glRecti(200,200,300,300);
    glRecti(400,200,500,300);
    glRecti(600,200,700,300);
    glRecti(100,300,200,400);
    glRecti(300,300,400,400);
    glRecti(500,300,600,400);
    glRecti(700,300,800,400);
    glRecti(0,400,100,500);
    glRecti(200,400,300,500);
    glRecti(400,400,500,500);
    glRecti(600,400,700,500);
    glRecti(100,500,200,600);
    glRecti(300,500,400,600);
    glRecti(500,500,600,600);
    glRecti(700,500,800,600);
    glRecti(0,600,100,700);
    glRecti(200,600,300,700);
    glRecti(400,600,500,700);
    glRecti(600,600,700,700);
    glRecti(100,700,200,800);
    glRecti(300,700,400,800);
    glRecti(500,700,600,800);
    glRecti(700,700,800,800);

    for(ChessPiece *p : whiteBoard) {
        if(p != nullptr){
           p->draw();
        }
    }

    for(ChessPiece *p : blackBoard) {
        if(p != nullptr){
            p->draw();
        }
    }

}
