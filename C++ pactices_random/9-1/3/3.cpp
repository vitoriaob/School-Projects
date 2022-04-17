#include<iostream>
#include<vector>
#include<string>

using namespace std;

class A{
private:
    int* memberA;
public:
    int value;
    A(int argA) { 
        int* memberA = new int;
        *memberA = argA;
        value = *memberA;
        cout << "new memberA" <<endl;
    }

     virtual ~A() {
        delete memberA;
        cout << "delete memberA"<<endl;
    }
    virtual void print(){
        cout << "*memberA " << value << endl;
    }
   
};

class B: public A{
private:
    double* memberB;
    
public:
    double value;
    B(double argB):A(1){
        double* memberB = new double;
        *memberB = argB;
        value = *memberB;
        cout << "new memberB" <<endl;
    }
 
    virtual ~B() {
        delete memberB;
        cout << "delete memberB"<<endl;
    }
    virtual void print(){
        A::print();
        cout << "*memberB " << value<< endl;
    }
};

class C: public B{
private: 
   const string* memberc;

public:
    string value;
    C(const string& argc):B(1.1) { 
        const string* memberc = new string;
        memberc = &argc;
        value = *memberc;
        cout << "new memberC" <<endl;

    }
      virtual void print(){
        B::print();
        cout << "*memberC " << value << endl;
    }
    virtual ~C() {
        delete memberc;
        cout << "delete memberC"<<endl;
    }
};


int main(){
    
    int n;
    double d;
    string s;
    
    cin >> n >> d >> s;
   
    A* a = new A(n);
    A* b = new B(d);
    A* c = new C(s);
    vector<A*> arr;
    
    arr.insert(arr.begin(),a);
    arr.insert(arr.begin()+1,b);
    arr.insert(arr.begin()+2,c);
    
    arr[0]->print();
    arr[1]->print();
    arr[2]->print();
    

    delete(arr[0]);
    delete(arr[1]);
    delete(arr[2]);
    
    return 0;
}
