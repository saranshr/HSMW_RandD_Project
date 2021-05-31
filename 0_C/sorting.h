/* #include <stdio.h>
#include <stdlib.h> */

void swap(int arr[], int a, int b){
    /* Small functionality to swap two elements in an array with indices a and b */
    int buffer = arr[a];
    arr[a] = arr[b];
    arr[b] = buffer;
}

int partition(int inputArray[], int low, int high){
    int pivot = inputArray[high];                   // set the pivot as the last element of the array
    int i = low-1;                                  // index of smaller elements
    for (int j = low; j <= high-1; j++){
        if (inputArray[j] < pivot){
            i++;
            swap(inputArray, i, j);                 // if current element is less than pivot, swap the positions of the two elements. Otherwise do nothing
        }
    }
    swap(inputArray, i+1, high);                    // Final 'move' to place pivot in the right position: i.e. all elements smaller than pivot will be on its left, and all elements larger on its right
    return (i+1);
}

void quickSort(int inputArray[], int low, int high){
    if (low < high){
        int p = partition(inputArray, low, high);
        quickSort(inputArray, low, p-1);            // sort before pivot
        quickSort(inputArray, p+1, high);           // sort after pivot
    }
}

// int main(int arg, char **argv){
//     /* Obtain input */
//     int inputArray[] = {10, 80, 30, 90, 40, 50, 70};
//     int sizeArray = sizeof(inputArray)/sizeof(inputArray[0]);
//     for (int i = 0; i < sizeArray; i++){
//         printf("%u ", inputArray[i]);
//     }
    
//     quickSort(inputArray,0,(sizeArray-1));
    
//     printf("\nsorted list is\n");
//     for (int i = 0; i < sizeArray; i++){
//         printf("%u ", inputArray[i]);
//     }
//     printf("\nfinished\n");
//     return 0;
// }