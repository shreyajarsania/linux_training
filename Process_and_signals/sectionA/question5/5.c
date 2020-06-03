/**************************************************************************
*
* Make a program where parent and child processes simultaneously works. 
* Parent will write capital 'ABCD..' into file & child process will write 
* small 'abcd ..' into the file.
*
***************************************************************************/

#include "5.h"
int main()
{
	pid_t pid;
	FILE *fp;
	char *message_parent, *message_child;
	int loop;

	/* on executing fork(), child process will be created */
		
	message_parent = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
	message_child = "abcdefghijklmnopqrstuvwxyz\n";
	pid = fork();

	fp = fopen("output.bin", "a");	
	for(loop = 0; loop < 5; loop++)
	{
		if (pid != 0) // parent will give positive int so execute if block
		{
			fprintf(fp, "%s", message_parent);

		}
		else // child proccess will execute else as it gives 0
		{
			fprintf(fp, "%s", message_child);
		}
	}
	fclose(fp);	
	exit(0);
}
