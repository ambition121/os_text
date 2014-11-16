#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<string.h>
void init_daemon(void);
int main()
{
char IP[13],cmd[100] = "ifconfig eth0";
FILE *fp,*fp1;
int offset;
init_daemon();
while(1)
{
	if((fp = fopen("IP","r")) == NULL)
	{
		printf("failed to open IP");
		exit(1);
	}
	if((fp = fopen("IPLOG","a+")) == NULL)
	{
		printf("failed to open IPLOG");
		exit(1);
	}
srand((int)time(0));
offset = rand()/(RAND_MAX+1.0)*10.0;
fseek(fp,offset*13,SEEK_SET);
fread(IP,13,1,fp);
strcat(cmd,IP);
fprintf(fp1,"正在运行%s",cmd);
system(cmd);
//execlp("ifconfig","ifconfig","eth0",IP,NULL);
rewind(fp);
strcpy(cmd,"ifconfig eth0");
fclose(fp);
fclose(fp1);
sleep(30);
	}
}


//创建守护进程
void init_daemon(void)
{
pid_t child1;
int i;
child1 = fork();
if(child1>0)
	exit(0);
else if(child1<0)
{
	perror("failed");
	exit(1);
}
setsid();				//创建新会话期
chdir("/home/nearu/c_prog");		//改变目录
umask(0);				//重置文件掩码
for(i=0;i<NOFILE;i++)			//关闭文件描述符
	close(i);
return;
}
