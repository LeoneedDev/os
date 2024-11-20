#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

//named semaphores

#define P_COLOR "\033[96m"
#define C_COLOR "\033[95m"
#define E_COLOR "\033[0m"

int main (int argc, char * argv[])
{
    pid_t pid = fork();

    if (pid)
    {
        sem_t * p1 = sem_open("guard", O_CREAT, 0644, 0);
        printf(P_COLOR "parent is running\n" E_COLOR);
        sleep(10);
        printf(P_COLOR "parent guard up()\n" E_COLOR);
        sem_post(p1);
        sem_close(p1);
        sem_unlink("guard");
    }
    else
    {
        sem_t * p1 = sem_open("guard", O_CREAT, 0644, 0);
        printf(C_COLOR "child is waiting\n" E_COLOR);
        sem_wait(p1);
        printf(C_COLOR "child is running\n" E_COLOR);
        sem_close(p1);
    }
    return 0;
}
