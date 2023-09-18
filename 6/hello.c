#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwsem.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DECLARE_RWSEM(mylock);
static struct task_struct *thread1, *thread2, *thread3;

int counter = 0;

static int write_threadfn(void *arg)
{
	pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
	down_write(&mylock);
	pr_info("processor:%d acquired write lock\n", smp_processor_id());
	counter++;
	msleep(7000);
	up_write(&mylock);
	pr_info("processor%d released write lock\n", smp_processor_id());
	return 0;
}

static int read_threadfn(void *arg)
{
	pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
	down_read(&mylock);
	pr_info("processor:%d acquired read lock\n", smp_processor_id());
	pr_info("processor%d\t counter:%d\n", smp_processor_id(), counter);
	msleep(5000);
	up_read(&mylock);
	pr_info("processor:%d releasing read lock\n", smp_processor_id());
	return 0;
}

static int __init test_hello_init(void)
{
	thread1 = kthread_run(read_threadfn, NULL, "thread1");
	thread2 = kthread_run(read_threadfn, NULL, "thread2");
	thread3 = kthread_run(write_threadfn, NULL, "thread3");
	return 0;
}

static void __exit test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);
