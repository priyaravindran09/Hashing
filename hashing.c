#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int hashTableSize = 0;
int currSize = 0;

int hashFunc(int element)
{
    return (element % hashTableSize);
}

void insertElement(int table[])
{
    int index = 0, i = 0, element = 0;
    printf("Enter the element to be inserted\n");
    scanf("%d",&element);

    index = hashFunc(element);

    if(currSize == hashTableSize) {
        printf("Table Full - Element could not be inserted\n");
        return;
    }

    while(table[index] != INT_MIN) {
        if(table[index] == INT_MAX) 
            break;
        index = hashFunc(index+1);
        i++;
        if(i == hashTableSize)
            break;
    }

    if(i == hashTableSize)
        printf("Table Full\n");
    else {
        table[index] = element;
        currSize++;
    }
}

void searchElement(int table[])
{
    int element = 0, index = 0, i = 0;
    printf("Enter the element to be searched\n");
    scanf("%d",&element);
    index = hashFunc(element);

    while(i < hashTableSize) {
        if(table[index] == element) {
            printf("Element found at key %d\n",index);
            break;
        }
        else if((table[index] == INT_MAX) || (table[index] != INT_MIN)) {
            index = hashFunc(index+1);
        }
        i++;
    }
    if(i == hashTableSize)
        printf("Element not found!\n");

}

void deleteElement(int table[])
{ 
    int element = 0, index = 0, i = 0;
    printf("Enter the element to be deleted\n");
    scanf("%d",&element);
    index = hashFunc(element);

    while(i < hashTableSize) {
        if(table[index] == element) {
            table[index] = INT_MIN;
            printf("Element deleted\n");
            break;
        }
        else if((table[index] == INT_MAX) || (table[index] != INT_MIN)) {
            index = hashFunc(index+1);
        }
        i++;
    }
    if(i == hashTableSize)
        printf("Element not found!\n");
}

void displayElements(int table[])
{
    int i;

    printf("Key\tElement\n");

    for(i = 0; i < hashTableSize; i++) {
        printf("%d\t%d\n",i,table[i]);
    }
}

int ifPrime(int num) 
{
    int index;

    if((num == 1) || (num == 0)) 
        return 0;

    for(index = 2; index <= num/2; index++) {
        if((num % index) == 0)
            return 0;
    }

    return 1;
}

int getPrime(int num)
{
    if((num % 2) == 0) {
        num++;
    }
    for(; !ifPrime(num); num += 2);
    return num;
}

int main(void)
{
    int j = 0, option =0;
    char c;
    
    printf("Enter the size of the hash table\n");
    scanf("%d",&hashTableSize);
    hashTableSize = getPrime(hashTableSize);
    printf("%d\n",hashTableSize);
    int hashTable[hashTableSize];
    for(j = 0;j < hashTableSize; j++)
        hashTable[j] = INT_MIN;
    
    do {
        printf("Select your option\n1:Insert\n2:Search\n3:delete\n4:display\n");
        scanf("%d",&option);

        switch(option) {
            case 1:
            insertElement(hashTable);
            break;
            case 2:
            searchElement(hashTable);
            break;
            case 3:
            deleteElement(hashTable);
            break;
            case 4:
            displayElements(hashTable);
            break;
            default:
            printf("Not a valid option\n");
            break;
        }

        displayElements(hashTable);
        printf("Do you want to continue? (y/n) \n");
        scanf(" %c",&c);
    }  while((c == 'y') || (c == 'Y'));

    return 0;
}
