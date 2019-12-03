if (APPLE)
    FIND_PACKAGE(OpenGL)
    find_package(GLUT REQUIRED)
else ()
    FIND_PACKAGE(OpenGL)
endif (APPLE)

cmake_minimum_required(VERSION 3.10)
project(FinalProjectMajor_GF_JN)

add_executable(Graphics_Based ChessPiece.cpp ChessPiece.h Board.cpp Board.h graphics.cpp graphics.h
        pieces/King.cpp pieces/King.h pieces/Queen.cpp pieces/Queen.h pieces/Bishop.cpp pieces/Bishop.h
        pieces/Rook.cpp pieces/Rook.h pieces/Knight.cpp pieces/Knight.h pieces/Pawn.cpp pieces/Pawn.h)

if (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
    target_link_libraries (Graphics_Based ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
else ()
    find_package(OpenGL REQUIRED COMPONENTS OpenGL)
    find_package(GLUT REQUIRED)

    add_dependencies(Graphics_Based OpenGL::OpenGL)
    include_directories(${GLUT_INCLUDE_DIRS} )
    target_link_libraries(Graphics_Based OpenGL::OpenGL ${GLUT_LIBRARY} ${OPENGL_gl_LIBRARY})
endif ()

