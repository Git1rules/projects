/* Author:	Stephen Alexandrov
   Date  :	09-23-2019
   
*/

#include <flowControl.h>



int main(int argc,char **argv,char **pEnv)
{
	showIf(5);
	showIf(15);


	showSwitch(1);
	showSwitch(2);
	showSwitch(3);
	showSwitch(4);
	showSwitch(-1);

	showFor(10);


	showWhile(5);


	return 0;
}
