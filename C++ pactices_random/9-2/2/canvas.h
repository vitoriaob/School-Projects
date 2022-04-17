#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Canvas {
public:
 Canvas(size_t row, size_t col){
    _width = col;
    _heigth = row;
    for(int i = 0; i < _heigth; i++)
        canvas.push_back(vector<char>(_width));
    }
 ~Canvas(){
    canvas.erase(canvas.begin(),canvas.end());
}
 
void Resize(size_t w, size_t h);
 
bool DrawPixel(int x, int y, char brush);

void Print();

void Clear();
private:
  size_t _width;
  size_t _heigth;
  vector<vector<char>> canvas;
};
class Shape {
public:
 Shape(int wx, int hy, int h, int w, char sign){
     _wx = wx; _hy = hy; _heig = h; _wid = w; _brush = sign;
}
 virtual ~Shape(){}
 virtual void Draw(Canvas* canvas) {};
 virtual void Dump(){};
protected:
 int _wx;
 int _hy;
 int _heig;
 int _wid;
 char _brush;
};
class Rectangle : public Shape { 
public:
    Rectangle(int x, int y, int w, int h, char sign):Shape(x,y,h,w,sign){}
    void Draw(Canvas* canvas);
    void Dump(){
        cout<< "rect " <<_wx<<' '<<_hy<<' '<<_heig<<' '<<_wid<<' '<<_brush<<endl;
    }
};
class UpTriangle : public Shape { 
public: 
    UpTriangle(int x, int y, int h, char sign):Shape(x,y,h,h,sign){}
    void Draw(Canvas* canvas);
    void Dump(){
        cout<<"tri_up " <<_wx<<' '<<_hy<<' '<<_heig<<' '<<_brush<<endl;
    }
};
class DownTriangle : public Shape { 
    public: 
    DownTriangle(int x, int y, int h, char sign):Shape(x,y,h,h,sign){}
    void Draw(Canvas* canvas);
    void Dump(){
        cout<<"tri_down "<<_wx<<' '<<_hy<<' '<<_heig<<' '<<_brush<<endl;
    }
};
class Diamond : public Shape {
    public: 
    Diamond(int x, int y, int h, char sign):Shape(x,y,h,h,sign){}
    void Draw(Canvas* canvas);
    void Dump(){
        cout<<"diamond "<<_hy<<' '<<_wx<<' '<<_heig<<' '<<_brush<<endl;
    }
};
