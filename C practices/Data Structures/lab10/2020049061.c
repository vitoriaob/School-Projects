#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

typedef struct BNode* BNodePtr;

struct BNode{
    int order;
    int size;
    BNodePtr *child;
    int *key;
    int is_leaf;
}BNode;


BNodePtr CreateTree(int order){
    BNodePtr b = (BNodePtr)malloc(sizeof(struct BNode));
    b->is_leaf = 1;
    b->size = 0;
    b->order = order;
    b->child = (BNodePtr*)malloc(2*order * sizeof(BNodePtr));
    b->key = (int*)malloc((2*order-1) * sizeof(int));
    for(int i = 0; i< order+1; i++){
        b->child[i] = NULL;
    }
    return b;
}



BNodePtr splitNode (BNodePtr x, int i, BNodePtr y) {
    int j;
    BNodePtr z = CreateTree(x->order);
    int T = x->order;
    z->size = T - 1;

    for (j = 0; j < T - 1; j++){
        z->key[j] = y->key[j+T];
    }

    if (y->is_leaf == 0)
    {
        for (j = 0; j < T; j++){
            z->child[j] = y->child[j+T];
        }
    }

    y->size = T - 1;

    for (j = x->size; j >= i+1; j--){
        x->child[j+1] = x->child[j];
    }

    x->child[i+1] = z;


    for (j = x->size-1; j >= i; j--){
        x->key[j+1] = x->key[j];
    }

    x->key[i] = y->key[T-1];


    x->size++;


   return x;
}
BNodePtr InsertNonFull(BNodePtr root, int a){
   int i = root->size-1;
   
    if(root->is_leaf){
        while(i >= 0 && root->key[i]> a){
            root->key[i+1] = root->key[i];
            i--;
        }
        root->key[i+1] = a;
        root->size++;
    }
    else
    {
        while (i >= 0 && root->key[i] > a){
            i--;
        }

        i = i + 1;

        if (root->child[i]->size == 2*root->order-1){
            root = splitNode(root, i, root->child[i]);

            if (a > root->key[i]){
                i = i + 1;
            }
        }

        root->child[i] = InsertNonFull(root->child[i], a);
    }

    return root;
}
BNodePtr Insert(BNodePtr root, int key){
    BNodePtr r = root;
    if(r->size == 2*r->order -1){
        BNodePtr s = CreateTree(root->order);
        s->is_leaf = 0;
        s->child[0] = r;
        s= splitNode(s, 0, r);
        s = InsertNonFull(s, key);
        return s;
    }
    else{
        return InsertNonFull(r, key);
    }
}

int Find(BNodePtr root, int key){
    
    BNodePtr high = root;
    int flag = 1;
    while(flag){
        int pos;
        for(pos = 0; pos < high->size; pos++){
            if(key == high->key[pos]) return 1;
            else if(key < high->key[pos]) break;
        }
        if(high->is_leaf) break;
        high = high->child[pos];
    }
    return 0;
}

void PrintTree(BNodePtr a){
    int i = 0;
    
    if(!a ){
        fprintf(fout, "Print Error: tree is empty!.\n");
        return;
    }
     while(a->key[i]!=0){
      fprintf(fout,"%d ", a->key[i]);
      i++;
     }

   while(a->key[i]!=0){
      if (a->is_leaf == 0) {
         PrintTree(a->child[i]);
      }
      i++;
   }
}


void DeleteTree(BNodePtr a){
     int i;
     for (i = 0; i < a->size; i++) {
        free(a->child[i]);
     }

   for (i = 0; i <= a->size; i++) {
      if (a->is_leaf == 0) {
         DeleteTree(a->child[i]);
      }
   }
 free(a);
} 

void main(int argc, char* argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    
    int order;
    fscanf(fin, "%d", &order);
    BNodePtr root = CreateTree(order);
    
    char cv;
    int key;
    while(!feof(fin)){
        fscanf(fin, "%c", &cv);
        switch(cv){
            case 'i':
                fscanf(fin, "%d", &key);
                if(Find(root, key))
                    fprintf(fout, "Insertion Error: key %d is already in the tree!\n", key);
                else
                    Insert(root, key);
                break;
            case 'f':
                fscanf(fin, "%d", &key);
                if(Find(root, key))
                    fprintf(fout, "Find key %d\n", key);
                else
                    fprintf(fout, "Finding Error: key %d is not in the tree!\n", key);
            case 'p':
                PrintTree(root);
                fprintf(fout,"\n");
                break;
        }
    }
    
    DeleteTree(root);
    fclose(fin);
    fclose(fout);
    return;
}
