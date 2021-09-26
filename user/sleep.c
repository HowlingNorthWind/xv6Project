#include "kernel/types.h"
#include "user/user.h"

int main(int argn, char *argv[]){
	int Num = atoi(argv[1]);
	sleep(Num);
	exit(0);
}

