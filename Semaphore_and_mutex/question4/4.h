#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int buffer[16];
pthread_mutex_t lock;
int pro_loop = 0, con_loop = 0;

void *producer(void *argument);
void *consumer();
