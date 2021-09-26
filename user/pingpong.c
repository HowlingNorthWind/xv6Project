#include <kernel/types.h>
#include <user/user.h>

int main(){

	int p1[2];
	int p2[2];
	pipe(p1);
	pipe(p2);
	
	int pid;
	if((pid=fork())==0)
	{
		close(p2[0]);
		close(p1[1]);
		
		write(p2[1],"pong",4);
		close(p2[1]);
		
		char buf[10];
		read(p1[0],buf,4);
		close(p1[0]);
		printf("%d: received %s\n",getpid(),buf);
		
	}
	else
	{
		close(p1[0]);
		close(p2[1]);
		
		write(p1[1],"ping",4);
		close(p1[1]);
		
		char buf[10];
		read(p2[0],buf,4);
		close(p2[0]);
		printf("%d: received %s\n",getpid(),buf);
		
	}
	
	exit(0);
}

