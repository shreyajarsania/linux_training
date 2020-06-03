#include "1.h"

int main(int argc, char *argv[])
{
	int bytes, file_des, num;
	
	sscanf(argv[1],"%d", &file_des); 
	bytes = read(file_des, &num, sizeof(num)); // copy pipe data to num

	printf("%d - read %d bytes: %d\n", getpid(), bytes, num);
	exit(0);
}
