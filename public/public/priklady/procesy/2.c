#include <pthread.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

//man pthread_create

#define gettid() syscall(SYS_gettid)
int indefinite;

void* child(void *args)
{
    do {
        printf("executing child: pid - %d tid - %d\n", getpid(), gettid());
        sleep(3);
    } while(indefinite);
}

int main (int argc, char * argcv[])
{
    pthread_t p1;
    pthread_create(&p1, NULL, child, NULL);
    indefinite = argc > 1;

    do {
        printf("executing parent: pid - %d tid - %d\n", getpid(), gettid());
        sleep(2);
    } while(indefinite);

    pthread_join(p1, NULL);

    return 0;
}
