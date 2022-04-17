#include<iostream>
#include<vector>
#include<string>

using namespace std;

class A{
public:
    virtual string test()
    { return "A::test()";}
};
class B: public A{
    virtual string test()
    { return "B::test()";}
};
class C: public B{
    virtual string test()
    { return "C::test()";}
};

int main(){
   
    A* a = new A;
    A* b = new B;
    A* c = new C;
    vector<A*> arr;
    
    arr.insert(arr.begin(),a);
    arr.insert(arr.begin()+1,b);
    arr.insert(arr.begin()+2,c);
    
    cout << arr.at(0)->test()<<endl;
    cout << arr.at(1)->test()<<endl;
    cout << arr.at(2)->test()<<endl;
    
    arr.clear();
    delete(a);
    delete(b);
    delete(c);
    
    return 0;
}
