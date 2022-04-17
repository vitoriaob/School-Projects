#include<iostream>
#include<string>
#include<vector>
#include"animal.h"

using namespace std;

int main(){
    int age, stripes;
    string name, toy;
    char com;
    vector<Animal*> animals;
    
    int k = 0;
    while(1){
        cin >> com;
        if(com == 'z'){
          cin >> name >> age >> stripes;
          Animal* zebra = new Zebra(name, age, stripes);
          animals.insert(animals.begin()+k,zebra); 
          k++;
        }
        else if(com=='c'){
           cin>> name >> age >> toy;
           Animal* cat = new Cat(name, age, toy);
           animals.insert(animals.begin()+k,cat);
           k++;
        }
        else if(com == '0')
            break;
    }
    
    for(int i=0; i<animals.size(); i++){
       animals.at(i)->printInfo(); 
       delete animals.at(i);
    }
    
    return 0;
}
