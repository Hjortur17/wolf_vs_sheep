//
//  main.cpp
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 27/09/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

// --- SKILAVERKEFNI 6 ---
// * BÚA TIL VEGG SVO KINDURNAR FARA EKKI ÚT FYRIR
// * TIL VERÐUR GRAS Á HVERJI X SEK. ÞAÐ GEFUR ORKU
// * KINDUR FÁ ORKU FALL
// * KINDUR BORÐA GRAS TIL AÐ LIFA AF
// * ÚLFUR FÆR ORKU FALL
// * ÚFLUR BORÐAR KINDUR TIL AÐ LIFA AF


#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <vector>

#include <math.h>

using namespace std;

double width    =0.1;
double height   =0.1;

double get_distance_between(double obj1_x, double obj1_y, double obj2_x, double obj2_y) {
    
    double result_x;
    double result_y;
    double final_result;
    
    result_x = obj1_x - obj2_x;
    
    result_x = pow(result_x, 2);
    
    result_y = obj1_y - obj2_y;
    
    result_y = pow(result_y, 2);
    
    final_result = result_x + result_y;
    
    final_result = sqrt(final_result);
    
    return final_result;
}

class Animal {
public:
    double x        =0;
    double y        =0;
    
    double r        =1.0;
    double g        =1.0;
    double b        =1.0;
    
    double width    =0.1;
    double height   =0.1;
    
    double energy   =100.0;
    
    bool is_alive = true;
    bool gender = true;
    
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
    
    void energy_bar() {
        // if enegery lower 20% color change to red
        // if engery lower 50% color change to yellow
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
        
        double r=0.52;
        double g=0.46;
        double b=0.44;
        
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
    
    Wolf(double args_x, double args_y, int args_angle);
};

Wolf::Wolf(double args_x, double args_y, int args_angle) {

    // Coordinates
    x=args_x;
    y=args_y;
    
    // Angle
    angle=args_angle;
}

class Sheep: public Animal {
public:
    Sheep(double args_x, double args_y, double args_r, double args_g, double args_b);
    
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
        set_color(1.0, 1.0, 1.0);
    }
    
    void becomes_scared() {
        set_color(0.97, 0.87, 0.11);
    }
    
    void becomes_very_scared() {
        set_color(1.0, 0.0, 0.0);
    }
};

Sheep::Sheep(double args_x, double args_y, double args_r, double args_g, double args_b) {
    width = 0.05;
    height = 0.05;
    
    x=args_x;
    y=args_y;
    
    r=args_r;
    g=args_g;
    b=args_b;
}

Wolf vondi_ulfurinn (-1,    1,    90);

vector<Sheep> sheep_male;
vector<Sheep> sheep_female;
vector<Sheep> sheep_child;

void timer(int extra)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (vector<Sheep>::iterator it = sheep_male.begin(); it != sheep_male.end(); ++it) {
        
        it->draw();
        
        double distance_between_sheeps = get_distance_between(vondi_ulfurinn.x, vondi_ulfurinn.y, it->x, it->y);
        
        if (distance_between_sheeps > 0.6 ) {
            it->stop_being_scared();
        }
        
        if (distance_between_sheeps < 0.6 && distance_between_sheeps > 0.4) {
            it->becomes_scared();
        }
        
        if (distance_between_sheeps < 0.4 && distance_between_sheeps > 0.2) {
            it->becomes_very_scared();
        }
        
        if (distance_between_sheeps < 0.1 && distance_between_sheeps > 0.0) {
            it->is_alive = false;
            
            vondi_ulfurinn.eaten+=1;
            
            cout << vondi_ulfurinn.eaten << endl;
        }

        
        if (it->width < 0.1 && it->height < 0.1) {
            it->width+=0.001;
            it->height+=0.001;
        }
        
        it->move();
    }
    
    for (vector<Sheep>::iterator it = sheep_female.begin(); it != sheep_female.end(); ++it) {
        
        it->draw();
        
        double distance_between_sheeps = get_distance_between(vondi_ulfurinn.x, vondi_ulfurinn.y, it->x, it->y);

        if (distance_between_sheeps > 0.6 ) {
            it->stop_being_scared();
        }

        if (distance_between_sheeps < 0.6 && distance_between_sheeps > 0.4) {
            it->becomes_scared();
        }

        if (distance_between_sheeps < 0.4 && distance_between_sheeps > 0.2) {
            it->becomes_very_scared();
        }

        if (distance_between_sheeps < 0.1 && distance_between_sheeps > 0.0) {
            it->is_alive = false;

            vondi_ulfurinn.eaten+=1;

            cout << vondi_ulfurinn.eaten << endl;
        }
        
        if (it->width < 0.1 && it->height < 0.1) {
            it->width+=0.001;
            it->height+=0.001;
        }
        
        it->move();
    }
    
    for (vector<Sheep>::iterator girl = sheep_female.begin(); girl != sheep_female.end(); ++girl) {
        for (vector<Sheep>::iterator boy = sheep_male.begin(); boy != sheep_male.end(); ++boy) {
            
            double distance_between_boy_and_a_girl = get_distance_between(boy->x, boy->y, girl->x, girl->y);
            
            if (distance_between_boy_and_a_girl < 0.2 && distance_between_boy_and_a_girl > 0.0) {
                for (int i=1; i<=2; i++) {
                    Sheep child_sheep (0,      0,      0.44,     0.27,     0.69);
                    
                    sheep_child.push_back(child_sheep);
                };
            }
        }
    }
    
    vondi_ulfurinn.update_center();
    vondi_ulfurinn.special_draw();
    
    glFlush();
    glutTimerFunc(200, timer, 200);
}

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

void display_world() {
    
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(720, 1200);
    glutCreateWindow("Sheep running wild!");
    glutTimerFunc(200, timer, 200);
    
    for (int i=1; i<=2; i++) {
        Sheep boy_sheep (0,      0,      0.68,     0.85,     0.87);

        sheep_male.push_back(boy_sheep);
    };
    
    for (int i=1; i<=2; i++) {
        Sheep girl_sheep (0,      0,      1.0,     0.75,     0.76);
        
        sheep_female.push_back(girl_sheep);
    };
    
    //##################################
    glutDisplayFunc(display_world);
    glutKeyboardFunc(turningkeyPressed);
    glutSpecialFunc(arrowKeyPressed);
    //##################################
    
    glutMainLoop();

    return 0;
}
