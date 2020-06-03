#include "4.h"

int main()
{
	int num1, num2;

	printf("Enter 2 numbers \n");
	scanf("%d %d", &num1, &num2);
	
	my_add( num1, num2 );
	my_sub( num1, num2 );
	my_mul( num1, num2 );
	my_div( num1, num2 );
	
	return 0;
}
