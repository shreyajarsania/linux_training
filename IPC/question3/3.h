#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

typedef struct
{
	int num;
	char str[50][100];
}shared_mem;
