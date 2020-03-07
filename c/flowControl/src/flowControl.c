/* Author:	Stephen Alexandrov
   Date  :	09-23-2019
   
*/
#include <flowControl.h>


void showIf(int marker)
{

	printf("IF demo\n");
	if(marker >13)
	{
		printf("marker is over 13\n");
	}
	else
	{
		printf("marker is not over 13\n");	
	}
}

void showSwitch(int marker)
{
	printf("SWITCH demo\n");
	switch (marker)
	{
		case 1:
			printf("the value is one\n");
		break;
		case 2:
		case 3:
			printf("the value is either two or three\n");
                break;

		case 4:
			printf("the value is four\n");
                break;

		default:
			printf("the value is out of range\n");

	}

}

void showFor(int marker)
{
	printf("FOR demo\n");
	for(int i=0;i<marker;i++)
	{
		printf("Iteration %d of %d\n",i+1,marker);
	}
}

void showWhile(int marker)
{
	printf("While demo\n");
	int i=0;
	while(i<marker)
	{
		 printf("Iteration %d of %d\n",++i,marker);

	}

	printf("DO while will run at least once\n");
	do
	{
		printf("Iteration %d of %d\n",++i,marker);	

	} while (i<marker);


	printf("inifinite loop\n");
	while(1)
	{
		i++;	

		//Note: iteration 9 will miss out the printing part
		 if(i == 9)continue;
		printf("%d %s \n",i,"iteration");

		//will leave the loop after iteration 13
		if (i>13) break;
	}

}
