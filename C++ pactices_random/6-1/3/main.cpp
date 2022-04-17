#include<iostream>
#include "accounts.h"

using namespace std;

int main (){
    char job;
    int id, id2, money;
    AccountManager bank;
    
    bank.num = 0;
    bank.initialize();
    
    while(1){
        cout << "Job? " <<endl;
        cin >> job;
        
        if(job == 'N'){
            bank.create(bank.num);
            bank.num++;
        }
        else if (job == 'D'){
            cin >> id >> money;
            bank.deposit(id, money);
        }
        else if (job == 'W'){
            cin >> id >> money;
            bank.withdraw(id,money);
        }
        else if (job == 'T'){
            cin>>id>>id2>>money;
            bank.transfer(id,id2,money);
        }
        else if (job == 'Q')
            break;
        
        if(bank.num >9)
            break;
        
    }
}
