#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/jiffies.h>

#define BUFFER_SIZE 128

#define PROC_NAME "jiffies"

// My assignment
// ---------------
// Design a kernel module that creates a /proc file named /proc/jiffies that reports the
// current value of jiffies when the /proc/jiffies file is read, such as with the command 
// "cat /proc/jiffies"
// Be sure to remove /proc/jiffies when the module is removed.

static ssize_t proc_read(struct file *file, char *buf, size_t count, loff_t *pos);

static struct proc_ops my_fops =
{
	.proc_read = proc_read,
};


static int proc_init(void)
{
	proc_create(PROC_NAME, 0, NULL, &my_fops);
	printk(KERN_INFO "/proc/%s created\n", PROC_NAME);

	return 0;
}

static void proc_exit(void)
{
	remove_proc_entry(PROC_NAME, NULL);
	printk( KERN_INFO "/proc/%s removed\n", PROC_NAME);
}


static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
	int rv = 0;
	char buffer[BUFFER_SIZE];
	static int completed = 0;
	unsigned long copyReturnValue; //<-- This variable is unused and only used to silence compiler warnings

	if (completed)
	{
		completed = 0;
		return 0;
	}
	
	completed = 1;

	rv = sprintf(buffer, "The current value of jiffies right now is :  %lu\n", jiffies);
	
	copyReturnValue = copy_to_user(usr_buf, buffer, rv);

	return rv;
}

module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello jiffies");

