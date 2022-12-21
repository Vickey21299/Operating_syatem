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

MODULE_LICENSE ("GPL");
pid_t uid;
struct pid *struct_pid;
pid_t pgid;
struct task_struct *task;

int value =78;
module_param(value, int,0);
static int __init read_struct(void){ //dfg
task = pid_task(struct_pid, PIDTYPE_PID);//task

if (task==0){
    return -EINVAL;
}

struct_pid = find_get_pid(value);

if (struct_pid==0){
    return -EINVAL;
}
pgid=pid_vnr(task_pgrp(task));

printk(KERN_ALERT "Printing all details---\n");
printk(KERN_ALERT "process_command_path: %s\n", task->comm);
printk(KERN_ALERT "process group id is= %d\n",pgid);
printk(KERN_ALERT "process user-%d\n", task->cred->uid);
// printk(KERN_ALERT "process id- %d\n", task->pid);
return 0 ;
}

static void __exit task_struct_exit(void){//dfgh
    printk(KERN_INFO "%s Exiting\n", "GoodBye");
}
module_init(read_struct);//fgh
module_exit(task_struct_exit);//fg