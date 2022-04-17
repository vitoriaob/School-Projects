#include<iostream>

class Circle {
private:
    int cx, cy, cr;
public:
    double AreaC(int r);
    double PerimeterC(int r);
};

class Rectangle {
private:
    int rx, ry;
public:
    int AreaR(int x, int y);
    int PerimeterR(int x, int y);
    
};
