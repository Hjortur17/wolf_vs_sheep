//
//  wolf.cpp
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 12/11/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

#include "animals.cpp"

class Wolf: public Animal {
public:
    
    int eaten = 0;
    
    Wolf(double args_x, double args_y, double color_r, double color_g, double color_b);
};

Wolf::Wolf(double args_x, double args_y, double color_r, double color_g, double color_b) {
    // Coordinates
    x=args_x;
    y=args_y;
    
    // Colors
    r=color_r;
    g=color_g;
    b=color_b;
}
