#include<iostream>
#include "shapes.h"
using namespace std;

int main(){
    
    char shape;
    int size1, size2, size3, size4;
    int area, perimeter;
    double areac, perimeterc;
    
    cout << "shape?" << endl;
    cin >> shape;
    
  while(1){
    if(shape == 'R'){
        cin >> size1 >> size2 >> size3 >> size4;
        Rectangle R;
        area = R.AreaR(size1, size2);
        perimeter = R.PerimeterR(size1, size2);
        cout << "area: "<< area << " perimeter: " << perimeter << endl;
    }
    else if(shape == 'C'){ 
        cin >> size1 >> size2 >> size3;
        Circle C;
        areac = C.AreaC(size3);
        perimeterc = C.PerimeterC(size3);
        cout << "area: "<< areac << " perimeter: " << perimeterc << endl;
    }
    else if (shape == 'Q')
        break;
    
    cout << "shape?" << endl;
    cin >> shape;
  }

   
   return 0;  
}
