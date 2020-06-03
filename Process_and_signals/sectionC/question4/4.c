/**************************************************************************
*
* Write a program and do the following :using sigaction API, handle SIGINT,
* SIGTERM, SIGQUIT, SIGSTOP, SIGTSTP and SIGKILL. Install dummy handlers for
* the mentioned signals Using sigaction() system call API !!!
*
***************************************************************************/

#include "4.h"

/* define the functions to handle each signal */
void sigint(int sig)
{
	printf("program faced SIGINT signal with signal no. %d", sig);
}
void sigterm(int sig)
{
	printf("program faces SIGTERM signal with signal no. %d", sig);
}
void sigquit(int sig)
{
        printf("program faces SIGQUIT signal with signal no. %d", sig);
}
void sigstop(int sig)
{
        printf("program faces SIGSTOP signal with signal no. %d", sig);
}
void sigtstp(int sig)
{
        printf("program faces SIGTSTP signal with signal no. %d", sig);
}
void sigkill(int sig)
{
        printf("program faces SIGKILL signal with signal no. %d", sig);
}


int main()
{
	struct sigaction act;

	/* dummy handler for sigint */
	act.sa_handler = sigint;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, 0);
	
	/* dummy handler for sigterm */
	act.sa_handler = sigint;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;

	sigaction(SIGTERM, &act, 0);
	
	/* dummy handler for sigquit */
	act.sa_handler = sigterm;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
	
	sigaction(SIGQUIT, &act, 0);
	
	/* dummy handler for sigstop */
	act.sa_handler = sigstop;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
	
	sigaction(SIGSTOP, &act, 0);
	
	/* dummy handler for sigtstp */
	act.sa_handler = sigtstp;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
	
	sigaction(SIGTSTP, &act, 0);
	
	/* dummy handler for sigkill */
	act.sa_handler = sigkill;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
	
	sigaction(SIGKILL, &act, 0);
	
	while(1) 
	{
		printf("give the signal\n");
		sleep(1);
	}
}
