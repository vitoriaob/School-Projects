#include <iostream>
#include <string>
using namespace std;

void printmatrix(int c, int l, string matrix[5][5]){
    matrix[l][c] = '*';
}
void printmatrix(string matrix[5][5]){
    int i, j;
    for(i=0; i<5; i++){
        for (j=0; j<5; j++){ 
            cout << matrix[i][j];
        }
        cout<< endl;
    }
    
}
int main(){
    int x, y, i, j, count = 0;
    string table[5][5];
    
    cin >> x >> y;
    for(i=0; i<5; i++)
        for (j=0; j<5; j++) 
            table[i][j] = '.';
    
    while( (x >= 0) && (y >= 0) && (x < 5) &&(y < 5)){
         printmatrix(x,y, table);
         printmatrix(table);
         
         count ++;
         if (count == 5)
            break;
         
         cin >> x >> y;
    }
    
    
}
