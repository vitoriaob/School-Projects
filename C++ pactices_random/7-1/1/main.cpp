#include<iostream>
#include "sorted.h"
#include<string>
#include <sstream>
#include<vector>
using namespace std;

string helper = " ";


int main(){
   SortedArray vect;
   vector<int> printer;
   int num;
   string comand, buffer, buffer2;
   
   getline(cin, buffer);
   istringstream iss(buffer);
   while(iss>>num)
       vect.AddNumber(num);

   

    while(1){
    
    getline(cin,comand);
   
    if(comand == "ascend"){
        printer = vect.GetSortedAscending();
        for(int i=0; i< printer.size();i++)
            cout<< printer[i] <<" ";
        cout<<endl;
    }
    else if(comand == "descend"){
        printer = vect.GetSortedDescending();
        for(int i=0; i< printer.size();i++)
            cout<< printer[i]<<" ";
        cout<<endl;
    }
    else if(comand == "max")
        cout<< vect.GetMax()<< endl;
    else if(comand == "min")
        cout<< vect.GetMin()<< endl;
    else if(comand == "quit")
        break;
//     else 

              
    }
    
   
   return 0;
}
