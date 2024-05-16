#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
   int is_valid(Node* n){
      int i,j,k;
      // Check rows
      for(i=0;i<9;i++){
         int* row = (int*) malloc(sizeof(int) * 10);
         for(j=0;j<9;j++){
            k = n->sudo[i][j];
            if(k == 0) continue;
            if(row[k] == 1){
               free(row);
               return 0; // Not valid
            }
            row[k] = 1;
         }
         free(row);
      }
      // Check columns
      for(j=0;j<9;j++){
         int* col = (int*) malloc(sizeof(int) * 10);
         for(i=0;i<9;i++){
            k = n->sudo[i][j];
            if(k == 0) continue;
            if(col[k] == 1){
               free(col);
               return 0; // Not valid
            }
            col[k] = 1;
         }
         free(col);
      }
      // Check 3x3 sub-grids
      for(int box = 0; box < 9; box++){
         int* grid = (int*) malloc(sizeof(int) * 10);
         int start_row = (box / 3) * 3;
         int start_col = (box % 3) * 3;
         for(i = start_row; i < start_row + 3; i++){
            for(j = start_col; j < start_col + 3; j++){
               k = n->sudo[i][j];
               if(k == 0) continue;
               if(grid[k] == 1){
                  free(grid);
                  return 0; // Not valid
               }
               grid[k] = 1;
            }
         }
         free(grid);
      }
      return 1; // Sudoku board is valid
   }
}


List* get_adj_nodes(Node* n){
   
   List* adjList = createList();
   for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
         if(n->sudo[i][j] == 0){
            for(int k = 1; k <= 9; k++){
               Node* adjNode = copy(n);
               adjNode->sudo[i][j] = k;
               if(is_valid(adjNode)){
                  pushBack(adjList, adjNode);
               }
            }
         }
      }
   }
   return adjList;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/