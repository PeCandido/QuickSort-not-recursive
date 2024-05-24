#include <stdio.h>
#include <stdlib.h>
#include "t_stack_quicksort.h"

int main(){
    int array[] = {3, 7, 6, 9, 2};
    int size = 5;

    printf("Array: \n");
    printArray(array, size);

    quickSort(array, 0, size - 1);
    printf("QuickSorted Array: \n");
    printArray(array, size);
}