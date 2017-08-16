#include <linux/module.h>                                        
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/list.h>

static int __init getpid_init(void)
{
	struct task_struct *task,*p;
	struct list_head *pos;
	int count = 0;
    printk("<1>hello,world! from the kernel space......\n");
	task = &init_task;
	list_for_each(pos,&task->tasks)
	{
		p = list_entry(pos,struct task_struct,tasks);
		count++;
		printk("<1>%d--->%s\n", p->pid, p->comm);
	}
	printk("<1>the num of process is:%d\n", count);
    return 0;
}

static void __exit getpid_cleanup(void)
{
    printk("<1>goodbye,world! leaving kernel space...\n");  
}

module_init(getpid_init);
module_exit(getpid_cleanup);
MODULE_LICENSE("GPL");
