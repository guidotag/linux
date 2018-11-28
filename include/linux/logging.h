#ifndef __LOGGING_H
#define __LOGGING_H

#define TOKEN 12345

void log_vma_create(int token, unsigned long start, unsigned long end);
void log_vma_remove(int token, unsigned long start, unsigned long end);
void log_page_fault(int token, unsigned long virtual, unsigned long physical);

#endif