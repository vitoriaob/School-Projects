#include<iostream>
#include"rect.h"

using namespace std;

int Rectangle::getArea(){
    return _width *_height;
}

int Rectangle::getPerimeter(){
    return 2*_width + 2* _height;
}

void Square::print(){
    cout << _width << "x" << _width << " Square" << endl;
    cout << "Area: " <<  Rectangle::getArea() << endl;
    cout<< "Perimeter: " << Rectangle::getPerimeter() << endl;
}

void NonSquare::print(){
    cout << _width << "x" << _height << " NonSquare" << endl;
    cout << "Area: " <<  Rectangle::getArea() << endl;
    cout<< "Perimeter: " << Rectangle::getPerimeter() << endl;
}
