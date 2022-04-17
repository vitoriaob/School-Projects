#include<iostream>
#include<vector>
#include"intset.h"
#include<string>
using namespace std;

int main(){
    IntegerSet set;
    vector<int> printer;
    string comand;
    int num;
    
    while(1){
        cin>> comand;
        
        if(comand == "add"){
            cin >> num;
            set.AddNumber(num);
            printer = set.GetAll();
            for(int i=0; i<printer.size(); i++)
            cout << printer[i] << " ";
            cout << endl;
            
        }
        else if(comand == "del"){
            cin >> num;
            set.DeleteNumber(num);
            printer = set.GetAll();
            for(int i=0; i<printer.size(); i++)
            cout << printer[i] << " ";
            cout << endl;
        }
        
        else if(comand == "get"){
            cin >> num;
            cout << set.GetItem(num) << endl;
        }
        else if(comand == "quit")
            break;
     
    }
    
    return 0;
}
