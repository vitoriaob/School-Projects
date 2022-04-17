#include<iostream>

class Rectangle {
public:
Rectangle(int width, int height){ _width = width; _height = height;} 
int getArea(); // Returns the area of this rectangle
int getPerimeter(); // Returns the perimeter of this rectangle
protected:
// Define member variables you need
    int _width;
    int _height;
};
class Square: public Rectangle {
public:
Square (int width): Rectangle(width,width){} 
void print();// Print out information about this object (ex. '5x5 Square')
};
class NonSquare: public Rectangle {
public:
NonSquare (int width, int height): Rectangle(width,height){}
void print(); // Print out information about this object (ex. '2x7 NonSquare')
};
