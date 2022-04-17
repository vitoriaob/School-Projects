#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fin;
FILE *fout;

typedef struct Node{
    int vertex;
    int dist;
    int prev;
}Node;

typedef struct Graph{
    int size;
    int **vertices;
    Node* nodes;
}Graph;

typedef struct Heap{
    int capacity;
    int size;
    Node* Element;
}Heap;

Graph* createGraph(int size){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->size = size;
    g->nodes = (Node*)malloc(size*sizeof(Node));
    g->vertices = (int**) malloc(size*sizeof(int*));
    for(int i = 0; i < size; i++){
        g->vertices[i] = (int*)malloc(size*sizeof(int));
         
    }

    for(int i; i < size; i++){
        for(int j; j < size; j++)
            g->vertices[i][j] = 0;
    }

   return g; 
}
void deleteGraph(Graph *G){
    for(int i; i < G->size; i++) {
        free(G->vertices[i]);
        }
     free(G->vertices);
     free(G->nodes);
     free(G);
}

Heap* createMinHeap(int heapsize){
     Heap* template = (Heap*) malloc(sizeof(Heap));
    template->Element = (Node*)malloc(heapsize*sizeof(Node));
    template->capacity = heapsize;
    template->size = 0;
    return template;

}
void deleteMinHeap(Heap* minheap){
    free(minheap->Element);
    free(minheap);
}

void swapMinHeapNode(Node* a, Node* b){
    Node t = *a;
    *a = *b;
    *b = t;
}
 void heapify(Heap* minHeap, int vertex){
     int smallest, left, right;
     smallest = vertex;
     left = 2 * vertex + 1;
     right = 2 * vertex + 2;
     
     if(left < minHeap->capacity && minHeap->Element[left].dist < minHeap->Element[smallest].dist)
         smallest = left;
     if(right < minHeap->capacity && minHeap->Element[right].dist < minHeap->Element[smallest].dist)
         smallest = right;
     
     if(smallest != vertex){
         Node smallestNode = minHeap->Element[smallest];
         Node idxNode = minHeap->Element[vertex];
         
        minHeap->Element[smallestNode.vertex].vertex = vertex;
         minHeap->Element[idxNode.vertex].vertex = smallest;
         
        swapMinHeapNode(&minHeap->Element[smallest], &minHeap->Element[vertex]);
         heapify(minHeap, smallest);
     }
 }
Node deleteMin(Heap* heap){
    if(heap->capacity == heap->size)
        printf("Is full \n");
    
    Node root = heap->Element[0];
    Node last = heap->Element[heap->size-1];
    heap->Element[0] = last;
    heap->size--;
    //heapify(heap, 1);
    
     int i = heap->size;
      while( i!= 0 && heap->Element[i-1].vertex > heap->Element[i].vertex){
             swapMinHeapNode(&heap->Element[i], &heap->Element[i-1]);
             i--;
        }
    return root;
    
}

void InsertToMinHeap(Heap* minHeap, int prev, int vertex, int distance){
    if(minHeap->capacity == minHeap->size) return;
    if(minHeap->Element[0].vertex == 0){ //case is empty
        minHeap->Element[0].vertex = vertex;
        minHeap->Element[0].dist = distance;
        minHeap->Element[0].prev = prev;
        minHeap->size++;
    }
    else if (distance !=0 ){
        int i = minHeap->size;
        minHeap->Element[i].vertex = vertex;
        minHeap->Element[i].dist = distance;
        minHeap->Element[i].prev = prev;
        minHeap->size++;
        
        while( i!= 0 && minHeap->Element[i-1].vertex > minHeap->Element[i].vertex){
            swapMinHeapNode(&minHeap->Element[i-1], &minHeap->Element[i]);
            i--;
        }
    }
}
void setNodes(Graph* g, Heap* h){
    int v = g->size;
    int count =0;
     for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(g->vertices[i][j]){
                g->nodes[count].prev = i;
                g->nodes[count].vertex = j;
                g->nodes[count].dist = g->vertices[i][j];
                count++;
            }
        }
    }
     
    
    //putting on the Heap
    int i =0;
    while(i < v && g->nodes[i].dist !=0){
        InsertToMinHeap(h, g->nodes[i].prev, g->nodes[i].vertex, g->nodes[i].dist);
        i++;
    }
  
}
void printShortestPath(Graph* g){
    int v = g->size;
    int w = 0;
    Node nodes[v];
    Heap* minHeap = createMinHeap(v);
    setNodes(g, minHeap);
    
    int currsize =1;
    
    while(minHeap->size){
        Node now = deleteMin(minHeap);
        nodes[currsize++] = now;
    }
    
    //making a char to print properly
    char convert[v*v];
    convert[0] = nodes[currsize-1].prev + '0';
    convert[1] = '-';
    convert[2] = '>';
    int c = 3;
    for(int i = currsize-1; i > 0; i--){
        if(nodes[i].prev>nodes[i].vertex) break;
        convert[c] = nodes[i].vertex + '0';
        convert[c+1] = ' ';
        //actualizing distances
        w +=nodes[i].dist;
        fprintf(fout,"%s(cost: %d)\n", convert, w);  
        // printing properly
        convert[c+1] = '-';
        convert[c+2] = '>';
        c+=3;
    }
    
    //checking if it reached the final vertex and printing    
    if(currsize < v){
        int sobre = v - currsize;
        int count = 0;
        while(sobre){
                fprintf(fout, "Cannot reach to node %d\n", v-1-count);
                count++;
                sobre--;
        }
    
    }
    
    deleteMinHeap(minHeap);
}

void main(int argc, char* argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    
    int size;
    Graph* g;
   
    fscanf(fin, "%d\n", &size);
    
     g = createGraph(size+1);
    char tmp = 0;
    while(tmp != '\n'){
        int node1, node2, weight;
        fscanf(fin, "%d-%d-%d", &node1, &node2, &weight);
        g->vertices[node1][node2] = weight;
        tmp = fgetc(fin);
    }
 
    printShortestPath(g);
    deleteGraph(g);
}
