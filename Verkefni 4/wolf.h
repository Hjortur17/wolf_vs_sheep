//
//  wolf.h
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 04/12/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

#ifndef wolf_h
#define wolf_h

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

#endif /* wolf_h */
