/* Author:	Stephen Alexandrov
   Date  :	01-11-2020
   
 This program demonstrates 
	dlopen() 	dynamic loading of a shared library,
	dlsym() 	resolving function symbols, 
			executing functioncode using function pointers to resolved symbols,
	dlclose() 	unloading the library.
	dlerror() 	notifies of the dynamic linker errors

	Library search path  should be set in  the environment where the application is to to run
	For AIX it would be LIBPATH, SUN and Linux will need LD_LIBRARY_PATH and HPUX will need SHLIB_PATH

	Library should be compiled first. Please note, No library header is needed in the application, 
	as no library symbols are resolved at compile time
*/

#include <stdio.h>
#include <dlfcn.h>

int main(int argc,char **argv,char **pEnv)
{

	printf("******************************************************\n");
	printf("Demonstration of dynamic loading of library at runtime\n");

	void* libraryHandle=0;
	char* libraryName="libcbaLib.so";
	/* Declaring symbols in the library, names of functions*/

	char* refFunc="refFunction";
	char* valFunc="valueFunction";


	/* Declaring function parameter */

	int i=10;
	printf("Initial value of parameter: %d\n",i);

	/* Declaring the pointer to value function */
        int(*f_ptr)(int)=0;

	/* Declaring the pointer to reference function */
	int(*f_ptr1)(int*)=0;


	printf("Loading the library %s dynamically \n",libraryName);

	libraryHandle = dlopen(	libraryName,RTLD_LAZY);
	if(0 == libraryHandle)
	{
		printf("Error loading library %s\n",dlerror());
		return -1;
	}

	printf("resolving the symbol %s\n",valFunc);
	f_ptr = (int(*)(int))dlsym(libraryHandle,valFunc);

	printf("executing %s from %s\n",valFunc,libraryName);
	f_ptr(i);
	printf("Parameter passed by value outside the function : %d\n",i);

	printf("resolving the symbol %s\n",refFunc);
        f_ptr1 = (int(*)(int*))dlsym(libraryHandle,refFunc);

        printf("executing %s from %s\n",refFunc,libraryName);
	f_ptr1(&i);
	printf("Parameter passed by reference(address of variable) outside the function : %d\n",i);

	printf("Unloading the library %s\n",libraryName);
	dlclose(libraryHandle);

	printf("Done ...\n");
	printf("******************************************************\n");	
	return 0;
}
