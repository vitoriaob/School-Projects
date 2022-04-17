#include<iostream>
#include<string>
#include"rect.h"

using namespace std;

int main(){
    int wi, he;
    string com;
    
    while(1){
        cin >> com;
        if (com == "square"){
            cin >> wi;
            Square s(wi);
            s.print();
        }
        else if (com == "nonsquare"){
            cin >> wi >> he;
            NonSquare ns(wi, he);
            ns.print();
        }
        else if (com == "quit")
            break;
    }
    
    
    return 0;
}
