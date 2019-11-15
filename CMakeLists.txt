cmake_minimum_required(VERSION 3.15)
project(FinalProjectMajor_GF_JN)

set(CMAKE_CXX_STANDARD 17)

add_executable(Main main.cpp ChessPiece.cpp ChessPiece.h Board.cpp Board.h
        pieces/King.cpp pieces/King.h pieces/Queen.cpp pieces/Queen.h pieces/Bishop.cpp pieces/Bishop.h pieces/Rook.cpp pieces/Rook.h pieces/Knight.cpp pieces/Knight.h pieces/Pawn.cpp pieces/Pawn.h graphics.cpp graphics.h)
add_executable(Testing testing.cpp ChessPiece.cpp ChessPiece.h Board.cpp Board.h
        pieces/King.cpp pieces/King.h pieces/Queen.cpp pieces/Queen.h pieces/Bishop.cpp pieces/Bishop.h pieces/Rook.cpp pieces/Rook.h pieces/Knight.cpp pieces/Knight.h pieces/Pawn.cpp pieces/Pawn.h)