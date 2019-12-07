//
// Created by Jillian Neff on 12/3/19.
//

#ifndef FINALPROJECTMAJOR_GF_JN_BUTTON_H
#define FINALPROJECTMAJOR_GF_JN_BUTTON_H


#include "Quad.h"
#include <string>
#include <functional>
#include <math.h>

class Button : public Quad {
private:
    std::string label;
    color originalFill, hoverFill, pressFill;
    bool pressed;

public:
    Button(color fill, point center, unsigned int width, unsigned int height, std::string label);
    /* Uses OpenGL to draw the box with the label on top */
    virtual void draw() const override;

    /* Returns true if the coordinate is inside the box */
    bool isOverlapping(int x, int y) const;

    /* Returns true if button is pressed down */
    bool isPressed() const;

    /* Change color of the Button when the user is hovering over it */
    void hover();

    /* Change color of the Button when the user is clicking on it */
    void pressDown();

    /* Change the color back when the user is not clicking/hovering */
    void release();

    void choice();
};

#endif //FINALPROJECTMAJOR_GF_JN_BUTTON_H
