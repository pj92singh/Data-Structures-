#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
/*
pj92singh
Prabhjit Singh

Basic premisis is that once a PID is in use its
indicated as a 1 in the array and when the release_pid()
function free itup ti goes back to 0

So the program will work as a multi-process program with multiple
child and parent process creating and freeing up the same program
from question 6.

If you wish to run it longer just change the count variable!
 */

#define MAX 10000 //pid ranges 500 to 1000
#define MIN 500
#define RANGE MAX - MIN //size of the array to hold pid

 int* pid_pool; //array defined externaly in pid_demo.c

int create_pid_pool()
{
	printf("Allocating the sapce for making the PID\n");
	//calloc allocates the array, initilizes the memory to 0 for us
	pid_pool = (int *)calloc(RANGE, sizeof(int));
	return pid_pool == NULL ? 0 : 1; //return 1 if calloc worked, or 0

}

int get_pid()
{
	//look for the first non zero element, which is "free pid"
	for(int i = 0; i < RANGE; ++i)
		if (!pid_pool[i]){
			pid_pool[i] = 1; //once found, set to 1 to indicate it as in use
			printf("%d\n", pid_pool[i]);
			return i + MIN; //return the PID
		}

	return 1;
}

int release_pid(int pid)
{
	printf("Realease the PID\n");
	pid_pool[pid - MIN] = 0; //set it to 0

	return !pid_pool[pid - MIN]; //check to see if it set to 0
}
int main(){
	int count=0, status = 2;
	do{
	//parent makes pid pool
	//then sleeps
	if(fork()){
	create_pid_pool();
	get_pid();
	//sleep again
	//allowing the child to release
	wait(&status);

	}
	//else the child will sleep
	//then release the pid
	else{
	sleep(2);
	release_pid(*pid_pool);
	//printf("Realease the PID\n");
	//pid_pool[pid - MIN] = 0; //set it to 0
	free(pid_pool);
	sleep(2);
	}
	++count;

}while(count<5);

return 0;

exit(0);

}
