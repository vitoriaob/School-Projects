#include<iostream>

class Shape {
 public:
 Shape();
 Shape(int width, int height, int starti, int startj, char sign){
     _width = width; _height = height; _starti = starti; _startj = startj; _sign = sign;}
 double GetArea(){
   return _width*_height;  
}
 int GetPerimeter(){
     return _width*2 + _height*2;
}
 void Draw(int canvas_width, int canvas_height);
 protected:
 int _width;
 int _height;
 int _starti;
 int _startj;
 char _sign;
};
class Diamond: public Shape{
public:
 Diamond(int height, int starti, int startj, char sign): Shape(height,height,starti,startj,sign){}
 double GetArea(){
     return ((((2*_height)+1)*((2*_height)+1))/2.0);
}
 int GetPerimeter(){
     return Shape::GetPerimeter()+_height*2;
}
 void Draw(int canvas_width, int canvas_height);
};

class Square: public Shape{
public:    
 Square(int height, int starti, int startj, char sign): Shape(height,height,starti,startj,sign){}
 double GetArea(){
     return Shape::GetArea();
}
 int GetPerimeter(){
     return Shape::GetPerimeter();
}
 void Draw(int canvas_width, int canvas_height){
     return Shape::Draw(canvas_width, canvas_height);
} 
};    

class Rectangle: public Shape{
public: 
 Rectangle(int width, int height, int starti, int startj, char sign): Shape(width,height,starti,startj,sign){}
 double GetArea(){
     return Shape::GetArea();
}
 int GetPerimeter(){
     return Shape::GetPerimeter();
}
 void Draw(int canvas_width, int canvas_height){
     return Shape::Draw(canvas_width, canvas_height);
}    
};
