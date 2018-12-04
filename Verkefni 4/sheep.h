//
//  sheep.h
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 04/12/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

#ifndef sheep_h
#define sheep_h

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

#endif /* sheep_h */
