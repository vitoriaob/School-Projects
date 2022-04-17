#include<iostream>
using namespace std;

int main(){
    int N, i, max, min;
    cin >> N;
    
    int* Narray = new int[N];
    
    cin >> Narray[0];
    max = Narray[0];
    min = Narray[0];
    
    for(i=1; i<N; i++){
        cin >> Narray[i];
        if(Narray[i] > max)
            max = Narray[i];
        else if(Narray[i] < min)
            min = Narray[i];
    }
    
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;

    delete[] Narray;

    return 0;
}
