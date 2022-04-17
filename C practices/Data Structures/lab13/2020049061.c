#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fin;
FILE *fout;

typedef int ElementType;
typedef ElementType List;
typedef struct HashTbl* HashTable;

typedef struct HashTbl{
    int TableSize;
    List *TheLists;
}HashTbl;

HashTable createTable(int TableSize){
    HashTable h = (HashTbl*)malloc(sizeof(HashTbl));
    h->TableSize = TableSize;
    h->TheLists = (int*)malloc(TableSize* sizeof(int));
    for(int i = 0; i < TableSize; i++){
        h->TheLists[i] = 0;
    }
    return h;
}
int Find(HashTable H, ElementType Key, int solution){
    int hash = Key % H->TableSize;
    if(H->TheLists[hash] != Key){
          if(solution == 1){
            int i = 1;
            while(i){
                if(H->TheLists[hash+i] != Key && hash+i < H->TableSize) i++;
                else if (H->TheLists[hash+i] != Key && hash+i >= H->TableSize) return 0;
                else return hash+i;
                }
            }
            else if(solution == 2){
                int i = 1;
                while(i){
                    if(H->TheLists[hash+i] != Key && hash+(i*i) < H->TableSize) i++;
                    else if (H->TheLists[hash+i] != Key && hash+(i*i) >= H->TableSize) return 0;
                    else return hash+(i*i);
                }
            }
        }
    else if(H->TheLists[hash] == Key) return(hash);
    
}
void Insert(HashTable H, ElementType Key, int solution){
    int hash; 
    int exists = Find(H, Key, solution);
    hash = Key % H->TableSize;
    if(exists) 
        fprintf(fout, "Insertion Error: %d already exists at address %d\n", Key, exists);
    else if(H->TheLists[hash]){
        if(solution == 1){
            int i = 1;
            while(i){
                if(H->TheLists[hash+i]) i++;
                else{ 
                    if(hash+i < H->TableSize){
                        H->TheLists[hash+i] = Key; 
                        fprintf(fout, "Insert %d into address %d\n", Key, hash+i);}
                    else fprintf(fout, "Insertion Error: table is full\n");
                    i =0;
                    
                }
            }
        }
        else if(solution == 2){
            int i = 1;
            while(i){
                if(H->TheLists[hash+(i*i)]) i++;
                else{ 
                    if(hash+(i*i) <= H->TableSize){
                        H->TheLists[hash+(i*i)] = Key; 
                        fprintf(fout, "Insert %d into address %d\n", Key, hash+(i*i));}
                    else fprintf(fout, "Insertion Error: table is full\n");
                    i =0;
                }
            }
        }
    }
    else{
        H->TheLists[hash] = Key;
        fprintf(fout,"Insert %d into address %d\n", Key, hash);
    }
}
void Delete(HashTable H, ElementType Key, int solution){
    int pos = Find(H, Key, solution);
    if(pos){
        H->TheLists[pos] = 0;
        fprintf(fout,"Delete %d\n", Key);
        
    }
    else fprintf(fout, "Deletion Error: %d is not in the table\n", Key);
}

void printTable(HashTable H){
    for(int i = 0; i < H->TableSize; i++)
        fprintf(fout, "%d ", H->TheLists[i]);
    fprintf(fout, "\n");
}
void deleteTable(HashTable H){
    free(H->TheLists);
    free(H);
}

int main(int argc, char *argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    
    char solution_str[20];
    int solution, TableSize;
    
    fscanf(fin, "%s", solution_str);
    if(!strcmp(solution_str, "Linear"))
        solution = 1;
    else if(!strcmp(solution_str, "Quadratic"))
        solution = 2;
    else{
        fprintf(fout, "Error: Invalid hashing solution!");
        return 0;
    }
    
    fscanf(fin, "%d", &TableSize);
    HashTable H = createTable(TableSize);
    
    char cv;
    int key;
    while(!feof(fin)){
        fscanf(fin, "%c", &cv);
        switch(cv){
            case 'i':
                fscanf(fin, "%d", &key);
                Insert(H, key, solution);
                break;
            case 'f':
                fscanf(fin, "%d", &key);
                int result = Find(H, key, solution);
                if(result)
                    fprintf(fout, "%d is in the table\n", key);
                else
                    fprintf(fout, "%d is not in the table\n", key);
                break;
            case 'd':
                fscanf(fin, "%d", &key);
                Delete(H, key, solution);
                break;
            case 'p':
                printTable(H);
                break;
        }
    }
    deleteTable(H);
    
    return 0;
}
