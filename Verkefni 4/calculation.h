//
//  calculation.h
//  Verkefni 4
//
//  Created by Hjörtur Freyr Lárusson on 04/12/2018.
//  Copyright © 2018 Hjörtur Freyr. All rights reserved.
//

#ifndef calculation_h
#define calculation_h

#include <math.h>

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

#endif /* calculation_h */
