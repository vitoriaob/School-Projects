#include<iostream>
#include<string>
#include "number.h"

using namespace std;

int main(){
    Cube num;
    int n;
    string com;
    
    while(1){
      cin >> com;

      if(com == "number"){
          cin >> n;
          num.setNumber(n);
          cout << "getNumber(): " << num.getNumber()<< endl;
        }
      else if(com == "square"){
          cin >> n;
          num.setNumber(n);
          cout << "getNumber(): " << num.getNumber() << endl;
          cout << "geSquare(): " << num.getSquare() << endl;
        }
      else if(com == "cube"){
          cin >> n;
          num.setNumber(n);
          cout << "getNumber(): " << num.getNumber() << endl;
          cout << "geSquare(): " << num.getSquare() << endl;
          cout << "getCube(): " << num.getCube() << endl;
        }
      else if(com == "quit")
          break;
    }
    return 0;
}
