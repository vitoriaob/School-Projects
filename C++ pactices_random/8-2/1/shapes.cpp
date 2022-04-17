#include<iostream>
#include"shapes.h"

using namespace std;

void Shape::Draw(int canvas_width, int canvas_height){
    
    char** ary = new char*[canvas_width];
        for(char i = 0; i < canvas_width; ++i)
            ary[i] = new char[canvas_height];
    char s;
  
//drawing    
    for(int i=0; i< canvas_width; i++){
        for(int j=0; j< canvas_height; j++){
            
            if((i>=_starti && j>=_startj) && (i< _starti+_width && j<_startj+_height) && i<canvas_width && j<canvas_height)
               s = _sign;
            else 
                s = '.';
            ary[i][j] = s;
            }
        }

//printing    
    cout << ' ';
    int k;
    for(k=0; k<canvas_width; k++)
        cout << k;
    cout << endl;
    for(int i=0; i<canvas_width; i++){
        cout << i;
        for(int j=0; j<canvas_height; j++){
            cout << ary[i][j];
        }
        cout<<endl;
    }

// free the matrix    
    for(int i = 0; i < canvas_width; ++i) {
        delete [] ary[i];
    }
    delete [] ary;
    
}


void Diamond::Draw(int canvas_width, int canvas_height){
    
    char** ary = new char*[canvas_width];
        for(int i = 0; i < canvas_width; ++i)
            ary[i] = new char[canvas_height];
    
// filling the canvas first
    for(int i=0; i< canvas_width; i++){
        for(int j=0; j< canvas_height; j++)
            ary[i][j] = '.';
    }
                     
//drawing the diamond
//upper
    int c = 0;
    int i = _starti;
    
    while(i<=_starti+_height && i<canvas_width && i<canvas_height){
        
            for(int j=0; j <=c; j++){
            if(j+_startj>=canvas_height || _startj-j>=canvas_height )break;
            ary[i][_startj-j] = _sign;
            ary[i][_startj+j] = _sign;
            }
         c++; 
         i++;
    }
//bottom
    c = _height-1;
    i =_starti+_height+1;
    while(i<=_starti+2*_height && i<canvas_width && i<canvas_height){
            for(int j= c; j >=0; j--){
                if(j+_startj>=canvas_height || _startj-j>=canvas_height )break;
                ary[i][_startj-j] = _sign;
                ary[i][_startj+j] = _sign;
            }
     c--; 
     i++;
    }

    
//printing    

    cout << ' ';
    int kl;
    for( kl=0; kl<canvas_width; kl++)
        cout << kl;
    cout << endl;
    for(int i=0; i<canvas_width; i++){
        cout << i;
        for(int j=0; j<canvas_height; j++){
            cout << ary[i][j];
        }
        cout<<endl;
    }

// free the matrix    
    
    for(int v = 0; v < canvas_width; ++v) {
        delete [] ary[v];
    }
    delete [] ary;
    
}
