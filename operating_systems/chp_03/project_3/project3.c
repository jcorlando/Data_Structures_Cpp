#include <linux/module.h>


/* This function is called when the module is loaded. */
static int proc_init(void)
{
  // print to kernel log buffer
  printk(KERN_INFO "Loaded Project3 Module\n");

  return 0;
}


/* This function is called when the module is removed. */
static void proc_exit(void)
{
  // Print to kernel log buffer
  printk( KERN_INFO "Module Project3 Removed\n");
}


module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Project 3 — Linux Kernel Module for Listing Tasks");
MODULE_AUTHOR("Clint BeastWood");

