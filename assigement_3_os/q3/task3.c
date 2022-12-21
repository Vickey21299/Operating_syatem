#include<linux/kernel.h>
#include<linux/module.h>
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/pid.h>
#include<linux/sched.h>
#include <linux/cred.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include<linux/stat.h>
#include<linux/moduleparam.h>
#include <asm/uaccess.h>
#include <linux/fs.h> 




MODULE_LICENSE("GPL");
struct pid *struct_pid;
struct task_struct * task;
pid_t pgid;
pid_t uid;
int set_int=434;
module_param(set_int,int,0);
static int __init task_read_struct(void){
	struct_pid = find_get_pid(set_int);
	task = pid_task(struct_pid,PIDTYPE_PID);
	pgid=pid_vnr(task_pgrp(task));
	printk(KERN_ALERT "process id= %d\n",task->pid);
	printk(KERN_ALERT "process user_id= %d\n",task->cred->uid);
	printk(KERN_ALERT "process command path: %s\n",task->comm);
	printk(KERN_ALERT "process group id is= %d\n",pgid);
	printk(KERN_ALERT "testing");
	return 0;
}
//exit by using rmmod to remove modules
static void __exit task_exit(void){
	printk(KERN_ALERT "Exit\n","GoodBye");
}
//MODULE_LICENSE("GPL");
module_init(task_read_struct);
module_exit(task_exit);