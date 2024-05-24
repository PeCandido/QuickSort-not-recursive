#include <stdio.h>
#include <stdlib.h>
#include "t_stack_quicksort.h"

// troca valores de lugar
void swapValues(int *v1, int *v2){
    int aux = *v1; 
    *v1 = *v2; 
    *v2 = aux; 
}

// cria partição do array de acordo com o pivô
int particle(int array[], int start, int end){
    int pivot = array[end];  // define o pivô como ultimo elemento do array
    int i = start - 1;      // i começa um antes de j, que é o inicio do array

    for(int j = start; j < end; j++){
        if(array[j] < pivot){   // caso elemento j for menor que o pivô, troca i com j
            i++;
            swapValues(&array[i], &array[j]);
        }
    }

    // troca o elemento i com o pivot, pivot vai pro meio do array (se tudo der certo)
    swapValues(&array[i+1], &array[end]);  
    return i+1;
}

void quickSort(int array[], int start, int end){
    int *auxStack = (int*) malloc(sizeof(int) * (end - start + 1)); // cria pilha auxiliar
    int top = -1; // começa topo da pilha
    
    auxStack[++top] = start; // adiciona o começo da pilha
    auxStack[++top] = end;  // adiciona o fim da pilha

    while(top >= 0){  
        // desempilha
        start = auxStack[top--]; 
        end = auxStack[top--];

        int pivot = particle(array, start, end); // encontra índice do pivô

        if(pivot-1 > start) {
            auxStack[++top] = start;
            auxStack[++top] = pivot - 1;
        }

        if(pivot+1 < end) {
            auxStack[++top] = pivot + 1;
            auxStack[++top] = end;
        }
    }

    free(auxStack);
}

void printArray(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}