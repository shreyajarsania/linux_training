#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/ipc.h> 
#include <sys/msg.h>

typedef struct 
{ 
	long msg_type; 
	int msg_num; 
} msg_queue;

msg_queue message, buffer;
sem_t syn;

void *producer();
void *consumer();

int msgid;
