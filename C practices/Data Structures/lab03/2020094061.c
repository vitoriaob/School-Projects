#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

FILE* fin;
FILE* fout;

typedef struct Stack{
    int* key;
    int top;
    int max_stack_size;
}Stack;

Stack* CreateStack(int max){
    Stack* S = NULL;
    S = (Stack*)malloc(sizeof(Stack));
    S->key = (int*)malloc(sizeof(int)*max);
    S->max_stack_size = max;
    S->top = -1;
    return S;
}
int IsEmpty(Stack* S){
    if(S->top == -1) return 1;
    else return 0;
}
int IsFull(Stack* S){
    if(S->top >= 20) return 1;
    else return 0;
}
void Push(Stack* S, int X){
    if(!IsFull(S))
        S->key[++(S->top)] = X;
}
int Top(Stack* S){
    if(IsEmpty(S)) return 0;
    else return S->key[S->top];
}
int Pop(Stack* S){
    int value = Top(S);
    if(IsEmpty(S)) return 0;
    else{
        S->top--;
        return value;
    }
}
void DeleteStack(Stack* S){
     while(S->top!=-1)
         Pop(S);
     free(S);
}


void main(int argc, char *argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w"); 
    
    Stack* stack;
    char input_str[101];
    int max = 20, i=0, a, b, result;
    int error_flag = 0;
    
    fgets(input_str, 101, fin);
    stack = CreateStack(max);
    
    fprintf(fout, "Top Numbers :");
    
    while(input_str[i] != '#' && !error_flag){
        
        if(isdigit(input_str[i])){ //Checking if is digit 
            if(stack->top >= 20){ //checking if stack is full;
                fprintf(fout, "\nError : Invalid Postfix Expression, Stack is Full!\n");
                error_flag = 1;
            }
            else Push(stack, (input_str[i] - '0'));
        }
    
        else if (input_str[i] == '+' || input_str[i] == '-' || input_str[i] == '*' || input_str[i] == '/' || input_str[i] == '%') { //check operation
            
            if(IsEmpty(stack)){  //check if stack is empty for variable 'a'
                fprintf(fout, "\nError : Invalid Postfix Expression, Stack is Empty!\n"); 
                error_flag = 1;
            }
            else a = Pop(stack);
            
            if(IsEmpty(stack)){ //check if stack is empty for variable 'b'
                fprintf(fout, "\nError : Invalid Postfix Expression, Stack is Empty!\n");
                error_flag = 1;
            }
            else b = Pop(stack);
            
            
            switch (input_str[i])  // making the operations
            {
            case '*':
                result = b * a;
                break;

            case '/':
                if(a == 0) { //checking if divides by zero
                    fprintf(fout, "\nError : Invalid Postfix Expression, Divide by Zero!\n");
                    error_flag = 1;
                }
                else result = b / a;
                break;

            case '+':
                result = b + a;
                break;

            case '-':
                result = b - a;
                break;
                
            case '%':
                if(a == 0) { //check if divides by zero
                    fprintf(fout, "\nError : Invalid Postfix Expression, Divide by Zero!\n");
                    error_flag = 1;
                }
                else result = b % a;
                break;
                }
                
            // push the value obtained above onto the stack 
            Push(stack, result);
        }
       if(!error_flag) fprintf(fout, " %d", Top(stack)); //check if there was any error
       i++;
       
    }
     if(stack->top > 0){ //check if there's remaining numbers at the stack
           fprintf(fout, "\nError : Invalid Postfix Expression, %d numbers are left!\n", stack->top);
       }
     else if(!error_flag) fprintf(fout,"\nEvaluation Result : %d\n", Pop(stack));
    
    fclose(fin);
    fclose(fout);
    DeleteStack(stack); 
    
}
