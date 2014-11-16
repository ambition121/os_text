#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
 void sig_term(int sig)
 {
         pid_t p;
         int i = 0;
         waitpid(p,&i,0);
         printf("%d\n",WEXITSTATUS(i));
 }


int main()
{
pid_t p;
	int i=0,j=0;
	p = fork();
	if(p<0){
		perror("fork error\n");
		exit(1);
	}
	if(p>0){
		for(;i<20;i++){
		sleep(1);
		signal(SIGCHLD,sig_term);
		printf("parent\n");
		}
	}
else{
	for(;j<5;j++){
		sleep(1);
		printf("child\n");
	}
	exit(2);
	}
	return 1;
}

