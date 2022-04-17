#include<stdio.h>
#include<stdlib.h>
#define INF 1e9

FILE *fin;
FILE *fout;

typedef struct HeapStruct{
    int capacity;
    int size;
    int *elements;
}Heap;

Heap* CreateHeap(int heapSize){
    Heap* template = (Heap*) malloc(sizeof(struct HeapStruct));
    template->elements = (int*)malloc(sizeof(int)*heapSize);
    template->capacity = heapSize;
    template->size = 0;
    return template;
}

int IsFull(Heap *heap){
    if(heap->capacity == heap->size) return 1;
    else return 0;
}

void heapify(Heap *heap, int i){
    int max = i;
    int left = 2*i +1;
    int right = 2*i +2;
    int n = heap->size;
    int swap;
    
    //if left leaf is larger than root
    if(left < n && heap->elements[left] > heap->elements[max])
        max = left;
    
    //if right leaf is larger than root
    if(right < n && heap->elements[right] > heap->elements[max])
        max = right;
    
    //if max is not root
    if(max != i){
       swap = heap->elements[i];
       heap->elements[i] = heap->elements[max];
       heap->elements[max] = swap;
       
       heapify(heap, max);
    }
}
void maxheap(Heap *heap){
    //last root index
    int index = (heap->size/2)-1;
    //heapify the array
    for(int i = index; i>=0; i--) heapify(heap, i);
}

 

int Find(Heap *heap, int value){
    int flag = 0;
   
    for(int i = 0; i< heap->size; i++){
        if(heap->elements[i] == value){
            flag = 1;
            
        }
    }
    return flag;
}

void Insert(Heap *heap, int value){
    
    if(IsFull(heap)){
        fprintf(fout, "Insert Error: heap is full\n");
        return;
    }
    else if(Find(heap, value)) fprintf(fout, "Insert Error: %d is already in the heap\n", value);
    
    else if(heap->size == 0){
        heap->elements[0] = value;
        ++heap->size;
        fprintf(fout, "insert %d\n", value);
    }
    else{
        heap->elements[heap->size] = value;
        ++heap->size;
        fprintf(fout, "insert %d\n", value);
        
        maxheap(heap);
    }
}

void PrintHeap(Heap* heap){
    //check if is empty
    if(heap->size == 0){
        fprintf(fout, "Print Error: heap is empty\n");
        return;
    }
    
    fprintf(fout, "%d", heap->elements[0]);
    for(int i=1; i<heap->size; i++) fprintf(fout, " %d", heap->elements[i]);
    fprintf(fout,"\n");
}

int DeleteMax(Heap *heap){
    int max = heap->elements[0];
    
    if(heap->size ==0){
        fprintf(fout, "Delete Error: heap is empty\n");
        return -INF;
    }
    //re-ordering the array
    for(int i = 1; i < heap->size; i++){
        heap->elements[i-1] = heap->elements[i];
    }
    heap->size--;
    maxheap(heap);
    return max;
}

void deleteheap(Heap* heap){
   free(heap->elements);
   free(heap);
}


int main(int argc, char* argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    char cv;
    Heap* maxheap;
    int heapsize, key, max_element;
    
    while(!feof(fin)){
        fscanf(fin, "%c", &cv);
        switch(cv){
            case 'n':
                fscanf(fin, "%d", &heapsize);
                maxheap = CreateHeap(heapsize);
                fprintf(fin, "");
                break;
            case 'i':
                fscanf(fin, "%d", &key);
                Insert(maxheap, key);
                fprintf(fin, "insert %d\n", key);
                break;
            case 'd':
                max_element = DeleteMax(maxheap);
                if(max_element != -INF){
                    fprintf(fout, "Max Element: %d deleted\n", max_element);
                }
                break;
            case 'p':
                PrintHeap(maxheap);
                break;
            case 'f':
                fscanf(fin, "%d", &key);
                if(Find(maxheap, key)) fprintf(fout, "%d is in the heap\n", key);
                else fprintf(fout, "Finding Error: %d is not in the heap\n", key);
                break; 
        }
    }
    deleteheap(maxheap);
    return 0;
}
