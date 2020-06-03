#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

typedef struct
{
	char name[20];
	char address[500];
	long int phone;
}details;
