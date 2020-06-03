/********************************************************************************************
 *
 * Write a program to create a thread, thread routine should increment a number in infinite 
 * loop, main() should also increment a number and print the same. For both the programs, 
 * starting number will be given as input from command line. For both the programs, when user 
 * presses CTRL+C, the program should stop printing the number and should exit gracefully.
 *
*********************************************************************************************/

#include "4.h"

int num;
void sigint(int sig)
{
        printf("program is terminated successfuly\n");
	exit (0);
}

int main(int argc, char *argv[])
{
	if( argv[1]== NULL)
	{
		printf("ENter a valid value");
		exit (0);
	}
	num = atoi(argv[1]);
	
	pthread_t thread;
	pthread_attr_t attribute;
	int thread_status;
	struct sigaction act;
	struct sched_param param;

	thread_status = pthread_create( &thread, NULL, infinite_fun,  NULL );
	
	pthread_attr_getschedparam (&attribute, &param);
	param.sched_priority = -19;
	pthread_attr_setschedparam (&attribute, &param);
	pthread_create (&thread, &attribute, infinite_fun, NULL); 


	/* dummy handler for sigint using sig action*/
        act.sa_handler = sigint;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
	sigaction(SIGINT, &act, 0);

	/* infintie loop inside main thread */
	while(1)
	{
		printf("from main thread %d\n", num++);
		sleep(1);
	}

	/* terminate the thread */
	thread_status = pthread_join(thread, NULL);
	if(thread_status != 0)
	{
		printf("Thread jion failed\n");
	}
	else
	{
		printf("thread join failed\n");
	}
	return 0;
}

void *infinite_fun()
{
	struct sigaction act;
	act.sa_handler = sigint;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;

	sigaction(SIGINT, &act, 0);
	while(1)
        {
                printf("from other thread %d\n", num++);
		sleep(1);
        }
}
