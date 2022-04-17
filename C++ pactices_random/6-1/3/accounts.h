#include<iostream>

class Account{
public: 
    int ID;
    int ballance;
};

class AccountManager{
public: 
    Account accounts[10];
    int num;
public:
    void initialize();
    void create(int num);
    void ballancecheck(int account);
    void deposit(int account, int value);
    void withdraw(int account, int value);
    void transfer(int accountmain, int accountsource, int value);
};
