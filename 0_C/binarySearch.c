/*
Implementation of the Binary Search. Following criteria will be considered:
    - Iterative and Recursive approaches
    - Input data array will be provided in an ascending sorted manner
    - Elements occurring multiple times in the array will be dealt with by:
        - Taking the set of the array to obtain unique elements
        - Storing the indices of the 'removed' elements e.g. in a dictionary, where the key would be the unique element and the list of indices of
        the recurring element the value
*/

#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

#define LOW 0                                   // preprocessor command --> doesn't change during runtime

void getUserInput(int sizeArray, int inputArray[], int userIn[]){
    /* get input data set and the element to be searched for from user */

    printf("Enter data elements seperated by a comma, e.g. 1,2,3. Press Enter at the end. Do not enter more than %d numbers: \n", sizeArray);
    for (int i = 0; i < sizeArray; i++){
        scanf("%d, ", &inputArray[i]);
    }
    printf("\nEnter the number to be searched for: \n");
    scanf("%d", &userIn[1]);

    printf("\nFor iterative implementation, enter 0. For recursive implementation, enter 1 :\n");
    scanf("%d", &userIn[0]);

}

int binarySearchIter(int dataSet[], int numElem, int n){
    // iterative implementation
    int low = 0;
    int high = numElem;                         // last element of data set
    while (low <= high){
        int mid = (low + high) / 2;
        if (dataSet[mid] > n){
            high = mid - 1;
        } else if (dataSet[mid] < n) {
            low = mid + 1;
        } else {
            return mid;                         // best case scenario, search value is the center element              
        }
    }
    return -1;                                   // element not found
}

int binarySearchRec(int dataSet[], int n, int low, int high){
    // recursive implementation

    if (high < low){
        return -1;                           // not found
    }
    int mid = (low + high) / 2;
    if (dataSet[mid] > n){
        return binarySearchRec(dataSet, n, low, mid - 1);
    } else if (dataSet[mid] < n) {
        return binarySearchRec(dataSet, n, mid + 1, high);
    } else {
        return mid;                         // best case scenario, search value is the center element
    }
}

int main(int arg, char **argv){
    /* Obtain input */
    int stackHeap;                                                      // 0 = implementation on stack; 1 = implementation on heap
    printf("Implementation on stack or heap? Enter 0 for stack, 1 for heap: \n");
    scanf("%d", &stackHeap);

    int sizeArray;
    int tempSize = 1;                                               // incase user selects 'heap', the redundant tempArray will just be of length 1.
    int userIn[2];                                                  // userIn[1]: element to be searched for; userIn[0]: iterative or recursive implementations
    printf("Enter size of input array: \n");
    scanf("%d", &sizeArray);
    
    if (stackHeap == 0) {
        tempSize = sizeArray;
    }
    int tempArray[tempSize];                                        // if user selects 'stack', the tempArray is declared to be of user defined length. Otherwise it is of length 1
    int *inputArray;                                                // for dynamic memory allocation (heap implementation), we need a pointer to point at the array created

    if (stackHeap == 0) {
        inputArray =  tempArray;                                    // equivalent to inputArray = &tempArray[0]; i.e. the pointer inputArray is now pointing to the tempArray. Both arrays are therefore the same!
        // printf("input array = %p\n", &inputArray[0]);
        // printf("temp array = %p\n", &tempArray[0]);
    } else {
        inputArray = (int*) malloc(sizeArray * sizeof(int));
        if(inputArray == NULL) {                                    // if sizeArray is too large and the memory cannot be allocated on the heap, we need to do error handling
            printf("\n\nError! Memory requested too large and could not be allocated, enter a smaller size of array:\n");
            scanf("%d", &sizeArray);
            inputArray = (int*) malloc(sizeArray * sizeof(int));
        }
    }

    getUserInput(sizeArray, inputArray, userIn);

    // sort input 
    quickSort(inputArray,0,(sizeArray-1));                          // sort user input in ascending order

    int result;
    if (userIn[0] == 0) {                                           // switch between iterative (0) and recursive (1) implementations
        result = binarySearchIter(inputArray, sizeArray, userIn[1]);
    } else {
        result = binarySearchRec(inputArray, userIn[1], LOW, sizeArray);
    }
    if (result == -1) {
        printf("Element not found \n");
    } else {
        printf("\nThe input data set, sorted in ascending order, is as follows: \n");
        for (int i = 0; i < sizeArray; i++){
            printf("%u ", inputArray[i]);
            }
        printf("\nSearch-Element (%d) is at index %d in the sorted data set \n",userIn[1],result);
    }

    if (stackHeap == 1) {
        free(inputArray);                                               // free memory allocated by malloc on the heap
    }

    return 0;

}
