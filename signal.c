#include<stdio.h>
#include<signal.h>
#include<stdarg.h>
void sigint(int sig);
void sigcont(int sig);
int main(void)
{
char a[100];
if(signal(SIGINT,&sigint)==SIG_ERR)  /*修改SIGINT信号到处理方法为sigint()函数*/
{
perror("sigint signal error!");
}
if(signal(SIGCONT,&sigcont)==SIG_ERR) /*修改SIGCONT信号到处理方法为sigcont()函数*/
{
perror("sigcont error!");
}
if(signal(SIGQUIT,SIG_IGN))
{
perror("sigquit error!");
}
printf("current process is:%d\n\n",getpid());
{
printf("input a:");
fgets(a,sizeof(a),stdin);
if(strcmp(a,"terminate\n")==0)
{
raise(SIGINT);
}
else if(strcmp(a,"continue\n")==0)
{
raise(SIGCONT);
}
else if(strcmp(a,"quit\n")==0)
{
raise(SIGQUIT);
}
else if(strcmp(a,"game over\n")==0)
{
raise(SIGTSTP);
}
else
{
printf("your input is:%s\n\n",a);
}
}
return 0;
}
void sigint(int sig)
{
printf("SIGINT signal %d:\n",sig);
}
void sigcont(int sig)
{
printf("SIGCONT signal %d:\n",sig);
}
