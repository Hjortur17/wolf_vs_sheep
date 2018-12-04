//
//  animal.h
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 04/12/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

#ifndef animal_h
#define animal_h

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

#endif /* animal_h */
