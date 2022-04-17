#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1, str2, strf;
    
    cin >> str1;
    cin >> str2;
    
    strf = str1+str2;
    int n = str2.size();
    
    cout << strf << endl;
    cout << str1[0] << endl;
    cout << str2[n-1] << endl;
    
}
