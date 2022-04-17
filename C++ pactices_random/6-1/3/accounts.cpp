#include "accounts.h"
using namespace std;

void AccountManager::initialize(){
    for(int i =0; i<10; i++)
        accounts[i].ID = -1;
}
void AccountManager::create(int num){
    accounts[num].ID = num;
    accounts[num].ballance = 0;
    cout << "Account for user "<<num<<" registered"<<endl;
     ballancecheck(num);
}

void AccountManager::deposit(int account, int value){
    
    if(value > 1000000 || value < 0)
        cout<< "Deposit ammount not possible." << endl;
    else if(accounts[account].ID != -1){
       accounts[account].ballance += value;
       cout << "Success: Deposit to user "<< account<<" "<< value << endl; 
       ballancecheck(account);
    }
    else 
        cout << "Account does not exist"<<endl;
    
}
void AccountManager::withdraw(int account, int value){
    
    if(value > 1000000 || value < 0)
        cout<< "Withdraw ammount not possible." << endl;
    else if(accounts[account].ID != -1 && accounts[account].ballance >=value ){
       accounts[account].ballance -= value;
       cout << "Success: Withdraw from user "<< account<< " "<< value << endl;
        ballancecheck(account);
    }
    else if(accounts[account].ID != -1 && accounts[account].ballance <value){
        cout << "Failure: Withdraw from user "<< account<< " "<< value << endl;
         ballancecheck(account);
    }
    else 
        cout << "Account does not exist"<<endl;
        
}
void AccountManager::transfer(int accountmain, int accountsource, int value){
    
    if(value > 1000000 || value < 0)
        cout<< "Transfer ammount not possible." << endl;
    else if(accounts[accountmain].ID != -1 && accounts[accountsource].ID != -1 && accounts[accountmain].ballance >=value ){
       accounts[accountmain].ballance -= value;
       accounts[accountsource].ballance +=value;
       cout << "Success: Transfer from user "<<accountmain<< " to user "<< accountsource<< " "<< value << endl; 
       ballancecheck(accountsource); 
       ballancecheck(accountmain);
    }
    else if(accounts[accountmain].ID != -1 && accounts[accountsource].ID != -1 && accounts[accountmain].ballance <value){
        cout << "Failure: Transfer from user "<<accountmain<< " to user "<< accountsource<< " "<< value << endl; 
        ballancecheck(accountsource);
        ballancecheck(accountmain);
    }
    else 
        cout << "Account does not exist"<< endl;
}
void AccountManager::ballancecheck(int account){
    cout<< "Balance of user " << accounts[account].ID <<": "<< accounts[account].ballance<<endl;
}
