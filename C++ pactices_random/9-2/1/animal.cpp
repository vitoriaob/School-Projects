#include<iostream>
#include "animal.h"

using namespace std;

void Animal::printInfo(){
    return;
}
void Zebra::printInfo(){
cout<< "Zebra, Name: "<<name<<", Age: "<<age<<", Number of stripes: "<< numStripes << endl;
}
void Cat::printInfo(){
cout<< "Cat, Name: "<<name<<", Age: "<<age<<", Favorite toy: "<< favoriteToy << endl;
}
