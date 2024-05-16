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
   for (int i = 0; i < 9; i++){
      int row_check[10] = {0};
      for (int j = 0; j < 9; j++){
         if (n->sudo[i][j] != 0 && row_check[n->sudo[i][j]] == 1){
            return 0;
         }
         row_check[n->sudo[i][j]] = 1;
      }
   }
   
   for (int j = 0; j < 9; j++){
      int col_check[10] = {0};
      for (int i = 0; i < 9; i++){
         if (n->sudo[i][j] != 0 && col_check[n->sudo[i][j]] == 1){
            return 0;
         }
         col_check[n->sudo[i][j]] = 1;
      }
   }

   for (int i = 0; i < 9; i += 3){
      for (int j = 0; j < 9; j += 3)){
         int box_check[10] = {0};
         for (int k = i; k < i + 3; k++){
            for (int l = j; l < j + 3; l++){
               if (n->sudo[k][l] != 0 && box_check[n->sudo[k][l]] == 1){
                  return 0;
               }
               box_check[n->sudo[k][l]] = 1;
            }
         }
      }
   }
   return 1;
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