//
//  test.cpp
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 15/10/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

#include "test.hpp"

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<GLUT/glut.h>

//This function is used to draw the 4 lines 2 vertical and 2 horizontal
void drawlines()
{
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    
    //2 vertical lines
    glVertex2f(100, 50);
    glVertex2f(100, 340);
    glVertex2f(200, 340);
    glVertex2f(200, 50);
    
    //2 horizontal lines
    glVertex2f(0, 150);
    glVertex2f(300, 150);
    glVertex2f(0, 250);
    glVertex2f(300, 250);
    
    glEnd();
}

//This is the idle call back function
void display()
{
    drawlines();
}
//main function of the program
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(300,350);
    glutCreateWindow("Tic Tac Toe");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
