#include<stdio.h>
#include<stdlib.h>

FILE *input;
FILE *output;

// Structures declaration
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node{
   ElementType element;
   Position  next;
};

List MakeEmpty(List L){ //Creating empty list! 
    L = (List) malloc(sizeof(struct Node));
    L->next = NULL;
    L->element = -1; // setting the head element as -1
    return L;
}
int IsEmpty(List L){ //check if the list L is empty
   return L->next == NULL;
}
int IsLast(Position P, List L){
    if (P == NULL) return 1;   //Checking if the position exists
    else if (P->next == NULL) return 1;  //Checking if the next is null, meaning its the last value
    else return 0;
}
Position Find(ElementType X, List L){
    Position tmp = L;
    while(tmp!=NULL && tmp->element != X){ //Searching in the list one by one untill the end of the list or until it finds the element X
        tmp = tmp->next;
    }
    return tmp;
}
Position FindPrevious(ElementType X, List L){ //Finding the previous element
    Position tmp = L;
    Position test = Find(X,L); //Check if the the element X is in the list
    if(test == NULL){
        return NULL;
    }
    while(tmp->next->element!= X && tmp->next!= NULL)  //search one by one by the element in the next node
        tmp = tmp->next;
    return tmp; //return the previous
}
void Insert(ElementType X, List L, Position P){ //Insertion
    Position tmp;
    if(P == NULL){ //Check if the position P is valid
       fprintf(output, "Insertion(%d) Failed: cannot find the location to be inserted\n", X); 
    }
    else { // create a new node and insert in the given position 
        tmp = (Position) malloc(sizeof(struct Node));
        tmp->element = X;
        tmp->next = P->next;
        P->next = tmp;
    }
}
void PrintList(List L){ // Print list from the next node after the header
    Position tmp = L->next;
    if(IsEmpty(L)) fprintf(output, "Empty List!");
    while(tmp != NULL){
        fprintf(output, "key:%d\t", tmp->element);
        tmp = tmp->next;
    }
    fprintf(output, "\n");
}
void Delete(ElementType X, List L){ //Delete element
    Position P, tmp;
    P = FindPrevious(X, L);
    if(P == NULL){ //Check if the element X is in the list
        fprintf(output, "Deletion(%d) Failed: Element %d is not in the list\n", X, X);
    }
    else if(!IsLast(P,L)){
        tmp = P->next;
        P->next = tmp->next;
        free(tmp);
    }
}
void DeleteList(List L){ //deleting list and freeing the memory
     Position P, tmp;
     P= L->next;
     L->next = NULL;
     while(P!=NULL){
     tmp = P->next;
     free(P);
     P = tmp;
     }
}

int main(int argc, char *argv[]) {
    char command;
    int key1, key2;
   // FILE *input;
    Position header = NULL;
    Position tmp = NULL;    
    if (argc == 1){
        input = fopen("input.txt", "r");
        output = fopen("output.txt", "w");  
    }
    else{
        input = fopen(argv[1], "r");
        output = fopen(argv[2], "w");
    }
    header = MakeEmpty(header);

    while (1) {

       command = fgetc(input);
       
       if(feof(input)) 
               break;
       
       switch (command) {
            
            case 'i':
                fscanf(input, "%d %d\n", &key1, &key2);
                //duplication check
                tmp= Find(key1, header);
                if (tmp!= NULL) {
                    fprintf(output, "There already is an element with key %d. Insertion failed\n", key1);
                }
                else{
                     tmp= Find(key2, header);
                     Insert(key1, header, tmp);
                }
                break;

            case 'd':
                fscanf(input, "%d\n", &key1);
                Delete(key1, header);
                break;
            
            case 'f':
                fscanf(input, "%d\n", &key1);
                tmp = FindPrevious(key1, header);
                if (IsLast(tmp, header))
                    fprintf(output, "Finding (%d) Failed: Element %d is not in the list\n", key1, key1);
                else {
                    if (tmp->element > 0)
                        fprintf(output, "Key of previous node of %d is %d.\n", key1, tmp->element); 
                    else
                        fprintf(output, "Key of previous node of %d is header.\n", key1);
                    }
                break;
            case 'p':
                PrintList(header);
                break;
           
            default:
               break;
        }
    }
    
    DeleteList(header);
    fclose(input);
    fclose(output);
    return(0);
}
