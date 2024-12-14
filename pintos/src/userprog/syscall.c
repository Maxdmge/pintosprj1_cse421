#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

//got these from 5.3 of project doc
static void sys_halt(void);
static void sys_exit(int status);
static pid_t sys_exec(const char *cmd_line);
static int sys_wait(pid_t pid);
static bool sys_create(const char *file, unsigned initial_size);
static bool sys_remove(const char *file);
static int sys_open(const char *file);
static int sys_filesize (int);
static int sys_read(int, void *, unsigned);
static int sys_write(int, const void *, unsigned);
static void sys_seek(int, unsigned);
static unsigned sys_tell(int);
static void sys_close(int);


static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  int sysnum = *(int *)f->esp;
  switch(sysnum){
    case SYS_HALT: // from lib user 
      sys_halt();
      break;
    case SYS_EXIT:
      sys_exit(*(int *)(f->esp+4));
      break;
    case SYS_EXEC: 
      f->eax= sys_exec(*(char **)(f->esp +4));
      break;
    case SYS_WAIT: 
      f->eax=sys_wait(*(pid_t *)(f->esp +4));
      break;
    case SYS_CREATE: 
      f->eax= sys_create(*(char **)(f->esp+4), *(unsigned *)(f->esp+8));
      break;
    case SYS_REMOVE:
      f->eax= sys_remove(*(char **)(f->esp +4));
      break;
    case SYS_OPEN:
      f->eax= sys_open(*(char **)(f->esp +4));
      break;
    case SYS_FILESIZE:
      f->eax= sys_filesize(*(int *)(f->esp +4));
      break;
    case SYS_READ:
      f->eax= sys_read(*(int *)(f->esp +4),*(void **)(f->esp+8),*(unsigned *)(f->esp+12));
      break;
    case SYS_WRITE: 
      f->eax= sys_write(*(int *)(f->esp +4),*(void **)(f->esp+8),*(unsigned *)(f->esp+12));
      break;
    case SYS_SEEK:
      sys_seek(*(int *)(f->esp +4),*(unsigned *)(f->esp +8));
      break;
    case SYS_TELL:
      f->eax = sys_tell(*(int *)(f->esp+4));
      break;
    case SYS_CLOSE:
      sys_close(*(int *)(f->esp+4));
      break;
    default;
      printf ("system call!\n");
      thread_exit ();
  }


static void sys_halt(void){// done
  shutdown_power_off(); 
}

static void sys_exit(int status){ //done
  struct thread *cur= thread_current();
  cur->checkexit = status;
  printf("%s: exit(%d)\n", cur->name, status);
  thread_exit();
}


static pid_t sys_exec(const char *cmd_line){
  if(cmd_line ==NULL){
    exit(-1);
  }
  }
}


static int sys_wait(pid_t pid){ //done
  return process_wait(pid);
}

static bool sys_create(const char *file, unsigned initial_size){

}

static bool sys_remove(const char *file){

}
static int sys_open(const char *file){

}
static int sys_filesize (int){

}
static int sys_read(int, void *, unsigned){

}
static int sys_write(int, const void *, unsigned){

}
static void sys_seek(int, unsigned){

}
static unsigned sys_tell(int){

}
static void sys_close(int){

}



}

