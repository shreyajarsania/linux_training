#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/wait.h>
typedef struct 
{ 
	long int num;
	char msg_text[10]; 
} msg_queue;
