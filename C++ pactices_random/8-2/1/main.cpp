#include<iostream>
#include<string> 
#include"shapes.h"

using namespace std;

int main(){
    
    string com;
    int height, width, starti, startj, canvasw, canvash;
    char sign;
    
    cin >> canvasw >> canvash;
    
    while(1){
        cin >> com;
        if(com == "rect"){
          cin >> starti >> startj >> width >> height>>sign;
          Rectangle rect(width,height,starti,startj,sign);
          cout << "Area: " << rect.GetArea() << endl;
          cout << "Perimeter: "<< rect.GetPerimeter() <<endl;
          rect.Draw(canvasw, canvash);
        }
        else if(com == "diamond"){
          cin >> startj >> starti >> height>>sign;
          Diamond diamond(height,starti,startj,sign);
          cout << "Area: " << diamond.GetArea() << endl;
          cout << "Perimeter: "<< diamond.GetPerimeter() <<endl;
          diamond.Draw(canvasw, canvash);
            
        }
        else if(com == "square"){
          cin >> starti >> startj >> height>>sign;
          Square square(height,starti,startj,sign);
          cout << "Area: " << square.GetArea() << endl;
          cout << "Perimeter: "<< square.GetPerimeter() <<endl;
          square.Draw(canvasw, canvash);
        }
        else if(com == "quit")
            break;
    }
    return 0;
}
