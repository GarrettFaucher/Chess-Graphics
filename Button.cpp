//
// Created by Jillian Neff on 12/3/19.
//

#include "Button.h"
#include "graphics.h"
using namespace std;

Button::Button(color fill, point center, unsigned int width, unsigned int height, std::string label) : Quad(fill, center, width, height) {
    this->label = label;
    originalFill = fill;
    hoverFill = {fill.red + 0.5, fill.green + 0.5, fill.blue + 0.5};
    pressFill = {fill.red - 0.3, fill.green - 0.3, fill.blue - 0.3};
    pressed = false;
}

void Button::draw() const {
    Quad::draw();
    glColor3f(0, 0, 0);
    glRasterPos2i(center.x - (4 * label.length()), center.y + 7);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
}

/* Returns true if the coordinate is inside the box */
bool Button::isOverlapping(int x, int y) const {
    // TODO: Implement
    if ((getLeftX()<= x && getRightX() >= x) && (getTopY()<=y && getBottomY() >= y)){
        return true;
    }
    return false; // Placeholder for compilation
}

/* Returns true if the button is pressed down */
bool Button::isPressed() const {
    return pressed;
}

/* Change color of the box when the user is hovering over it */
void Button::hover() {
    setColor(hoverFill);
}

void Button::setPressed(bool press) {
    pressed = press;
}

/* Change color of the box when the user is clicking on it */
void Button::pressDown() {
    setColor(pressFill);
    pressed = true;
}

/* Change the color back when the user is not clicking/hovering */
void Button::release() {
    setColor(originalFill);
    pressed = false;
}

void Button::choice() {
    int numTriangles = 100; //# of triangles used to draw circle

    GLfloat twoPi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fill.red - 0.2, fill.green - 0.2, fill.blue - 0.2);
    glVertex2f(center.x, center.y); // center of circle
    for(int i = 0; i <= numTriangles;i++) {
        glVertex2f(
                float(center.x) + (34 * cosf(float(i) *  twoPi / float(numTriangles))),
                float(center.y) + (34 * sinf(float(i) * twoPi / float(numTriangles)))
        );
    }
    glEnd();
}

