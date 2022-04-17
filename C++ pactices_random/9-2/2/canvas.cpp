#include<iostream>
#include<vector>
#include"canvas.h"

using namespace std;

void Canvas::Resize(size_t w, size_t h){
  canvas.erase( canvas.begin(), canvas.end() );
  _width = w;
  _heigth = h;
   canvas.clear();
   for(int i = 0; i < _heigth; i++)
        canvas.push_back(vector<char>(_width));
    
}
bool Canvas::DrawPixel(int x, int y, char brush){
  if ((x >= 0 && y >= 0) && (x < _width && y < _heigth)){
    canvas.at(y).at(x) = brush;
    return 1;
  }
  else
    return 0;
}
void Canvas::Print(){
    int aux = 0;
    cout << " ";
    for(int k = 0; k < _width; k++)
        cout << k%10;
    cout<<endl;
    
    for(auto it = canvas.cbegin(); it!= canvas.cend(); it++){
        cout << aux%10;
        for(int i = 0; i < (*it).size(); i++)
            cout << (*it).at(i);
        cout << endl;
        aux++;
    }
    
}
void Canvas::Clear(){
    for(int i =0; i< _heigth; i++){
        for(int j = 0; j < _width; j++){
            canvas.at(i).at(j) = '.';
        }
    }
}

void Rectangle::Draw(Canvas* canvas){
    for(int i = 0; i < _heig; i++){
        for(int j = 0; j <_wid; j++)
            canvas->DrawPixel(_wx+j, _hy+i, _brush);
    }
}

void UpTriangle::Draw(Canvas* canvas){
    int aux, xtmp, ytmp;
    xtmp = _wx;
    ytmp = _hy;
    aux = 1;
    for(int i=0; i<_hy; i++){
        for(int j = 0; j<aux; j++)
            canvas->DrawPixel( xtmp+j,ytmp, _brush);
        
        aux+=2;
        xtmp--;
        ytmp++;
    }
}

void DownTriangle::Draw(Canvas* canvas){
    int aux, xtmp, ytmp;
    xtmp = _wx;
    ytmp = _hy;
    aux = 1;
    for(int i=0; i<_heig; i++){
        for(int j = 0; j<aux; j++)
            canvas->DrawPixel(xtmp+j,ytmp, _brush);
        aux+=2;
        xtmp--;
        ytmp--;
    }
}

void Diamond::Draw(Canvas* canvas){
    int aux, xtmp, ytmp;
    xtmp = _wx;
    ytmp = _hy;
    aux = 1;
    for(int i=0; i<(_heig*2)-1; i++){
        for(int j = 0; j<aux; j++)
            canvas->DrawPixel( xtmp+j, ytmp, _brush);
        
        aux+=2;
        xtmp--;
        ytmp++;
    }
    
    aux-=4;
    xtmp+=2;
    for(int i=0; i<(_heig*2)-1; i++){
        for(int j = 0; j<aux; j++)
            canvas->DrawPixel(xtmp+j, ytmp, _brush);
        
        aux-=2;
        xtmp++;
        ytmp++;
    }
    
}
