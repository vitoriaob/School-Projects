#include"sorted.h"
#include <algorithm> 

SortedArray::SortedArray(){
    
}
SortedArray::~SortedArray(){
    numbers_.clear();
}

void SortedArray::AddNumber(int num){
     numbers_.push_back(num);
}
std::vector<int> SortedArray::GetSortedAscending(){
    std::sort (numbers_.begin(), numbers_.end());
    return numbers_;
}
std::vector<int> SortedArray::GetSortedDescending(){
    std::vector<int> aux;
    int i = numbers_.size()-1;
    std::sort (numbers_.begin(), numbers_.end());
    while(i>=0){
        aux.push_back(numbers_[i]);
        i--;
    }
    return aux;
}
int SortedArray::GetMax(){
    return *max_element(numbers_.begin(), numbers_.end());
}
int SortedArray::GetMin(){
    return *min_element(numbers_.begin(), numbers_.end());
}
