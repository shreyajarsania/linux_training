#include "4.h"
int my_div( int num1, int num2 )
{
	if(num2 == 0)
	{
		printf("2nd number canont be 0");
	}
	else
	{
		printf("Division of %d and %d is %d\n", num1, num2, num1 / num2);
	}
}
