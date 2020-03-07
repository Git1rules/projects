/* Author:	Stephen Alexandrov
   Date  :	01-11-2020
   
*/

#include <cbaLib.h>


 int valueFunction(int i)
 {
	i = i +5;
	printf("Value inside the function with parameters passed by value: %d\n",i);
	return 0;
 }

 int refFunction(int* i)
 {
	*i=*i + 5;

	 printf("Value inside the function with parameters passed by reference: %d\n",*i);

	return 0;
 }
