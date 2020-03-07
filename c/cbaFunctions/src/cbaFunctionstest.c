/* Author:	Stephen Alexandrov
   Date  :	10-20-2019
   
*/

#include <cbaFunctions.h>



int main(int argc,char **argv,char **pEnv)
{

	int i=10;

	printf("Initial value of parameter : %d\n",i);
	valueFunction(i);

	printf("Parameter passed by value outside the function : %d\n",i);

	refFunction(&i);
	printf("Parameter passed by reference(address of variable) outside the function : %d\n",i);
	

	printf("Same operations using function pointers\n");

	/* Declaring the pointer to value function */
	int(*f_ptr)(int)=valueFunction;

	i=10;	
	/* Calling the function using function pointer */
	f_ptr(i);
	printf("Parameter passed by value outside the function : %d\n",i);
	

	 /* Declaring the pointer to reference function */
	int(*f_ptr1)(int*)=refFunction;

	/* Calling the function using function pointer */

	f_ptr1(&i);
	printf("Parameter passed by reference(address of variable) outside the function : %d\n",i);



	return 0;
}
