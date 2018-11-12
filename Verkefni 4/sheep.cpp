//
//  sheep.cpp
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 12/11/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

#include "animals.cpp"

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
