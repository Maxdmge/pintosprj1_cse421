#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include <list.h>
void syscall_init (void);

typedef int pid_t;

struct file_des{
    int fd;
    struct file *file;
    struct list_elem elem;
};

#endif /* userprog/syscall.h */
