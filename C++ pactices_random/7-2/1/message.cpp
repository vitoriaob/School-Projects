#include"message.h"
#include<iostream>
#include<vector>
#include<map>

MessageBook::MessageBook(){
    
}
MessageBook::~MessageBook(){
    messages_.clear();
}
void MessageBook::AddMessage(int number, const std::string& message){
        if(messages_.find(number) == messages_.end())
            messages_.insert({number, message});
        else
            messages_.at(number) = message;
}
void MessageBook::DeleteMessage(int number){
    messages_.erase(number);
}
 std::vector<int> MessageBook:: GetNumbers(){
       std:: vector<int> list;
       std:: vector<int>::iterator it;
       it = list.begin();
       for(auto elem: messages_)
           list.push_back(elem.first);

     return(list);
 }
 const std::string& MessageBook::GetMessage(int number){
     return(messages_.at(number));
 }
