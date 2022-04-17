#include <iostream>
#include <string>
using namespace std;

void magicsquare(int** table, int n){
    int k, i, j, acti, actj;
    k = 1;
    i = 0;
    j = n/2;
    
    while(k <= (n*n)){
        
        table[i][j] = k;
        k++;
        acti = i;
        actj = j;
        i--;
        j++;
        
        if(i == -1)
            i = n-1;
        if(j == n)
            j= 0;
        if(table[i][j] != 0){
            i = acti+1;
            j = actj;
            if(i == -1)
              i = n-1;
        }
    }
}

void fillzeros(int** table, int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n ;j++)
            table[i][j] =0;
}


int main(int argc, char* argv[]){
    
    int n = stoi(argv[1]);
    
    if((n%2 != 0)&& n >= 3){
        
        int** matrix = new int*[n];
        for(int i = 0; i < n; ++i)
            matrix[i] = new int[n];
        
        fillzeros(matrix, n);
        magicsquare(matrix, n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout << matrix[i][j]<<" ";
            cout << endl;
        }
        for(int i = 0; i <n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}
