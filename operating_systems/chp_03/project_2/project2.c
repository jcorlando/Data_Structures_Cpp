#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/jiffies.h>

// Module Logic Starts here
static int proc_init(void)
{
  printk(KERN_INFO "Loading Module");
  return 0;
}

static void proc_exit(void)
{
  printk( KERN_INFO "Module Terminated\n");
}



module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Project 2 — Linux kernel module for task information");

