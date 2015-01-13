#include<stdio.h>
int main()
{
int hoge = 5;
int piyo = 10;
int *hoge_p;

/*输出变量地址*/
printf("&hoge..%p\n",&hoge);
printf("&pigo..%p\n",&piyo);
printf("&hoge_p..%p\n",&hoge_p);


hoge_p = &hoge;			//将hoge的地址赋给hoge_p
printf("hoge_p..%p\n",hoge_p);

printf("*hoge_p..%d\n",*hoge_p);	//通过hoge_P输出hoge的内容

/*通过hoge_p修改hoge的内容*/
*hoge_p = 10;
printf("hoge..%d\n",hoge);

return 0;
}
