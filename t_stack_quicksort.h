#ifndef T_STACK_QUICKSORT_H
#define T_STACK_QUICKSORT_H

typedef struct {
    int start;
    int end;
} t_stack;

void swap(int *v1, int *v2);
int particle(int array[], int start, int end);
void quickSort(int array[], int start, int end);
void printArray(int array[], int size);

#endif 