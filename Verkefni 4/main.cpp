//
//  main.cpp
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 27/09/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <math.h>

using namespace std;

double width    =0.1;
double height   =0.1;

class Animal {
    public:
        double x        =0;
        double y        =0;
    
        double width    =0.1;
        double height   =0.1;
    
        double r;
        double g;
        double b;
    
        void set_color(double r,double g,double b) {
            glColor3f(r,g,b);
        }

        void draw() {
            set_color(r,g,b);
            
            glBegin(GL_POLYGON);
            glVertex3f(x,            y,           0.0); //uppi til vinstri.
            glVertex3f((x+width),    y,           0.0); //uppi til haegri.
            glVertex3f((x+width),    (y-height),  0.0); //nidri til haegri.
            glVertex3f(x,            (y-height),  0.0); //nidri til vinstri.
            glEnd();
        }
    
        Animal();
};

Animal::Animal() {
    
}

class Wolf: public Animal {
    public:
        Wolf(double args_x, double args_y, double color_r, double color_g, double color_b);
};

Wolf::Wolf(double args_x, double args_y, double color_r, double color_g, double color_b) {
    x=args_x;
    y=args_y;
    
    // Colors
    r=color_r;
    g=color_g;
    b=color_b;
}

class Sheep: public Animal {
    public:
        Sheep(double args_x, double args_y, double color_r, double color_g, double color_b);
};

Sheep::Sheep(double args_x, double args_y, double color_r, double color_g, double color_b) {
    x=args_x;
    y=args_y;
    
    // Colors
    r=color_r;
    g=color_g;
    b=color_b;
}

Wolf vondi_ulfurinn(-1, 1, 0.52, 0.46, 0.44);
Sheep kindinn_einar(0, 0, 1.0, 1.0, 1.0);

void keyPressed(unsigned char key, int x, int y) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(key == 'd')  {vondi_ulfurinn.x+=width;} // Virkar 26.10.18
    if(key == 'a')  {vondi_ulfurinn.x-=width;} // Virkar 26.10.18
    if(key == 's')  {vondi_ulfurinn.y-=height;} // Virkar 26.10.18
    if(key == 'w')  {vondi_ulfurinn.y+=height;} // Virkar 26.10.18
    
    vondi_ulfurinn.draw();
    kindinn_einar.draw();
    
    glFlush();
}

void display_world() {
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(700, 1200);
    glutCreateWindow("Kind on the move!");
    
    //##################################
    glutDisplayFunc(display_world);
    glutKeyboardFunc(keyPressed);
    //##################################
    
    glutMainLoop();
    return 0;
}
