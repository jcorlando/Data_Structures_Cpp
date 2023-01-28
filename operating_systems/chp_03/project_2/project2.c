#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

#define BUFFER_SIZE 512
#define PROC_NAME "pid"


// Function prototypes for user space reading & writing of /proc/pid
static ssize_t proc_read(struct file *file, char *buf, size_t count, loff_t *pos);
static ssize_t proc_write(struct file *file, const char __user *usr_buf, size_t count, loff_t *pos);


// Kernel structure for Reading/Writing to /proc/ files
static struct proc_ops proc_pid_fops = {
  .proc_read = proc_read,
  .proc_write = proc_write
};


/* This function is called when the module is loaded. */
static int proc_init(void)
{
  /* creates the /proc/pid entry */
  proc_create(PROC_NAME, 0666, NULL, &proc_pid_fops);

  // print to kernel log buffer
  printk(KERN_INFO "Loaded /proc/ PID Module\n");
  
  return 0;
}

/* This function is called when the module is removed. */
static void proc_exit(void)
{
  /* removes the /proc/pid entry */
  remove_proc_entry(PROC_NAME, NULL);

  // Print to kernel log buffer
  printk( KERN_INFO "Module /proc/ PID Removed\n");
}

// Function definition for user space reading of /proc/pid
static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
  int returnValue = 0;
  char buffer[BUFFER_SIZE];
  static int completed = 0;

  // This variable is unused and is only used to silence compiler warnings
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



// Function definition for user space writing to /proc/pid
static ssize_t proc_write(struct file *file, const char __user *usr_buf, size_t count, loff_t *pos)
{
  char *k_mem;

  /* allocate kernel memory */
  k_mem = kmalloc(count, GFP_KERNEL);

  /* copies user space usr_buf to kernel buffer */
  if (copy_from_user(k_mem, usr_buf, count)) {
    printk( KERN_INFO "Error copying from user\n");
    return -1;
  }

  // --> How do I use this
  // kstrtol(const char *str, unsigned int base, long *res);

  printk(KERN_INFO "%s\n", k_mem);

  /* return kernel memory */
  kfree(k_mem);

  return count;
}



module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Project 2 — Linux kernel module for task information");
MODULE_AUTHOR("Clint BeastWood");

