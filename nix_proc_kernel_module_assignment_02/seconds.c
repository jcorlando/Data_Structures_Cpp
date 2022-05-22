#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <asm/param.h>
#include <linux/jiffies.h>

#define BUFFER_SIZE 512

#define PROC_NAME "seconds"

// My assignment
// ---------------
// Design a kernel module that creates a proc file named /proc/seconds that reports the number of elapsed
// seconds since the kernel module was loaded. This will involve using the value of jiffies as well as the
// HZ rate. When a user enters the command your kernel module will report the number of seconds that have elapsed
// since the kernel module was first loaded. Be sure to remove /proc/seconds when the module is removed.

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

	// Goodbye World!
	

	rv = sprintf(buffer, "The number of elapsed seconds since the kernel module was loaded is : %i\n", HZ);
	
	copyReturnValue = copy_to_user(usr_buf, buffer, rv);

	return rv;
}

module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello seconds");

