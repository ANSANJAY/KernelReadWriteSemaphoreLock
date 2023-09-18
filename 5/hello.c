#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwsem.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct rw_semaphore *mysem;

static int __init test_hello_init(void)
{
    mysem = kmalloc(sizeof(mysem), GFP_KERNEL);
    init_rwsem(mysem);
    pr_info("init_rwsem count:%ld\n", atomic_long_read(&mysem->count));
    down_write(mysem);
    pr_info("down_write count:%ld\n", atomic_long_read(&mysem->count));
    down_write(mysem);
    pr_info("down_write count:%ld\n", atomic_long_read(&mysem->count));
    kfree(mysem);
    return -1;
}

static void __exit test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);
