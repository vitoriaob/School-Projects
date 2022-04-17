#include<iostream>
#include<vector>
#include<string>

using namespace std;

class A{
public:
    virtual string getTypeInfo()
    { return "This is an instance of class A";}
};
class B: public A{
    virtual string getTypeInfo()
    { return "This is an instance of class B";}
};
class C: public B{
    virtual string getTypeInfo()
    { return "This is an instance of class C";}
};

void printObjectTypeInfo1(A* object){
    cout << object->getTypeInfo()<< endl;
}

void printObjectTypeInfo2(A& object){
    cout << object.getTypeInfo()<< endl;
}

int main(){
   
    A* a = new A;
    A* b = new B;
    A* c = new C;
    vector<A*> arr;
    
    arr.insert(arr.begin(),a);
    arr.insert(arr.begin()+1,b);
    arr.insert(arr.begin()+2,c);
    
    for(int i=0; i<3; i++){
        printObjectTypeInfo1(arr.at(i));
        printObjectTypeInfo2(*arr.at(i));
    }
    
    arr.clear();
    delete(a);
    delete(b);
    delete(c);
    
    return 0;
}
