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
        glVertex3f(x,           y,          0.0); //uppi til vinstri.
        glVertex3f((x+width),   y,          0.0); //uppi til haegri.
        glVertex3f((x+width),   (y-height), 0.0); //nidri til haegri.
        glVertex3f(x,           (y-height), 0.0); //nidri til vinstri.
        glEnd();

        //snua til baka.
        glTranslatef(center_x,center_y,0);
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
    x=args_x;
    y=args_y;
    
    // Colors
    r=color_r;
    g=color_g;
    b=color_b;
}

Wolf vondi_ulfurinn(-1, 1, 0.52, 0.46, 0.44, 90);
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
//    double distance_between_gunnar = get_distance_between(vondi_ulfurinn.x, vondi_ulfurinn.y, kindin_gunnar.x, kindin_gunnar.y);
//    double distance_between_jon = get_distance_between(vondi_ulfurinn.x, vondi_ulfurinn.y, kindin_jon.x, kindin_jon.y);
    
    vondi_ulfurinn.update_center();
    vondi_ulfurinn.draw();
    
    kindin_einar.move();
    
    kindin_einar.draw();
    
    
    if (kindin_einar.is_alive) {
        if (distance_between_einar > 0.6 ) {
            kindin_einar.stop_being_scared();
        }
        
        if (distance_between_einar < 0.6 && distance_between_einar > 0.4) {
            kindin_einar.becomes_scared();
        }
        
        if (distance_between_einar < 0.4 && distance_between_einar > 0.2) {
            kindin_einar.becomes_very_scared();
        }
        
        if (distance_between_einar < 0.1 && distance_between_einar > 0.0) {
            kindin_einar.is_alive = false;
            
            vondi_ulfurinn.eaten+=1;
            cout << vondi_ulfurinn.eaten << endl;
        }
    }
    
    glFlush();
}

void display_world() {
    
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(720, 1200);
    glutCreateWindow("Sheep running wild!");
    
    //##################################
    glutDisplayFunc(display_world);
    glutKeyboardFunc(keyPressed);
    //##################################
    
    glutMainLoop();

    return 0;
}
