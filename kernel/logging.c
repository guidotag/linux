#include <linux/module.h>
#include <linux/sched.h>	/* current and task_struct */
#include <linux/printk.h>
#include <linux/syscalls.h>

int logging_pid = -1;

EXPORT_SYMBOL(logging_pid);

asmlinkage long __x64_sys_logging_set(void) {
	logging_pid = current->pid;
	return 0;
}

asmlinkage long __x64_sys_logging_unset(void) {
	logging_pid = -1;
	return 0;
}
