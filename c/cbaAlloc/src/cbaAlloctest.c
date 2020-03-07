/* Author:	Stephen Alexandrov
   Date  :	10-17-2019
   
*/

#include <cbaAlloc.h>



int main(int argc, char** argv, char** pEnv)
{

	int 	i = 0;
	int 	size = 10;
	int	stringLength = 30;
	int* 	intArray=0;
	char* 	charArray=0;
	char** 	stringsArray =0;

	printf("Allocating the memory on the heap\n");
	printf("The arrays are passed by reference,using address of the array\n");

	printf("Allocating memory for integer array\n");

	i = allocateIntArray(size, &intArray);
	for(int i=0;i<size;i++)
	{
		printf("Integer %d: %d\n",i+1,intArray[i]);
	}


	 printf("Allocating memory for char array\n");
	i = allocateString(size, &charArray);

	printf("string value is %s\n",charArray);

	 printf("Allocating memory for string(char*) array\n");

	i = allocateArrayOfStrings(size,stringLength,&stringsArray); 


	printf("Done allocating\n");

	for(int j=0;j<size;j++)
	{
		printf("string %d : %s \n",j+1,stringsArray[j]);

	}	


        printf("Cleaning the Heap Memory\n");


	printf("Int array deallocation\n");
	i = deallocateIntArray(size, &intArray);
	printf("char array deallocation\n");
        i = deallocateString(size, &charArray);
	printf("String array deallocation\n");
        i = deallocateArrayOfStrings(size,stringLength,&stringsArray);

	printf("DONE\n");

	return 0;
}

