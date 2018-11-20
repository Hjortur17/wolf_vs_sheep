//
//  animals.cpp
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 12/11/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//


#ifndef ANIMAL_H
#define ANIMAL_H

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


    Animal(void);
};

#endif
