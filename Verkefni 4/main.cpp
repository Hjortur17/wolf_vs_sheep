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

double square_color_r   =0.96;
double square_color_g   =0.46;
double square_color_b   =0.27;

class Animal {
public:
    double x        =0;
    double y        =0;
    
    double width    =0.1;
    double height   =0.1;
    
    void draw(){
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_POLYGON);
        glVertex3f(x,            y,           0.0); //uppi til vinstri.
        glVertex3f((x+width),    y,           0.0); //uppi til haegri.
        glVertex3f((x+width),    (y-height),  0.0); //nidri til haegri.
        glVertex3f(x,            (y-height),  0.0); //nidri til vinstri.
        glEnd();
        
        glFlush();
    }
};

class Wolf: public Animal {
    
};

class Sheep: public Animal {
    
};

Wolf ulfur;
Sheep kind;

void keyPressed(unsigned char key, int x, int y) {
    if(key == 'd')  {ulfur.x+=width;} // Virkar 26.10.18
    if(key == 'a')  {ulfur.x-=width;} // Virkar 26.10.18
    if(key == 's')  {ulfur.y-=height;} // Virkar 26.10.18
    if(key == 'w')  {ulfur.y+=height;} // Virkar 26.10.18
    
    ulfur.draw();
}

void display_world() {
    //ulfur.draw();
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
