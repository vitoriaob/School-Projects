#include<iostream>
#include "number.h"

int Square::getSquare(){
    return Number::getNumber()*Number::getNumber();
}

int Cube::getCube(){
    return Number::getNumber()*Square::getSquare();
} 
