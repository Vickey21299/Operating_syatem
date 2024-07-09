#include<linux/kernel.h>
#include<linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include<linux/stat.h>
#include<linux/moduleparam.h>
#include <asm/uaccess.h>
#include <linux/fs.h> 
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/pid.h>
#include<linux/sched.h>
#include <linux/cred.h>
MODULE_LICENSE("GPL");
struct pid *struct_pid;
struct task_struct * task;
pid_t pgid;
pid_t uid;
int pid =23;
module_param(pid,int,0); // set parameter to execute the process
static int __init read_struct(void){
	struct_pid = find_get_pid(pid);
	task = pid_task(struct_pid,PIDTYPE_PID);
	pgid=pid_vnr(task_pgrp(task));
	printk(KERN_INFO "process id= %d\n",task->pid);
	printk(KERN_INFO "process user_id= %d\n",task->cred->uid);
	printk(KERN_INFO "process command path: %s\n",task->comm);
	printk(KERN_INFO "process group id is= %d\n",pgid);
	printk(KERN_INFO "testing");
	return 0;
}
static void __exit task_struct_exit(void){
	printk(KERN_INFO "%s","GoodBye"); // exit from the kernel or remove update module by using rmmod task.ko 
}
module_init(read_struct);
module_exit(task_struct_exit);