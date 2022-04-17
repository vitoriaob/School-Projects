#include <iostream>
#include <string>
using namespace std;

string add(string a, string b){
    return (a + "-" + b);
}

int add(int n, int m){
    return (n+m);
}

int main(){
    int x, y;
    string str1, str2;
    
    cin >> x >> y >> str1 >> str2;
    cout << add(x, y) << endl;
    cout << add(str1,str2)<< endl;
}
