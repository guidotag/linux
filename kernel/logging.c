#include <linux/module.h>
#include <linux/sched.h>	/* current and task_struct */
#include <linux/printk.h>
#include <linux/syscalls.h>
#include <linux/logging.h>

asmlinkage long __x64_sys_register(void) {
	current->token = TOKEN;
	return 0;
}

asmlinkage long __x64_sys_unregister(void) {
	current->token = 0;
	return 0;
}

void log_vma_create(int token, unsigned long start, unsigned long end) {
    if (token == TOKEN) {
        printk("XTNTS %d vc %lu %lu", current->pid, start, end);
        // printk("XTNT flush");
    }
}

void log_vma_remove(int token, unsigned long start, unsigned long end) {
    if (token == TOKEN) {
        printk("XTNTS %d vr %lu %lu", current->pid, start, end);
        // printk("XTNT flush");
    }
}

void log_page_fault(int token, unsigned long virtual, unsigned long physical) {
    if (token == TOKEN) {
        printk("XTNTS %d pf %lu %lu", current->pid, virtual, physical);
        // printk("XTNT flush");
    }
}