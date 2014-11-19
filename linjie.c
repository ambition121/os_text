#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int counter = 0;//
pthread_mutex_t mux;//counter的互斥锁
void thread1(void *arg);
void thread2(void *arg);
int main(int argc,char *argv[])
{
pthread_t id1,id2;
unsigned int slp1,slp2;

/*初始化互斥锁*/
pthread_mutex_init(&mux,NULL);

/*用户自定义休眠时间*/
printf("please print the sleep time slp1 and slp2:\n");
scanf("%d",&slp1);
scanf("%d",&slp2);

/*创建第一个线程*/
pthread_create(&id1,NULL,(void *)thread1,(void *)&slp1);

/*创建第二个线程*/
pthread_create(&id2,NULL,(void *)thread2,(void *)&slp2);

/*等待两个线程完成*/
pthread_join(id1,NULL);
pthread_join(id2,NULL);

/*print the last value of<counter>*/
printf("最后的 counter 值%d\n",counter);
exit(0);
}
void thread1(void *arg)/*第一个线程执行代码*/
{
int i,val;
for(i=1;i<=5;i++){

/*lock*/
pthread_mutex_lock(&mux);
val=++counter;
printf("第一个线程：第 %d 次循环，第一次引用counter=%d\n",i,counter);

/*LINE A*/
sleep(*((unsigned int *)arg));/*睡眠挂起slp1秒*/
counter=val;

/*unlock*/
pthread_mutex_unlock(&mux);
}
}
void thread2(void *arg)/*第二个线程执行代码*/
{
int i,val;
for(i=1;i<=5;i++){
 
/*lock*/
pthread_mutex_lock(&mux);
val=++counter;
sleep(*((unsigned int *)arg));/*睡眠挂起slp2秒*/
printf("第二个线程：第 %d 次循环，counter=%d\n",i,counter);
counter=val;
 
/*unlock*/
pthread_mutex_unlock(&mux);
}
}

