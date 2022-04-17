#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE* fin;
FILE* fout;

typedef struct _Queue{
    int* key;
    int front, rear, qsize, max_queue_size;
}Queue;

typedef struct _Graph{
    int size;
    int* node;
    int** matrix;
}Graph;

Queue* MakeNewQueue(int X){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->max_queue_size = X;
    q->front = q->qsize = 0;
    q->rear = X-1;
    q->key = (int*)malloc(q->max_queue_size * sizeof(int));
    return q;
}
int IsEmpty(Queue* Q){
    return (Q->qsize == 0);
}
int Dequeue(Queue* Q){
    if(IsEmpty(Q))
        return 0;
    int item = Q->key[Q->front];
    Q->front = (Q->front +1) % Q->max_queue_size;
    Q->qsize--;
    return item;
}
void Enqueue(Queue* Q, int X){
    Q->rear = (Q->rear+1)% Q->max_queue_size;
    Q->key[Q->rear] = X;
    Q->qsize++;
}
void DeleteQueue(Queue* Q){
    while(!IsEmpty){
        Dequeue(Q);
    }
    free(Q);
}

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int* arr, int n){
    int i, j;
    for (i = 0; i < n-1; i++)    
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
  
Graph* CreateGraph(int* nodes, int n){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->node = (int*)malloc(n* sizeof(int));
    G->matrix = (int**) malloc(n* sizeof(int*));
    G->size = n;
    for(int i = 0; i < n; i++)
        G->matrix[i] = (int*)malloc(n*sizeof(int));
    
    //filling the matrix
    bubbleSort(nodes, n);
    for(int i=0; i<n; i++){
        G->node[i] = nodes[i];
        for(int j = 0; j<n; j++)
            G->matrix[i][j] = 0;
    }

    return G;
}
int findpos(int* x, int n, int value){
    for(int i = 0; i < n; i++)
        if(x[i] == value) return i;
}
void InsertEdge(Graph* G, int a, int b){
    // creating the adjacency matrix
    int tmp1, tmp2;
  
    tmp1 = findpos(G->node,G->size, a);
    tmp2 = findpos(G->node,G->size, b);
    G->matrix[tmp1][tmp2] =  1;    
    
}
void PrintGraph(Graph* G){
    fprintf(fout,"   ");
    for(int i = 0; i < G->size; i++)
        fprintf(fout,"%d  ", G->node[i]);
    fprintf(fout,"\n");
    
    for(int i = 0; i < G->size; i++){
        fprintf(fout,"%d  ", G->node[i]);
        for(int j =0; j < G->size; j++){
            fprintf(fout,"%d  ", G->matrix[i][j]);
        }
        fprintf(fout,"\n");
    }
    fprintf(fout,"\n");
}
void DeleteGraph(Graph* G){
     for(int i; i < G->size; i++) 
         free(G->matrix[i]);
     free(G->matrix);
     free(G->node);
    free(G);
}
void indeegrees(Graph* G, int* indg, int* indegree, int n){
    int v;
    for(int i = 0; i < G->size; i++) indegree[i] = 0;
    for(int i = 0; i < n; i++){
        v = findpos(G->node,G->size, indg[i]);
        indegree[v]++;
    }
//     for(int i = 0; i < G->size; i++) printf("%d ", indegree[i]);
//     printf("\n");
}
void checkcycle(Graph* G);
void Topsort(Graph* G, int* in_degrees){
    Queue* Q =  MakeNewQueue(G->size);
    int v[G->size];
    int it=0;
    int pos;
    
    for(int i= 0; i < G->size; i++){
        pos = findpos(G->node, G->size, G->node[i]);
        if(in_degrees[i] == 0) Enqueue(Q, G->node[pos]);
    }

    while(!IsEmpty(Q)){
        int w;
        w = Dequeue(Q);
        v[it]= w;
        it++;
       // printf("%d ", w);
        pos = findpos(G->node, G->size, w);
        for(int i = pos; i < G->size; i++){
            in_degrees[i]--;
            if(in_degrees[i] == 0) Enqueue(Q, G->node[i]);
        }
    }
    int flag = 1;
    for(int i = 0; i < G->size-1; i+=2){
        if(v[i] > v[i+1]) flag =0;
    }
    if(flag){
        for(int i = 0; i < G->size; i++)
            fprintf(fout,"%d ", v[i]);
        fprintf(fout,"\n"); 
    }
    else fprintf(fout,"Sorting Error: Cycle!\n");
    
   
  
}

void countInput(int* n, char* str){
    int len = strlen(str), i;
    for(i = 0; i < len; i++)
        if(0 <= str[i] - '0' && str[i] - '0' < 10) (*n)++;
}
void parseInput(int* arr, char* str, int n){
    int len = strlen(str), i;
    int cnt = 0;
    for(i = 0; i < len; i++){
        if(isdigit(str[i])){
            arr[cnt] = str[i] - '0';
            cnt++;
        }
    }
}

int main(int argc, char* argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    
    char numbers[100], inputs[150];
    fgets(numbers, 100, fin);
    int n = 0;
    countInput(&n, numbers);
    int nodes[n];
    parseInput(nodes, numbers, n);
    int countin=0;
    

    Graph* G = CreateGraph(nodes, n);
    
    fgets(inputs, 100, fin);
    int len = strlen(inputs), i, j;
    for(i=0; i<len; i+=4){
        int a = inputs[i] - '0';
        int b = inputs[i + 2] - '0';
        countin++;
         InsertEdge(G, a, b);
    }
   
    int indg[countin];
    int count = 0;
    for(i=0; i<len; i+=4){
        int b = inputs[i + 2] - '0';
        indg[count] = b;
        count++;
    }

    
    int in_degrees[n];
    indeegrees(G, indg, in_degrees, countin);
    
    PrintGraph(G);
    Topsort(G, in_degrees);
    DeleteGraph(G);
    
    return 0;
}
