#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cnt = 0;
int indefinite = 0;

void printed(int num)
{
    printf("hello from child process ");
    printf("(%d) ", getpid());
    //fflush(stdout);  //skus odkomentovat :)
    //sleep(1);
    printf("num %d, cnt %d ", num, cnt);
    printf("\n");
    cnt = cnt+1;
    sleep(5);
}

int main (int argc, char * argv[])
{
    int number = atoi(argv[1]);
    int indefinite = argc > 2;
    for (int i = 0; i < number; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            do {
                printed(i);
            } while(indefinite);
            return 0; //???
        }
    }

    printf("Zomrel som\n");
    return 0;
}
