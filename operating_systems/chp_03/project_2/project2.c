#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define BUFFER_SIZE 512
#define PROC_NAME "pid"


// Function prototype for user space reading of /proc/pid
static ssize_t proc_read(struct file *file, char *buf, size_t count, loff_t *pos);


// Kernel structure for Reading/Writing to /proc/ files
static struct proc_ops proc_pid_fops = {
  .proc_read = proc_read,
};


/* This function is called when the module is loaded. */
static int proc_init(void)
{
  /* creates the /proc/pid entry */
  proc_create(PROC_NAME, 0666, NULL, &proc_pid_fops);

  printk(KERN_INFO "Loaded /proc/ PID Module\n");
  
  return 0;
}

/* This function is called when the module is removed. */
static void proc_exit(void)
{
  /* removes the /proc/hello entry */
  remove_proc_entry(PROC_NAME, NULL);
  printk( KERN_INFO "Module /proc/ PID Removed\n");
}

// Function definition for user space reading of /proc/pid
static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
  int returnValue = 0;
  char buffer[BUFFER_SIZE];
  static int completed = 0;

  // This variable is unused and only used to silence compiler warnings
  static unsigned long copyReturnValue;

  if (completed) {
    completed = 0;
    return 0;
  }

  completed = 1;

  returnValue = sprintf( buffer, "The PID info is  ==  \"PID info goes here\"\n" );

  copyReturnValue = copy_to_user(usr_buf, buffer, returnValue);

  return returnValue;
}


module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Project 2 — Linux kernel module for task information");
MODULE_AUTHOR("Clint BeastWood");

