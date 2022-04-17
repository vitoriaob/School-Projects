#include<iostream>
#include<set>
#include<string>
#include <cctype>
#include <algorithm>
#include "setfunc.h"


std::set<int> parseSet(const std::string& str){
   int i =1;
   int num;
   char test, sig;
   std::set<int> set1;
   
   while( i < str.length()){
       test = str[i];
       sig = str[i-1];
       if(isdigit(test)){
           num = test -  '0';
           if(sig == '-')
               num = num*(-1);
           set1.insert(num);
        }
        i++;
   }
    return(set1);
}

void printSet(const std::set<int>& set){
    std::cout << '{';
    for(auto it=set.begin(); it != set.end(); it++) 
        std::cout << ' ' << *it;
    std::cout << " }" << std::endl; 
}

std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1){
    std::set<int> setfinal;
    
    std::set_intersection(set0.begin(), set0.end(), set1.begin(), set1.end(), std::inserter(setfinal, setfinal.begin()));
    
    return (setfinal);
}

std::set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1){
    std::set<int> setfinal;
    
    std::set_union(set0.begin(), set0.end(), set1.begin(), set1.end(), std::inserter(setfinal, setfinal.begin()));
    
    return(setfinal);
}

std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1){
    std::set<int> setfinal;
    
    std::set_difference(set0.begin(), set0.end(), set1.begin(), set1.end(), std::inserter(setfinal, setfinal.begin()));
    
    return(setfinal);
}
