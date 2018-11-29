//
//  main.cpp
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 27/09/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//


// NOTES FOR FUTURE

// --- SKILAVERKEFNI 5 ---
// * BÚA TIL FAMILY - ÞANNIG EF EINN GULUR OG EINN BLÁR LENDA SAMAN VERÐUR BARN


// ------------------------------------------------------------------------------


// --- SKILAVERKEFNI 6 ---
// * TIL VERÐUR GRAS Á HVERJI X SEK. ÞAÐ GEFUR ORKU
// * KINDUR FÁ ORKU FALL
// * KINDUR BORÐA GRAS TIL AÐ LIFA AF
// * ÚLFUR FÆR ORKU FALL
// * ÚFLUR BORÐAR KINDUR TIL AÐ LIFA AF


#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

#include <math.h>

using namespace std;

double width    =0.1;
double height   =0.1;

double get_distance_between(double x1, double y1, double x2, double y2) {
    
    double first_result_x = (x1 - x2);
    
    double final_result_x = pow(first_result_x, 2);
    
    double first_result_y = (y1 - y2);
    
    double final_result_y = pow(first_result_y, 2);
    
    double final_result = sqrt(final_result_x + final_result_y);
    
    return final_result;
}

class Animal {
public:
    double x        =0;
    double y        =0;
    
    double width    =0.1;
    double height   =0.1;
    
    double r;
    double g;
    double b;
    
    bool is_alive = true;
    
    void set_color(double r,double g,double b) {
        glColor3f(r,g,b);
    }
    
    void draw() {
        if (is_alive) {
            set_color(r,g,b);
            
            glBegin(GL_POLYGON);
            glVertex3f(x,            y,           0.0); //uppi til vinstri.
            glVertex3f((x+width),    y,           0.0); //uppi til haegri.
            glVertex3f((x+width),    (y-height),  0.0); //nidri til haegri.
            glVertex3f(x,            (y-height),  0.0); //nidri til vinstri.
            
            glEnd();
        }
    }
    
    void move_right() {
        x+=width;
    }
    
    void move_left() {
        x-=width;
    }
    
    void move_up() {
        y+=height;
    }
    
    void move_down() {
        y-=height;
    }
    
    void standBy() {
        
    }
    
    Animal();
};

Animal::Animal() {
    
}

class Wolf: public Animal {
public:
    double width = 0.1;
    double height = 0.1;
    
    int eaten = 0;
    
    double center_x =0;
    double center_y =0;

    int angle = 0;

    void update_center() {
        center_x = x+(width/2);
        center_y = y+(height/2);
    };
    
    void special_draw() {
        set_color(r,g,b);

        //snua.
        glTranslatef(center_x,center_y, 0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(-center_x, -center_y, 0);
        
        glBegin(GL_POLYGON);
        glVertex3f(x,               y,              0.0); //uppi til vinstri.
        glVertex3f((x+width),       y,              0.0); //uppi til haegri.
        glVertex3f((x+(width/2)),   (y-height),     0.0); //uppi til haegri.
        glEnd();

        //snua til baka.
        glTranslatef(center_x,center_y, 0);
        glRotatef(angle, 0, 0, -1);
        glTranslatef(-center_x, -center_y, 0);

        glEnd();
    }
    
    Wolf(double args_x, double args_y, double color_r, double color_g, double color_b, int args_angle);
};

Wolf::Wolf(double args_x, double args_y, double color_r, double color_g, double color_b, int args_angle) {

    // Coordinates
    x=args_x;
    y=args_y;
    
    // Colors
    r=color_r;
    g=color_g;
    b=color_b;
    
    // Angle
    angle=args_angle;
}

class Sheep: public Animal {
public:
    Sheep(double args_x, double args_y, double color_r, double color_g, double color_b);
    
    void move() {
        int rand_number = rand() % 5 + 1;
        
        if (rand_number == 1) {
            Sheep::move_down();
        } else if (rand_number == 2) {
            Sheep::move_up();
        } else if (rand_number == 3) {
            Sheep::move_left();
        } else if (rand_number == 4) {
            Sheep::move_right();
        } else if (rand_number == 5) {
            Sheep::standBy();
        }
    }
    
    void stop_being_scared(){
        r=1.0;
        g=1.0;
        b=1.0;
    }
    
    void becomes_scared() {
        r=0.97;
        g=0.87;
        b=0.11;
    }
    
    void becomes_very_scared() {
        r=1.0;
        g=0.0;
        b=0.0;
    }
};

Sheep::Sheep(double args_x, double args_y, double color_r, double color_g, double color_b) {
    width = 0.05;
    height = 0.05;
    
    x=args_x;
    y=args_y;
    
    // Colors
    r=color_r;
    g=color_g;
    b=color_b;
}

//class Detectors {
//public:
//
//    void collision_detector(double distance_between_sheep, Wolf wolf) {
//        if (Sheep::is_alive) {
//            if (distance_between_sheep > 0.6) {
//                Sheep::stop_being_scared();
//            }
//
//            if (distance_between_sheep < 0.6 && distance_between_sheep > 0.4) {
//                Sheep::becomes_scared();
//            }
//
//            if (distance_between_sheep < 0.4 && distance_between_sheep > 0.2) {
//                Sheep::becomes_very_scared();
//            }
//
//            if (distance_between_sheep < 0.1 && distance_between_sheep > 0.0) {
//                Sheep::is_alive = false;
//
//                wolf.eaten+=1;
//            }
//        }
//    }
//}

//                (start_location, another_start_location, r, g, b, angle)

Wolf vondi_ulfurinn (-1,    1,     0.52,      0.46,    0.44,     90);
Sheep kindin_einar  (0,    0,      1.0,       1.0,     1.0);

double distance_between_einar = get_distance_between(vondi_ulfurinn.x, vondi_ulfurinn.y, kindin_einar.x, kindin_einar.y); // Kindin Einar

void turningkeyPressed(unsigned char key, int x, int y) {
    if(key == 'd')  {vondi_ulfurinn.angle=90;}
    if(key == 'a')  {vondi_ulfurinn.angle=-90;}
    if(key == 's')  {vondi_ulfurinn.angle=360;}
    if(key == 'w')  {vondi_ulfurinn.angle=180;}
}

void arrowKeyPressed(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            vondi_ulfurinn.move_up();
            break;
        case GLUT_KEY_DOWN:
            vondi_ulfurinn.move_down();
            break;
        case GLUT_KEY_LEFT:
            vondi_ulfurinn.move_left();
            break;
        case GLUT_KEY_RIGHT:
            vondi_ulfurinn.move_right();
            break;
    }
}


void timer(int extra)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if (kindin_einar.width < 0.1 && kindin_einar.height < 0.1) {
        kindin_einar.width+=0.001;
        kindin_einar.height+=0.001;
    }
    
    vondi_ulfurinn.update_center();
    vondi_ulfurinn.special_draw();
    
    kindin_einar.draw();
    kindin_einar.move();
    
    glFlush();
    glutTimerFunc(200, timer, 200);
}

void display_world() {
    
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(720, 1200);
    glutCreateWindow("Sheep running wild!");
    glutTimerFunc(200, timer, 200);
    
    //##################################
    glutDisplayFunc(display_world);
    glutKeyboardFunc(turningkeyPressed);
    glutSpecialFunc(arrowKeyPressed);
    //##################################
    
    glutMainLoop();

    return 0;
}
