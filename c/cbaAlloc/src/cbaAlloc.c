/* Author:	Stephen Alexandrov
   Date  :	10-17-2019
   
*/

#include <cbaAlloc.h>


int allocateIntArray(int size,int** array)
{
	*array =(int*)malloc(size * sizeof(int));
	int* locArray=*array;
	for(int i=0;i<size;i++)
	{
		locArray[i] = i+1;

	}
 return 0;
}
int allocateString(int size,char** array)
{
	int retcode=-1;
        *array = (char*)malloc(size * sizeof(char));
	strcpy(*array,"string");
        if (array !=0) retcode=0;
 	
return retcode;

}

int allocateArrayOfStrings(int size,int stringLength,char*** array)
{
	int retcode=-1;
	*array = (char**)malloc(size * sizeof(char*));
	/* Easier to deal with indexing */
	char** locArray = *array;


	for(int i=0;i<size;i++)
	{
		locArray[i]=(char*)malloc(stringLength*sizeof(char));
		char stringValue[15];
		sprintf(stringValue,"String %d",i);
		strcpy(locArray[i],(char*)stringValue);
	}
	
	if(*array != 0) retcode=0;
 return retcode;
}

int deallocateIntArray(int size,int** array)
{
  int* locArray = *array;
  for (int i=0;i<size;i++)
  {
	free (locArray[i]);
  }

	free (locArray);
 return 0;
}

int deallocateString(int size,char** array)
{

	 char* locArray = *array;
  for (int i=0;i<size;i++)
  {
        free (locArray[i]);
  }

  free (locArray);


 return 0;
}

int deallocateArrayOfStrings(int size,int stringLength,char*** array)
{
	char ** localArray=*array;
	for (int i =0;i<size;i++)
	{
		for(int j=0;j<stringLength;j++)
		{
			free(localArray[i,j]);

		}
		free(localArray[i]);

	}

	free(localArray);

 return 0;
}


