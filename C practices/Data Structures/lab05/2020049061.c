#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

FILE* fin;
FILE* fout;
int printvalues[101]; //auxiliary array to print the numbers withou a space in the end
int count = 0;


typedef struct BST* Tree;
typedef struct BST{
    int value;
    struct BST* left;
    struct BST* right;
}BST;

Tree insertNode(Tree tree, int key){
    //in case is the first number
    if(tree == NULL){
        tree = (Tree) malloc(sizeof(struct BST));
        tree->value = key;
        tree->left = tree->right = NULL;
        
    }
    else if(key < tree->value){
        tree->left = insertNode(tree->left, key);
    }
    else if(key > tree->value){
        tree->right = insertNode(tree->right, key);
    }
    else{ //if its already in the tree
        return NULL;
    }
    return tree;
}
int findNode(Tree root, int key){
    //if cant find the key
    if(root == NULL) return 0;
    if(key < root->value) return findNode(root->left, key);
    if(key > root->value) return findNode(root->right, key);
    //if find the key
    if(key == root->value) return 1;
}

Tree FindMin(Tree root){ //auxiliary function to find the minimum leaf
    if(root == NULL) return NULL;
    if(root->left == NULL) return root;
    return FindMin(root->left);
}

Tree deleteNode(Tree root, int key){
    Tree tmp;
    if(root == NULL) return NULL;
    else if (key < root->value) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->value) {
        root->right = deleteNode(root->right, key);
    } 
    else{
        // case 1: no leaves
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        } 
        //case 2: no left leaf
        else if(root->left == NULL){
            Tree aux = root->right;
            free(root);
            return aux;
        }
        //case 3: no right leaf
        else if(root->right == NULL){
            Tree aux = root->left;
            free(root);
            return aux;
        }
        //case 4: both leaves - finding the right node to delete
        else { 
            tmp = FindMin(root->right);
            root->value = tmp->value;
            root->right = deleteNode(root->right, tmp->value);
        }
    }
    
    return root;
}

void printInorder(Tree root){
    if(root == NULL) return;

    printInorder(root->left);
    printvalues[count++] = root->value; //I'm using an array to print the numbers withou a space in the end
    printInorder(root->right);   
}

void deleteTree(Tree root){
    if(root == NULL) return;
     deleteTree(root->left);
     free(root);
     deleteTree(root->right);
}


void main(int argc, char *argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w"); 
    
    Tree root = NULL;
    
    int key, flagfirst = 1;
    char  command;
    
     while (!feof(fin)) {
       fscanf(fin, "%c", &command);
       switch (command) {
            
            case 'i':
                fscanf(fin, "%d", &key);
                if(flagfirst ==1){
                    root = insertNode(root, key);
                    fprintf(fout, "insert %d\n", key);
                    flagfirst--;
                    break;
                }
                
                if (insertNode(root, key)) {
                    fprintf(fout, "insert %d\n", key);
                    
                }
                else{
                     fprintf(fout, "Insertion Error: %d is already in the tree\n", key);
                }
                break;
            case 'f':
                fscanf(fin, "%d", &key);
                if (findNode(root, key) == 1) {
                    fprintf(fout, "%d is in the tree\n", key);
                }
                else{
                     fprintf(fout, "Finding Error: %d is not in the tree\n", key);
                }
                break;
            case 'd':
                fscanf(fin, "%d", &key);
                //deleting
                // checking if the key is at the tree
                if (findNode(root, key) != 0) {
                   if(deleteNode(root, key))
                    fprintf(fout, "delete %d\n", key);
                    
                }
                else{
                    fprintf(fout, "Deleting Error: %d is not in the tree\n", key);
                }
                break;
            case 'p':
                fscanf(fin, "%c", &command);
                if(command =='i'){
                    //printing innorder
                    if(root == NULL) fprintf(fout,"Tree is empty\n");
                    else{
                        //procedure to print the array filled in the print inorder function
                        int i;
                        printInorder(root); 
                        fprintf(fout, "%d",printvalues[0]);
                        for(i = 1; i< count; i++)
                            fprintf(fout, " %d", printvalues[i]);
                        count= 0;   // to start in the array again
                        fprintf(fout, "\n"); 
                    }
                }
                break;
        }
 
     }
    
    deleteTree(root);
}
