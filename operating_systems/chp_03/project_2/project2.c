#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

/* This function is called when the module is loaded. */
static int proc_init(void)
{
  printk(KERN_INFO "Loading Module");
  return 0;
}

/* This function is called when the module is removed. */
static void proc_exit(void)
{
  printk( KERN_INFO "Module Terminated\n");
}



module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Project 2 — Linux kernel module for task information");
MODULE_AUTHOR("Clint BeastWood");

