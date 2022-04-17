#include <iostream>
#include <string>
#include <vector>
#include "canvas.h"

using namespace std;

int main(){
    int x,y, width, heigth;
    char sign;
    string com, type;
    vector<Shape*> shapes;
    
    size_t row, col;
    cin >> row >> col;
    
    Canvas* canvas = new Canvas(row, col);
    canvas->Clear();
    canvas->Print();
    
    while(1){
        cin >> com;
        if(com == "add"){
            cin >> type;
            if (type == "rect") {
            cin >> x >> y >> width >> heigth >> sign;
            Rectangle* rect = new Rectangle(x, y,  width, heigth,sign);
            shapes.push_back(rect);
            }
        else if (type == "tri_up") {
            cin >> x >> y >> width >> sign;
            UpTriangle* utri = new UpTriangle(x, y, width, sign);
            shapes.push_back(utri);
            }
        else if (type == "tri_down") {
            cin >> x >> y >>  width >> sign;
            DownTriangle* dtri = new DownTriangle(x, y, width, sign);
            shapes.push_back(dtri);
            }
        else if (type == "diamond") {
            cin >> x >> y >> width >> sign;
            Diamond* dia = new Diamond(x, y, width, sign);
            shapes.push_back(dia);
            }
        }
        else if(com == "draw"){
            canvas->Clear();
            for (int i = 0; i < shapes.size(); ++i) shapes[i]->Draw(canvas);
            canvas->Print();
        }
        else if(com == "delete"){
            cin >> x;
            if (x < shapes.size() && x >= 0)
                shapes.erase(shapes.begin()+x);
        }
         else if (com == "resize") {
            cin >> row >> col;
            canvas->Resize(row, col);
        } 
         else if(com == "dump"){
             int count = 0;
             for(Shape* i: shapes){
                 cout << count << " ";
                 i->Dump();
                 count++;
            }
        }
        else if(com == "quit")
            break;
    }
    
    for (int i = 0; i < shapes.size(); ++i) 
        delete shapes[i];
    shapes.clear();
    
    return 0;
}
