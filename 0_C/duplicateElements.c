#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *link;
} node; // define data type and typedef it to 'node'. This is the template of an element in the linked list

int sizeOfUniqueArray(int flagArray[], int inputArray[], int sizeArray)
{
    /* Find unique elements of array */
    int numDuplicates = 0;
    // memset(flagArray,1,sizeArray*sizeof(int));                         // this gives 16843009 = 0x01010101 --> i.e. memset fills each byte with 0x01 (sizeof(int) = 4 Bytes)
    for (int i = 0; i < sizeArray; i++)
    {
        flagArray[i] = 1; // initialize flagArray to 1
    }
    for (int i = 0; i < sizeArray; i++)
    {
        if (inputArray[i] == inputArray[i + 1])
        {
            flagArray[i + 1] = 0; // if duplicate found, set flagArray to 0 of duplicate element
            numDuplicates += 1;   // cumulative count of duplicates
        }
    }
    /* For testing */
    printf("flagArray: ");
    for (int i = 0; i < sizeArray; i++)
    {
        printf("%u ", flagArray[i]);
    }
    printf("\n");
    /**/

    int newSizeArray = sizeArray - numDuplicates; // number of unique elements in inputArray

    return newSizeArray;
}

void getUniqueFrequencies(int flagArray[], int inputArray[], int uniqueArray[], int frequencyArray[], int sizeArray)
{
    int uniqueArrayCount = 0; // iterator to iterate within uniqueArray
    int frequencyCount = 1;
    for (int i = 0; i < sizeArray; i++)
    {
        if (flagArray[i] == 1)
        { // identify unique elements and copy them to uniqueArray
            uniqueArray[uniqueArrayCount] = inputArray[i];
            uniqueArrayCount += 1;
            frequencyCount = 1;
        }
        else
        {
            frequencyCount += 1;
        }
        frequencyArray[uniqueArrayCount - 1] = frequencyCount;
    }
}

void hashTablesLinProb(int ht_uniqueArray[], int ht_frequencies[], int uniqueArray[], int frequencyArray[], int newSizeArray)
{
    for (int i = 0; i < newSizeArray; i++)
    {
        ht_uniqueArray[i] = -1; // initialize hash table with arbitrary value, e.g. -1
        ht_frequencies[i] = -1;
    }

    int key;
    for (int i = 0; i < newSizeArray; i++)
    {
        key = uniqueArray[i] % newSizeArray; // simple hash function --> mod size(Array) to make the key fit between 0 and (size of array - 1)
        printf("key = %d\n", key);

        // insert value at computed key
        if (ht_uniqueArray[key] == -1)
        {
            ht_uniqueArray[key] = uniqueArray[i];
            ht_frequencies[key] = frequencyArray[i];
        }
        else
        {
            // printf("Collision! uniqueArray[%d] already has the value %d stored.. \n",key,ht_uniqueArray[key]);
            while (key <= newSizeArray)
            { // deal with key collisions using linear probing method
                key = (key + 1) % newSizeArray;
                if (ht_uniqueArray[key] == -1)
                {
                    ht_uniqueArray[key] = uniqueArray[i];
                    ht_frequencies[key] = frequencyArray[i];
                    break;
                }
            }
        }
    }
}

void printHashTablesLinProb(int ht_uniqueArray[], int ht_frequencies[], int newSizeArray)
{
    printf("ht_uniqueArray: ");
    for (int i = 0; i < newSizeArray; i++)
    {
        printf("%u ", ht_uniqueArray[i]);
    }
    printf("\nht_frequencies: ");
    for (int i = 0; i < newSizeArray; i++)
    {
        printf("%u ", ht_frequencies[i]);
    }
    printf("\n");
}

void init_chainNodes(int newSizeArray, node *chainUniqueArray[], node *chainFrequencies[])
{
    // initialize the nodes to NULL
    for (int i = 0; i < newSizeArray; i++)
    {
        chainUniqueArray[i] = NULL;
        chainFrequencies[i] = NULL;
    }
}

void insertElementsInNodes(int newSizeArray, int uniqueArray[], int frequencyArray[], node *chainUniqueArray[], node *chainFrequencies[], node *nodeUniqueArray, node *nodeFrequencies, int i)
{
    int hashKey;
    nodeUniqueArray->data = uniqueArray[i];
    nodeUniqueArray->link = NULL;
    nodeFrequencies->data = frequencyArray[i];
    nodeFrequencies->link = NULL;

    // calculate hash key
    hashKey = uniqueArray[i] % newSizeArray;

    // check if head node is empty
    if (chainUniqueArray[hashKey] == NULL)
    {
        chainUniqueArray[hashKey] = nodeUniqueArray;
        chainFrequencies[hashKey] = nodeFrequencies;
    }
    else
    { // incase of collision, link head node to further nodes (at the same key) and store the values on the chained nodes
        node *tempUA = chainUniqueArray[hashKey];
        node *tempFr = chainFrequencies[hashKey];
        while (tempUA->link)
        {
            tempUA = tempUA->link;
            tempFr = tempFr->link;
        }
        tempUA->link = nodeUniqueArray;
        tempFr->link = nodeFrequencies;
    }
}

void printHashTableChainSep(int newSizeArray, node *chainUniqueArray[], node *chainFrequencies[])
{
    // print hash table with chains
    for (int i = 0; i < newSizeArray; i++)
    {
        node *tempPrintUA = chainUniqueArray[i];
        printf("\nchainUniqueArray[%d] -->", i);
        while (tempPrintUA)
        {
            printf("%d --> \n", tempPrintUA->data);
            tempPrintUA = tempPrintUA->link;
        }
    }
    printf("\n");
    for (int i = 0; i < newSizeArray; i++)
    {
        node *tempPrintFr = chainFrequencies[i];
        printf("\nchainFrequencies[%d] -->", i);
        while (tempPrintFr)
        {
            printf("%d --> \n", tempPrintFr->data);
            tempPrintFr = tempPrintFr->link;
        }
    }
}

int searchHashTable(int searchValue, int newSizeArray, node *chainUniqueArray[], node *chainFrequencies[], int frequencySearch)
{
    // searching for an element given value, e.g. 7:
    int hashKeySearch = searchValue % newSizeArray;
    node *tempSearchUA = chainUniqueArray[hashKeySearch];
    node *tempSearchFr = chainFrequencies[hashKeySearch];
    while (tempSearchUA)
    {
        if (tempSearchUA->data == searchValue)
        {
            frequencySearch = tempSearchFr->data;
        }
        tempSearchUA = tempSearchUA->link;
        tempSearchFr = tempSearchFr->link;
    }
    printf("Element %d found, occurs %d times", searchValue, frequencySearch);

    return frequencySearch;
}

int main(int arg, char **argv)
{
    /* Obtain input */
    int inputArray[] = {1,1,2,3,5};
    int sizeArray = sizeof(inputArray) / sizeof(inputArray[0]);
    int flagArray[sizeArray]; // boolean array required to assist with the search of unique elements

    /* For testing */
    printf("inputArray: ");
    for (int i = 0; i < sizeArray; i++)
    {
        printf("%u ", inputArray[i]);
    }
    printf("\n");
    /**/
    int newSizeArray;
    newSizeArray = sizeOfUniqueArray(flagArray, inputArray, sizeArray);

    int uniqueArray[newSizeArray];    // declare new array of unique values
    int frequencyArray[newSizeArray]; // array of frequencies of each unique element

    getUniqueFrequencies(flagArray, inputArray, uniqueArray, frequencyArray, sizeArray);

    /* For testing */
    printf("uniqueArray: ");
    for (int i = 0; i < newSizeArray; i++)
    {
        printf("%u ", uniqueArray[i]);
    }
    printf("\nfrequencyArray: ");
    for (int i = 0; i < newSizeArray; i++)
    {
        printf("%u ", frequencyArray[i]);
    }
    printf("\n");
    /**/
    /*
GOAL: 
    - Create/Use a dictionary structure to achieve following:
        - The 'key' would be the unique element
        - The 'value' would be the number of times the element exists in the input dataset
    --> Dictionaries don't exist in C
    --> Can be achieved using so called 'hash tables'    
*/
    int linProbChainSep = 1; // = 0 --> hash table with linear probing; = 1 --> hash table with chain separating
    if (linProbChainSep == 0)
    {
        int ht_uniqueArray[newSizeArray];
        int ht_frequencies[newSizeArray];

        hashTablesLinProb(ht_uniqueArray, ht_frequencies, uniqueArray, frequencyArray, newSizeArray);
        printHashTablesLinProb(ht_uniqueArray, ht_frequencies, newSizeArray);
    }
    else
    {
        // create an object node
        node *chainUniqueArray[newSizeArray]; // pointer chain of type node of size newSizeArray -> i.e. it it pointing to memory blocked for an array
        node *chainFrequencies[newSizeArray];

        /* Incase of collision of keys --> store data on a linked list at the same key. The first element 
        in the hash table therefore becomes the head of the linked list, pointing to further elements --> known as SEPARATE CHAINING */

        init_chainNodes(newSizeArray, chainUniqueArray, chainFrequencies);

        // insert values in head nodes, if collisions occur, enter values at nodes linked to the head node at the same key
        for (int i = 0; i < newSizeArray; i++)
        {
            node *nodeUniqueArray = malloc(sizeof(node)); // create new head nodes of hash table, one for unique array and one for frequency
            node *nodeFrequencies = malloc(sizeof(node));
            insertElementsInNodes(newSizeArray, uniqueArray, frequencyArray, chainUniqueArray, chainFrequencies, nodeUniqueArray, nodeFrequencies, i);
        }

        // print hash table with chain separating (i.e. using linked list)
        printHashTableChainSep(newSizeArray, chainUniqueArray, chainFrequencies);

        // search for an element in the hash table
        int frequencySearch;
        frequencySearch = searchHashTable(1, newSizeArray, chainUniqueArray, chainFrequencies, frequencySearch);

        printf("\nfinished\n");
        return 0;
    }
}