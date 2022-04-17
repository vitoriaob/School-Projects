#include<stdio.h>
#include<stdlib.h>
#include<time.h>

FILE *fin;
FILE *fout;
int *rank;
int *down, *right;


typedef struct _DisjointSet{
    int size_maze;
    int *ptr_arr;
}DisjointSets;

void init(DisjointSets *sets, DisjointSets *maze_print, int num){
    sets->size_maze = (num*num)-1;
    maze_print->size_maze = (num*num)-1;
    sets->ptr_arr = (int *) malloc(sizeof (int)*sets->size_maze);
    maze_print->ptr_arr = (int *) malloc(sizeof (int)*sets->size_maze);
    rank = (int *) malloc(sizeof (int)*sets->size_maze);
    for(int i =0; i<num*num; i++){  
        sets->ptr_arr[i]= i;
        maze_print-> ptr_arr[i] = 1; //all walls existing
        rank[i] = -1; //all disconected
    }
}
int find(DisjointSets *sets, int i){
 // recursive find with path compression
  if(i != sets->ptr_arr[i])
    sets->ptr_arr[i] = find(sets,sets->ptr_arr[i]);
  return sets->ptr_arr[i];
}

void Union(DisjointSets *sets, int i, int j){
    int x = find(sets, i);
    int y = find(sets,j);
    if( x == y ) return;

  // optimization with rank
    if(rank[x] > rank[y])
        sets->ptr_arr[y] = x;
    else {
        sets->ptr_arr[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
    }
}



int isSameSet(DisjointSets *sets, int i, int j){
    return find(sets, i) == find(sets, j);
}

void createMaze(DisjointSets *sets, DisjointSets *maze_print, int num){
    // begin with a rectangular maze of all closed cells
   down = (int *) malloc(sizeof (int)*sets->size_maze);
   right = (int *) malloc(sizeof (int)*sets->size_maze);
   for(int i =0; i<num*num; i++){  
        down[i] = 1;
        right[i] =1;
    }
    
  int start = sets->ptr_arr[0];
  int goal  = sets->ptr_arr[num*num-1];
  int x, edge, cel;
  
 
  // goal is not reachable from start
  while (!isSameSet(sets,start,goal)) {
    edge = rand()%2;
    cel = rand()%sets->size_maze;
    
    if(edge == 0) x = cel+1; //right edge
    else x = cel+num;       //bottom edge
    
    if(!isSameSet(sets,cel, x))
        Union(sets,cel,x);
        maze_print-> ptr_arr[cel] = 0;
        if(edge == 0)  right[cel] =0; //right edge
        else down[cel] = 0;       //bottom edge     
    }  
    
}

void printMaze(DisjointSets *maze, int num){
    
    //printing the first upper wall
    fprintf(fout, "+");
    for(int k =0; k<=num; k++)
            fprintf(fout, "---+");
    //maze entry
    fprintf(fout,"\n    ");
    
    for(int k = num; k < maze->size_maze; k+=num){
    //columns 
    
    for(int i = 1; i <num; i++){
        //case the right wall is erased
        if(right[i+k] == 0)
            fprintf(fout, "    ");
        else fprintf(fout, "|");
    
        
//         if(maze->ptr_arr[i+k] == 0 && maze->ptr_arr[i+k+1]==0)
//             fprintf(fout, "    ");
//         else fprintf(fout, "|");
    }
        fprintf(fout,"\n");
        
    //printing the lines
    fprintf(fout, "+");
    for(int j = 1; j<num; j++){
        //case the bottom is erased
        if(down[j+k] == 0)
                fprintf(fout, "    ");
        else fprintf(fout, "---+");
        }
//         fprintf(fout,"\n|");
//         for(int k =0; k<=num; k++)
//             fprintf(fout,"   |");
//         fprintf(fout,"\n|");
//         for(int k =0; k<=num; k++)
//             fprintf(fout,"   |");
//         fprintf(fout,"\n");
    }
        fprintf(fout,"\n");
    //printing last line
    fprintf(fout, "+");
    for(int j = 0; j<=num; j++)
            fprintf(fout, "---+");
    fprintf(fout,"\n");
}
// void freeMaze(DisjointSets){
//     
// }

int main(int argc, char* argv[]){
    srand((unsigned int)time(NULL));
    
    int num, i;
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    
    DisjointSets *sets, *maze_print;
    fscanf(fin, "%d", &num);
    
    sets = (DisjointSets*)malloc(sizeof(DisjointSets));
    maze_print = (DisjointSets*)malloc(sizeof(DisjointSets));
    
    init(sets, maze_print, num);
    createMaze(sets, maze_print, num);
//      for(int i =0; i<num*num; i++){
//          printf("%d ", maze_print->ptr_arr[i]);
//      }
    printMaze(maze_print, num);
    
    //freeMaze(sets, maze_print);
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}
