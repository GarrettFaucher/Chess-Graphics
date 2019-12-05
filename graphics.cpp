//
// Created by Jillian Neff on 11/15/19.
//

#include "graphics.h"
#include "Board.h"
#include "Button.h"
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;
GLdouble width, height;
int wd;
Board board;
screen phase;
Button startBtn({0.8,0.8,1.0},{400,500},100,50,"START");

void init() {
    width = 1000;
    height = 1000;
    srand(time(0));
    phase = start;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if(phase == start){
        string label = "Virtual Chess Game";
        glColor3f(1, 1, 1);
        glRasterPos2i(410,300);
        for(const char &letter : label) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
        startBtn.draw();
        glFlush();
    }
    if(phase == game){
        board.draw();
        glFlush();
    }
    if(phase == ending){

        glFlush();
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {
    if(startBtn.isOverlapping(x,y)){
        startBtn.hover();
    }
    else{
        startBtn.release();
    }

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && startBtn.isOverlapping(x,y)){
        startBtn.pressDown();
    }
    else{
        startBtn.release();
    }
    // If the left button is up and the cursor is overlapping with the Button, start the game.
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && startBtn.isOverlapping(x,y)){
        phase = game;
    }

    glutPostRedisplay();

}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Chess Game!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}

