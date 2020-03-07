#ifndef cbaAlloc2894783824758
#define cbaAlloc2894783824758

#include <stdio.h>
#include <string.h>

int allocateIntArray(int size,int** array);
int allocateString(int size,char** array);
int allocateArrayOfStrings(int size,int stringLength,char*** array);

int deallocateIntArray(int size,int** array);
int deallocateString(int size,char** array);
int deallocateArrayOfStrings(int size,int stringLength,char*** array);


#endif
