#include<vector>
#include<iostream>
#include<algorithm>
#include "intset.h"

IntegerSet::IntegerSet(){
    
}
IntegerSet::~IntegerSet(){
    numbers_.clear();
}

void IntegerSet::AddNumber(int num){
    std::vector<int>::iterator check;
    check = std::find (numbers_.begin(), numbers_.end(), num);
//     if(check == numbers_.end())
    numbers_.push_back(num);
}
void IntegerSet::DeleteNumber(int num){
    numbers_.erase(std::remove(numbers_.begin(), numbers_.end(), num), numbers_.end());
}
int IntegerSet::GetItem(int pos){
    if(pos > numbers_.size())
        return -1;
    else
        return numbers_[pos];
}
std::vector<int> IntegerSet::GetAll(){
    return numbers_;
}
