//
//  wolf.cpp
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 12/11/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

#ifndef WOLF_H
#define WOLF_H

class Wolf: public Animal {
    public:
        double r=1.0;
//        int eaten = 0;
    
        inline Wolf(double g) {
            
            r=g;
            
        }
    
//        inline Wolf(double g);
        // double args_x, double args_y, double color_r, double color_g, double color_b
};

//inline Wolf::Wolf(double g) {
    // Coordinates
//    x=args_x;
//    y=args_y;
//
//    // Colors
//    r=color_r;
//    g=color_g;
//    b=color_b;
//}

#endif
