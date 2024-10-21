#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile int cnt  = 0;
int j = 0;
void *printed(void *num)
{
    sleep(1); //skus ma presuvat
    printf("hello from thread ");
    printf("%d - %d", *(intptr_t)num, j); //#1
    //printf("%d - %d", (int)(intptr_t)num, j); //#2
    printf("\n");
    cnt = cnt+1;
    return NULL;
}

int main(int argc, char *argv[])
{
    int number = atoi(argv[1]);
    pthread_t *ctx = malloc(sizeof(pthread_t)*number);
    assert(ctx);
    int i;
    for (i = 0; i < number; ++i, ++j) {
        assert(pthread_create(ctx+i, NULL, printed, &i) == 0); //#1
        //assert(pthread_create(ctx+i, NULL, printed, (void *)(intptr_t)i) == 0); //#2
    }
    sleep(1); // skus ma presuvat
    for (i = 0; i < number; ++i) {
        assert(pthread_join(ctx[i], NULL) == 0);
    }

    printf("Uspesne bolo vykonanych '%d' printerov\n", cnt);
    return 0;
}
