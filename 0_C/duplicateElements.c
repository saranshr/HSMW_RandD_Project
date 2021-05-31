#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int arg, char **argv){
    /* Obtain input */
    int inputArray[] = {1,2,2,3,4};
    int sizeArray = sizeof(inputArray)/sizeof(inputArray[0]);
    for (int i = 0; i < sizeArray; i++){
        printf("%u ", inputArray[i]);
    }

    /* Find unique elements of array */
    /* Obtain size of new array */
    int newSizeArray = sizeArray;
    for (int i = 0; i < sizeArray-1; i++){
        if (inputArray[i] == inputArray[i+1]){
            newSizeArray--;
        }
    }
    int uniqueArray[newSizeArray];
    printf("\n newSizeArray =  %d and unique array is:\n", newSizeArray);

    /*
    - boolean array of same size as input array
    - iterate through input array and check if element is unique
    - change flag at duplicate
    - count duplicates
    - subtract from input array size to find size of unique array
    - compare indices of unique flag and copy that in input array
    */

/*     int m = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            if(inputArray[i]==uniqueArray[j])
                break;
        if(j==m){
            inputArray[m]=uniqueArray[i];
            m++;
    }
} */
/* 
    int doubleCheck = 0;
    for (int i = 0; i <= newSizeArray; i++){
        if (i == newSizeArray) {
                doubleCheck = 0;
            }
        if (inputArray[i] == inputArray[i+1]){
            uniqueArray[i] = inputArray[i];
            continue;
        } else if (doubleCheck == 1) {
            uniqueArray[i-1] = inputArray[i];
            continue;
        } else if (inputArray[i] == inputArray[i-1]){
            uniqueArray[i] = inputArray[i+1];
            //i++;
            doubleCheck = 1;
            continue;
        } else if (i==newSizeArray){
            uniqueArray[i-1] = inputArray[i];
        } else {
            uniqueArray[i] = inputArray[i];
            continue;
        }
    }
  */

    printf("\n newSizeArray =  %d and unique array is:\n", newSizeArray);

    for (int i = 0; i < newSizeArray; i++){
        printf("%u ", uniqueArray[i]);
    }
    printf("\nfinished\n");
    return 0;
}