#include<iostream>
#include<vector>
#include<string>
#include<map>
#include"message.h"
using namespace std;

int main(){
    MessageBook phones;
    vector<int> phoneslist;
    string message, msg, op;
    char space;
    int number;
    vector<int>::iterator i;
    
    cin >> op;
    
    while(1){
        if(op == "add"){
           cin >> number;
           space = getchar();
           getline(cin,message);
           phones.AddMessage(number, message);
        }
        else if(op == "delete"){
           cin >> number;
           phones.DeleteMessage(number);
        }
        else if(op == "print"){
            cin >> number;
            msg = phones.GetMessage(number);
            cout << msg << endl;
        }
        else if(op == "list"){
            phoneslist = phones.GetNumbers();
            for(i = phoneslist.begin(); i < phoneslist.end(); i++){
                cout << *i << ": " << phones.GetMessage(*i) << endl;
            }
        }
        else if(op == "quit")
            break;
        
        cin >> op;
    }
    
    
    return 0;
}
