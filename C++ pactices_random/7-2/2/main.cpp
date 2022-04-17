#include<iostream>
#include<set>
#include<string>
#include "setfunc.h"

using namespace std;

int main(){
    set<int> set1, set2, setfinal;
    string line, line1, line2;
    char first, space, op;
    
    while(1){
        cin >> first;
        if(isdigit(first))
            break;
        getline(cin,line1, '}');
        space = getchar();
        op = getchar();
        space = getchar();
        getline(cin,line2, '}');
        
        set1 = parseSet(line1);
        set2 = parseSet(line2);
        
        if(op == '+'){
            setfinal = getUnion(set1,set2);
            printSet(setfinal);
        }
        else if(op == '-'){
            setfinal = getDifference(set1,set2);
            printSet(setfinal);
        }
        else if(op == '*'){
            setfinal = getIntersection(set1,set2);
            printSet(setfinal);
        }
        
    }
    
    return 0;
}
