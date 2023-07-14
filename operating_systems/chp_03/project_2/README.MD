# Project 2 — Linux kernel module for task information

In this project, I will write a Linux kernel module that uses the /proc file system for displaying a task's information based on its process identifier value pid. This project will involve writing a process identifier to the file /proc/pid. Once a pid has been written to the /proc file, subsequent reads from /proc/pid will report (1) the command the task is running, (2) the value of the task's pid, and (3) the current state of the task.

---
---
## Project Results
```bash
echo "1395" > /proc/pid
cat /proc/pid
command = [bash] pid = [1395] state = [1]
```
---
---

### **Linux tips for working with Kernel modules**
### **&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;And some project extras**

##### **Compile Module**
```bash
clear && make clean && make
```

##### **list all kernel modules that are currently loaded**
```bash
lsmod
```

##### **Check the contents of messages in the kernel log buffer**
```bash
dmesg
```

##### **Load kernel modules**
```bash
sudo insmod project2.ko
```

##### **Remove kernel modules**
```bash
sudo rmmod project2
```

##### **Clear kernel log buffer**
```bash
sudo dmesg -c
```
