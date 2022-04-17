#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

FILE* fin;
FILE* fout;

int queue_array[101];
int top = -1;

typedef struct ThreadedTree* ThreadedPtr;
typedef int ElementType;
ThreadedPtr root;

typedef struct ThreadedTree{
    int left_thread;
    int right_thread;
    ThreadedPtr left_child;
    ThreadedPtr right_child;
    ElementType data;
}ThreadedTree;

ThreadedPtr CreateTree(){
    ThreadedPtr tree = NULL;
    tree = (ThreadedPtr)malloc(sizeof(ThreadedTree));
    if(tree == NULL){
        fprintf(fout, "no space");
        return NULL;
    }
    tree-> data = -1;
    tree->left_thread = 1;
   // tree->left_child = tree;
    tree->right_thread = 1;
  //  tree->right_child = tree;
    return tree;
}


ThreadedPtr InSucc(ThreadedPtr tree){
    ThreadedPtr tmp;
    tmp = tree->right_child;
    if(!tree->right_thread){
        while(!tmp->left_thread)
            tmp = tmp->left_child;
    }
    return tmp;
}
void printInorder(ThreadedPtr tree){
    ThreadedPtr tmp = tree;
    if(tree == NULL) fprintf(fout, "the tree is empty");
    
    fprintf(fout, "Inorder Transversal :");
    //reach leftmost node
    while(tmp->left_thread == 0) tmp = tmp->left_child;
    
    //one by one print sucessors
    while(tmp!=NULL){
        fprintf(fout, " %d", tmp->data);
        tmp = InSucc(tmp);
    }
}

int Insert(ThreadedPtr root,int root_idx,ElementType data,int idx){
    ThreadedPtr ptr = root;
    ThreadedPtr par = NULL;
    
    if(idx >= 100) return 0;
    
    while(ptr!=NULL){
        //if key already exists
        if(data == ptr->data) return 0;
        else if(ptr->data == -1) ptr->data = data;
        
        par = ptr; //actualizing parent pointer
       // printf("par data %d\n", par->data);
        
        //left subtree check
        if(data < ptr->data){
            if(ptr->left_thread == 0) ptr = ptr->left_child;
        }
        //right subtree
        else{
            if(ptr->right_thread == 0) ptr = ptr->right_child;
        }
        
        //creating new node
        ThreadedPtr tmp = (ThreadedPtr)malloc(sizeof(ThreadedTree));
        tmp->left_thread = 1;
        tmp->right_thread = 1;
        tmp->data = data;
        //printf("tmp %d\n", tmp->data);
        
         if(data < (par->data)){
            tmp->left_child = par->left_child;
            tmp->right_child = par;
            par->left_thread = 0;
            par->left_child = tmp;
           // printf("passei2 e inseri %d\n", tmp->data);
        }
        else{
            tmp->left_child = par;
            tmp->right_child = par->right_child;
            par->right_thread = 0;
            par->right_child = tmp;
           // printf("passei3 e inseri %d\n", tmp->data);
        }
        return 1;
    }
    
}



/*int Insert(ThreadedPtr root,int root_idx,ElementType data,int idx){
    ThreadedPtr node = CreateTree();
    node->data = data;
    
    if(root->data == -1){
        root->data = data;
        idx++;
    }
    while(1){
        node->data = data;
        
        if(node->left_thread){
            node->left_child = CreateTree();
            node->data = data;
            node->left_thread = 0;
            printf("passei2 e inseri %d\n", node->data);
            break;
        }
        else node->left_child->data = data;
        
        if(node->right_thread){
            node->right_child = CreateTree();
            node->data = data;
            node->right_thread = 0;
            printf("passei3 e inseri %d\n", node->data);
            break;
        }
        else  node->right_child->data = data;
    }
}*/

/*void printInorder(ThreadedPtr root){
    ThreadedPtr tmp = root;
    
    
    while(!tmp->left_thread){
        fprintf(fout, " %d", tmp->data);
        tmp = tmp->left_child;
    }
    while(!tmp->right_thread){
        fprintf(fout," %d", tmp->data);
        tmp = tmp->right_child;
    }
    if(tmp) fprintf(fout," %d", tmp->data);
}*/
void DeleteTree(ThreadedPtr root){
    if(root == NULL) return; 
    free(root);
}

void main(int argc, char *argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w"); 

    ThreadedTree* root;
    root = CreateTree();
    
    char test;
    fscanf(fin, "%c\n", &test);
    
    
    int numnodes = test - '0';

    int root_idx = 0, idx = 0;
     int data;
     
     while(++idx <= numnodes){
         ElementType data;
         fscanf(fin, "%c", &test);
         if(test == ' ') fscanf(fin, "%c", &test);
         data = test - '0';
           
         if(Insert(root, root_idx, data, idx) == 0){
             return;
            } 
        
              
     }   
     printInorder(root);
     //TransverseInorder(root);
     DeleteTree(root);
     
     fclose(fin);
     fclose(fout);

}
