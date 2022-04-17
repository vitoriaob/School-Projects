#include<iostream>
#include "shapes.h"
#define pi 3.14

double Circle::AreaC(int r){
    return ((r*r)*pi);
    }
double Circle::PerimeterC(int r){
    return (2*pi*r);
    }

 int Rectangle::AreaR(int x, int y){
    return(x*y);
    }
int Rectangle::PerimeterR(int x, int y){
    return((2*x)+(2*y));
    }


    
