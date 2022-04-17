#include<iostream>
using namespace std;

void swapInt(int& n1, int& n2){
    int aux;
    aux = n1;
    n1 = n2;
    n2 = aux;
}

void swapString(string& s1, string& s2){
    string aux;
    aux = s1;
    s1 = s2;
    s2 = aux; 
}

int main(){
    int n1, n2;
    string s1, s2;
    cin >> n1 >> n2 >> s1 >> s2;
    
    cout << "n1: " << n1 << ", n2: " << n2 << ", s1: " << s1 << ", s2: " << s2 << endl;
    
    swapInt(n1, n2);
    swapString(s1, s2);
    
    cout << "n1: " << n1 << ", n2: " << n2 << ", s1: " << s1 << ", s2: " << s2 << endl;
    
    return 0;
}
