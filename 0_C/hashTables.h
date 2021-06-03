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
    // searching for an element given value
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

    return frequencySearch;
}