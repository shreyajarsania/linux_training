/*******************************************************************************
*
* #include <stdio.h>
* #include <unistd.h>

*	int main()
*	{
*	    if (fork()) {
*		if (!fork()) {
*		    fork();
*		    printf("1 ");
*		}
*		else {
*		    printf("2 ");
*		}
*	    }
*	    else {
*		printf("3 ");
*	    }
*	    printf("4 ");
*	    return 0;
*	}
*
*******************************************************************************/

#include "3.h"

int main()
{
    if (fork()) 
    {
	if (!fork()) 
	{
	    fork();
	    printf("1 ");
	}
	else 
	{
	    printf("2 ");
	}
    }
    else 
    {
	printf("3 ");
    }
    printf("4 ");
    return 0;
}

/* here 1st if(fork) is executed and 1 child process is created,
 * now the parent process passes the condition but child proccess cannot
 * so child executes else block and parent executes if block
 *
 * in if block - in if(!fork()) one more child is created by parent proccess, parent fails this condtion and moves to else block and prints 2 then 4, whereas child passes the conditon goes into if block, it runs another fork and created one more child - fork(); and prints 1 then 4, now created child will again go into if block and print 1 then 4
 *
 * the 1st child executing outer else block will give 3 then 4
 */
