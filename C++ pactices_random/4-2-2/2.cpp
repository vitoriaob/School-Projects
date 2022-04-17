#include<iostream>
using namespace std;

void bubblesort(int* array, int n){
    int tmp;
    
    for(int i=1; i<n; i++){
        for(int k=0; k<(n-i); k++){
            if(array[k] > array[k+1]){
                tmp = array[k];
                array[k] = array[k+1];
                array[k+1] = tmp;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    if(n > 0){
        
        int* array = new int[n];
    
        for(int i=0; i<n; i++)
            cin >> array[i];
    
        bubblesort(array,n);
    
        for(int i=0; i<n; i++)
            cout << array[i] << " ";
        cout << endl;
    
        delete[] array;
    }    
    return 0;
}
