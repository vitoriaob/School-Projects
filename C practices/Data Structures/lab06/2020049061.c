#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef int ElementType;

typedef struct AVLNode{
    ElementType element;
    AVLTree left, right;
    int height;
}AVLNode;

int Height(Position p){ //function to return the height of the leaves when necessary
    if(p==NULL) return -1;
    return p->height;
}

Position SingleRotationWithLeft(Position node){ //performing singe rotation to left
    int max;
    Position tmp;
    //swaping the nodes
    tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    //adjusting height values
    if (Height(node->left) > Height(node->right)) max = Height(node->left);
    else max = Height(node->right);
    
    node->height = max+1;
    
    if (Height(tmp->left) > node->height) max = Height(tmp->left);
    else max = node->height;
    
    tmp->height = max+1;
    
    return tmp;
}
Position SingleRotationWithRight(Position node){ //performing single rotation to right
    int max;
    Position tmp;
    //swaping the nodes 
    tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    //adjusting height values
    if (Height(node->left) > Height(node->right)) max = Height(node->left);
    else max = Height(node->right);
    
    node->height = max+1;
    
    if (Height(tmp->right) > node->height) max = Height(tmp->right);
    else max = node->height;
    
    tmp->height = max+1;
    
    return tmp;
}
Position DoubleRotateWithLeft(Position node){ //rotate Left-Right
    node->left = SingleRotationWithRight(node->left);
    return SingleRotationWithLeft(node);
}
Position DoubleRotateWithRight(Position node){ //rotate Right-Left
    node->right = SingleRotationWithLeft(node->right);
    return SingleRotationWithRight(node);
}

int findNode(AVLTree T, int X){ //auxiliary function to dont insert two same values
    //if cant find the key
    if(T == NULL) return 0;
    if(X < T->element) return findNode(T->left, X);
    if(X > T->element) return findNode(T->right, X);
    //if find the key
    if(X == T->element) return 1;
}

AVLTree Insert(ElementType X, AVLTree T){
    //check if element is in tree
    if(findNode(T, X)){
        fprintf(fout, "Insertion Error: %d is already in the tree!\n", X);
        return T;
    }
    
    if(T == NULL){
        T = malloc(sizeof(struct AVLNode));
        T->element = X;
        T->height = 0;
        T->left = T->right = NULL;
    }
    else if(X < T->element){
        T->left = Insert(X, T->left);
        if(Height(T->left)- Height(T->right) >= 2){
            if(X < T->left->element){
                T = SingleRotationWithLeft(T);
            } 
            else{
                T = DoubleRotateWithLeft(T);
            }
        }
    }
    else if(X > T->element){
        T->right = Insert(X, T->right);
        
        if(Height(T->right)- Height(T->left) == 2){
            if( X > T->right->element){
              T = SingleRotationWithRight(T);
          }
            else{
            T = DoubleRotateWithRight(T);
            }
        }     
    }
    
    if(Height(T->left) > Height(T->right)) T->height = Height(T->left) +1;
    else  T->height = Height(T->right) +1;
    
    return T;
}

AVLTree FindMin(AVLTree root){ //auxiliary function to find the minimum leaf
    if(root == NULL) return NULL;
    if(root->left == NULL) return root;
    return FindMin(root->left);
}

AVLTree Delete(ElementType X, AVLTree T){
    AVLTree tmp = NULL;
    
    if(T == NULL) fprintf(fout, "Deletion Error: %d is not in the tree!\n", X);
    
    else if(X < T->element){
         T->left = Delete(X, T->left);
         if(Height(T->left) - Height(T->right) == -2){
             if(Height(T->right->right) > Height(T->right->left))
                 T = SingleRotationWithRight(T);
             else T = DoubleRotateWithRight(T);
             
         }
     }
    else if( X > T->element){
         T->right = Delete(X, T->right);
         if(Height(T->right)-Height(T->left) == -2){
             if(Height(T->left->left) > Height(T->left->right)) T = SingleRotationWithLeft(T);
             else T = DoubleRotateWithLeft(T);
         }
     }
    else if(T->left && T->right){ //has two leaves
        //replacing wirh the smallest subtree at right
        tmp = FindMin(T->right);
        T->element = tmp->element;
        T->right = Delete(T->element, T->right);
        if(Height(T->right)-Height(T->left) == -2){
             if(Height(T->left->left) > Height(T->left->right)) T = SingleRotationWithLeft(T);
             else T = DoubleRotateWithLeft(T);
        }
    }
    else{
       tmp = T;
       T = T->left ? T->left: T->right;
       free(tmp);
    }
    if(T!=NULL){
        if(Height(T->left) > Height(T->right)) T->height = Height(T->left) +1;
        else  T->height = Height(T->right) +1;
    }
    return T;
}

void PrintInorder(AVLTree T){
    if(T == NULL) return;
    PrintInorder(T->left);
    fprintf(fout, "%d(%d) ", T->element, T->height); 
    PrintInorder(T->right);  
}
void DeleteTree(AVLTree T){
    if(T == NULL) return;
     DeleteTree(T->left);
     free(T);
     DeleteTree(T->right);
}

int main(int argc, char *argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    AVLTree Tree = NULL;
    AVLTree root = NULL;
    char cv;
    int key;
    
    while(!feof(fin)){
        fscanf(fin, "%c", &cv);
        switch(cv){
            case 'i':
                fscanf(fin, "%d\n", &key);

                Tree = Insert(key, Tree);
        
                break;
            case 'd':
                fscanf(fin, "%d\n", &key);
                Tree = Delete(key, Tree);
                break;
        }
        PrintInorder(Tree);
        fprintf(fout, "\n");
    }
    
    DeleteTree(Tree);
    fclose(fin);
    fclose(fout);
    
    return 0;
}
