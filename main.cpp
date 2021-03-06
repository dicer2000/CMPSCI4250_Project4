/**********************
 * Brett Huffman
 * CMPSCI 4250
 * Jul 23, 2021
 * Project 4
**********************/

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 1000


void f1()
{
    char lArray[DEFAULT_SIZE] = {0};
    static int n = 0;
    static long int addr = (long) &lArray;

    n++;

    if(n > 10)
        return;
    else
    {
        // Print the Call # and address of array
        printf("\nCall: #%d @ %p", n, lArray);
        
        // Next get the current address of array
        // As a long.  This prevents a warning
        long int addrCurrent = (long) &lArray;

        // Debugging
//        printf("\nCurrent: #%ld", addrCurrent);
//        printf("\nPrior: : #%ld", addr);

        // Print the difference
        printf("\nAR Size: #%d - %ld\n", n, (addr-addrCurrent));

        // Store for next time
        addr = (long) &lArray;

        // Call recursively
        f1();

    }
}

void f2()
{
    // Get address of the very start of the stack
    void *pStart;
    static long int addrStart = (long)(&pStart);

    char lArray[DEFAULT_SIZE] = {0};
    static int n = 0;
    static long int addr = (long) &lArray;

    n++;

    // There is no terminating clause in this
    // one - it's going to seg fault

    // Print the Call # and address of array
    printf("\nCall: #%d @ %p", n, lArray);
    
    // Next get the current address of array
    // As a long.  This prevents a warning
    long int addrCurrent = (long) &lArray;

    // Debugging
//        if(n > 10)
//            return;
//    printf("\nCurrent: #%ld", addrCurrent);
//    printf("\nPrior: : #%ld", addr);

    // Print the difference
    printf("\nAR Size: #%d - %ld\n", n, (addr-addrCurrent));

    // Print the ongoing total size of the stack
    printf("Stack Size: #%d - %ld\n", n, (addrStart-addrCurrent));

    // Store for next time
    addr = (long) &lArray;

    // Call recursively
    f2();

}

void f3()
{
    char *lArray = (char*)malloc( sizeof(char) * DEFAULT_SIZE );
    static int n = 0;
    char c = '0';
    static long int addr = (long) &c;

    n++;

    if(n > 10)
        return;
    else
    {
        // Print the Call # and address of array
        printf("\nCall: #%d @ %p", n, lArray);
        
        // Next get the current address of array
        // As a long.  This prevents a warning
        long int addrCurrent = (long) &c;

        // Debugging
//        printf("\nCurrent: #%ld", addrCurrent);
//        printf("\nPrior: : #%ld", addr);

        // Print the difference
        printf("\nAR Size: #%d - %ld\n", n, (addr-addrCurrent));

        // Store for next time
        addr = (long) &c;

        // Free the memory
        free(lArray);

        // Call recursively
        f3();


    }
}

int main() {

 //f1();

 //f2();

 f3();

 return 0;

}