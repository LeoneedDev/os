#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

//man syscall
//man fork
//man getpid

#define gettid() syscall(SYS_gettid)

int main (int argc, char * argcv[])
{
    int indefinite = argc > 1;
    pid_t pid = fork(); 
    if (pid == 0)
    {
        do {
            printf("executing child:  pid - %d; tid - %ld\n", getpid(), gettid());
            sleep(3);
        } while(indefinite);
    }
    else
    {
        do {
            printf("executing parent: pid - %d; tid - %ld\n", getpid(), gettid());
            sleep(2);
        } while(indefinite);
    }

    return 0;
}
