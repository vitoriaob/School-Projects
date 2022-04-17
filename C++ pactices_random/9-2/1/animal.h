#include<iostream>
#include<string>

using namespace std;

class Animal{
protected:
    string name;
    int age;
public:
    Animal(string n, int a){ name = n; age = a;}
    virtual void printInfo();
};

class Zebra:public Animal{
protected:
    int numStripes;

public:
    Zebra(string n, int a, int stripes): Animal(n,a), numStripes(stripes){}
    
    virtual void printInfo();
};

class Cat: public Animal{
protected:
    string favoriteToy;
public:    
    Cat(string n, int a, string toy): Animal(n, a), favoriteToy(toy){}
    
    virtual void printInfo();
};
