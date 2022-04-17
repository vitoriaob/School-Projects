#include<stdio.h>

void rotateLeft(int* pa, int* pb, int* pc){
  int aux;
  aux = *pa;
  
  *pa = *pb;
  *pb = *pc;
  *pc = aux;  
}

void rotateRight(int* pa, int* pb, int* pc){
  int aux;
  int auxx; 
  aux = *pa;
  auxx = *pb;
  
  *pa = *pc;
  *pb = aux;
  *pc = auxx;
}

int main(void){
    int a, b, c, tmp;
    a = 10;
    b = 20;
    c = 30;
    
    printf("%d:%d:%d\n", a, b, c);
    scanf("%d", &tmp);
    
    while(tmp == 1 || tmp ==2){
        
        if(tmp ==1)
        rotateLeft(&a, &b, &c);
        
        else if(tmp ==2) 
        rotateRight(&a, &b, &c);
        
        printf("%d:%d:%d\n", a, b, c);
        scanf("%d", &tmp);
    }    
     
 
}
