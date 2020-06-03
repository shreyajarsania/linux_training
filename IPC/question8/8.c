/******************************************************************************************************
 *
 * Implement message queue communication method between child and parent.
 *
******************************************************************************************************/
#include "8.h"

int main()
{	
	int status, msgid, num, okay;
	msg_queue sent, receive;

	/* inititate mesaage queue */
	msgid = msgget((key_t)1234, 0777 | IPC_CREAT);
	char string1[50], string2[50];
	
	status = fork();
	
	while(strcmp(receive.msg_text, "end") != 0 && strcmp(sent.msg_text, "end") != 0)
	{
		if(status != 0)
		{
			sleep(1);
			/* get data from user */
			printf("Enter message to send to child and end to end: ");
			gets(sent.msg_text);
			/* sent message into message queue */
			if( msgsnd(msgid, (void *)sent.msg_text, sizeof(sent.msg_text), 0) != 0)
			{
				printf("Error in sending data");
			}
		}
		else
		{
			/* receive message from parent process */
			msgrcv(msgid, (void *)receive.msg_text, sizeof(receive.msg_text), 0, 0);
			printf("Data received is : ");
			puts(receive.msg_text);
		}
	}
	
	msgctl(msgid, IPC_RMID, NULL);
	wait(&status);

	return 0;
}
