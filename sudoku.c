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

  int i,j,numColumna,num;
  //int k=0, numSubMa;
  for(i=0; i <9 ; i++){
    
    int filas[10] = {0,0,0,0,0,0,0,0,0};
    int columnas[10]={0,0,0,0,0,0,0,0,0};
    
    for(j=0 ; j <9 ; j++){
      num = n->sudo[i][j];
      numColumna = n->sudo[j][i];
      if(num !=0){
        if(filas[num] == 0){
          filas[num] = 1;
        } 
        else
        {
          return 0;
        }
      }
      
      if(numColumna !=0){
        if(columnas[numColumna] == 0){
          columnas[numColumna] = 1;
        } 
        else
        {
          return 0;
        }
      }  

      /*
      int fila = 3*(k/3) + (i/3);
      int colum = 3*(k%3) + (i%3);
      numSubMa = n->sudo[fila][colum];

      if(numSubMa !=0){
        if(filas[numSubMa] == 0){
          filas[numSubMa] = 1;
        } 
        else if(columnas[numSubMa] == 0){
          columnas[numSubMa] = 1;
        } 
        else
        {
          return 0;
        }
        k++;
      }
      */
    }
  }
  return 1;
}

  /*
   int* VectorCero = calloc(10, sizeof(int));
  //Recorrer fila
  for(int i=0 ; i <9 ; i++)
    {
      int num;
      num = n->sudo[0][i];
      if(VectorCero[num] == 0)
      {
        VectorCero[num]=1;
      }
      else if(VectorCero[num]==1) return 1;
    }
    return 1;
    */



List* get_adj_nodes(Node* n){
    List* list=createList();
    int i,j, num;

    for(i=0 ; i <9 ; i++)
      {
        for(j=0 ; j<9 ; j++)
          {
            if(n->sudo[i][j] == 0){
              for(num = 1 ; num<= 9 ; num++)
                {
                  Node *adyacente = copy(n);
                  adyacente->sudo[i][j] = num;
                  push(list, adyacente);
                }
              return list;
            }
          }
      }
    return list;
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