/*******************************************************************************
*
* What is the output of the following code?
*	#include <stdio.h>
*	#include <unistd.h>
*	int main()
*	{
*	    if (fork() || fork())
*		fork();
*	    printf("1 ");
*	    return 0;
*	}
*
*******************************************************************************/

#include "2.h"

int main()
{
    if (fork() || fork())
	fork();
    printf("1 ");
    return 0;
}

/* Here 1st fork() will create 1 child
 * then or will be checked, as Parent is positve int it passess condition n goes into if block
 * parent further runs 3rd fork and we get 1 more child
 * as the 1st child will not pass the condition it will go for 2nd fork and create 1 more child
 * further the child will enter if block and run 3rd fork creating 1 more child
 * 
 * hence we get 5 proceesses - 4 child and 1 parent
