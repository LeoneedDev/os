#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

//named semaphores

int main (int argc, char * argv[])
{
    pid_t pid = fork();

    if (pid)
    {
        sem_t * p1 = sem_open("guard", O_CREAT, 0644, 0);
        printf("parent is running\n");
        sleep(10);
        sem_post(p1);
        sem_close(p1);
        sem_unlink("guard");
    }
    else
    {
        sem_t * p1 = sem_open("guard", O_CREAT, 0644, 0);
        printf("child is waiting\n");
        sem_wait(p1);
        printf("child is running\n");
        sem_close(p1);
    }
    return 0;
}
