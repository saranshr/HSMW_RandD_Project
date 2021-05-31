/* 
implement simple linear search
- input array need not be sorted
- loop through each element until the element being searched for is found
- output index/location of element being searched for
 */


#include <stdio.h>

int linSearch(int dataSet[], int n){
    for(int count=0; count <= sizeof(dataSet); count++){
        if (dataSet[count] == n){
            return count;
        } else if (count == sizeof(dataSet)){
            return -1;             
        }
    }
}
int main(int arg, char **argv){

    int data[] = {4,7,2,8,3,90,10,3};
    int searchFor = 10;
    int result = linSearch(data, searchFor);
    if (result == -1) {
        printf("Element not found \n");
    }else {
        printf("Element is at index %d \n",result);
    }
    return 0;
}