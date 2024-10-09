#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "os_base.h"

sem_t guard;
volatile int cnt = 0;

void *printed(void *num)
{
    OS_SEM_DOWN(guard);
    sleep(1);
    printf("hello from thread ");
    printf("%d", *(int *)num);
    printf("\n");
    cnt = cnt+1;
    OS_SEM_UP(guard);
    return NULL;
}

int main(int argc, char *argv[])
{
    os_base_init(FALSE, TRUE);
    OS_SEM_INIT(guard, 1);

    int number = atoi(argv[1]);
    pthread_t *ctx = malloc(sizeof(pthread_t)*number);
    assert(ctx);
    int i;
    for (i = 0; i < number; ++i) {
        assert(pthread_create(ctx+i, NULL, printed, &i) == 0);
    }
    for (i = 0; i < number; ++i) {
        assert(pthread_join(ctx[i], NULL) == 0);
    }

    printf("Uspesne bolo vykonanych '%d' printerov\n", cnt);

    OS_SEM_DESTROY(guard);
    os_base_destroy();

    return 0;
}
