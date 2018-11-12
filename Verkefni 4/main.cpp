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


// including files
#include "calculations.cpp"
#include "animals.cpp"
#include "wolf.cpp"
#include "sheep.cpp"

using namespace std;

Wolf vondi_ulfurinn(-1, 1, 0.52, 0.46, 0.44);
Sheep kindin_einar(0, 0, 1.0, 1.0, 1.0);
Sheep kindin_gunnar(0, 0, 1.0, 1.0, 1.0);
Sheep kindin_jon(0, 0, 1.0, 1.0, 1.0);


void keyPressed(unsigned char key, int x, int y) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(key == 'd')  {vondi_ulfurinn.move_right();}
    if(key == 'a')  {vondi_ulfurinn.move_left();}
    if(key == 's')  {vondi_ulfurinn.move_down();}
    if(key == 'w')  {vondi_ulfurinn.move_up();}
    
    double distance_between_einar = get_distance_between(vondi_ulfurinn.x, vondi_ulfurinn.y, kindin_einar.x, kindin_einar.y);
    double distance_between_gunnar = get_distance_between(vondi_ulfurinn.x, vondi_ulfurinn.y, kindin_gunnar.x, kindin_gunnar.y);
    double distance_between_jon = get_distance_between(vondi_ulfurinn.x, vondi_ulfurinn.y, kindin_jon.x, kindin_jon.y);
    
    vondi_ulfurinn.draw();
    
    kindin_einar.draw();
    kindin_gunnar.draw();
    kindin_jon.draw();
    
    kindin_einar.move();
    kindin_gunnar.move();
    kindin_jon.move();
 
    if (distance_between_einar > 0.6 ) {
        kindin_einar.stop_being_scared();
    }
    
    if (distance_between_einar < 0.6 && distance_between_einar > 0.4) {
        kindin_einar.becomes_scared();
    }
    
    if (distance_between_einar < 0.4 && distance_between_einar > 0.2) {
        kindin_einar.becomes_very_scared();
    }
    
    if (distance_between_einar < 0.2 && distance_between_einar > 0.1) {
        kindin_einar.is_alive = false;

        vondi_ulfurinn.eaten+=1;

        cout << vondi_ulfurinn.eaten << endl;
    }
    
    
    
    if (distance_between_gunnar > 0.6 ) {
        kindin_gunnar.stop_being_scared();
    }
    
    if (distance_between_gunnar < 0.6 && distance_between_gunnar > 0.4) {
        kindin_gunnar.becomes_scared();
    }
    
    if (distance_between_gunnar < 0.4 && distance_between_gunnar > 0.2) {
        kindin_gunnar.becomes_very_scared();
    }
    
    if (distance_between_gunnar < 0.2 && distance_between_gunnar > 0.1) {
        kindin_gunnar.is_alive = false;
        
        vondi_ulfurinn.eaten+=1;
        
        cout << vondi_ulfurinn.eaten << endl;
    }
    
    if (distance_between_jon > 0.6 ) {
        kindin_jon.stop_being_scared();
    }
    
    if (distance_between_jon < 0.6 && distance_between_jon > 0.4) {
        kindin_jon.becomes_scared();
    }
    
    if (distance_between_jon < 0.4 && distance_between_jon > 0.2) {
        kindin_jon.becomes_very_scared();
    }
    
    if (distance_between_jon < 0.2 && distance_between_jon > 0.1) {
        kindin_jon.is_alive = false;
        
        vondi_ulfurinn.eaten+=1;
        
        cout << vondi_ulfurinn.eaten << endl;
    }
    
    glFlush();
}

void display_world() {
    
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(700, 1200);
    glutCreateWindow("Sheep running wild!");

    //##################################
    glutDisplayFunc(display_world);
    glutKeyboardFunc(keyPressed);
    //##################################

    glutMainLoop();
    return 0;
}
