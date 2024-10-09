#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "os_base.h"

sem_t guard;

__attribute__ ((format (printf, 1, 2)))
void myPrintf(const char *fmt, ...)
{
    OS_SEM_DOWN(guard);
    int res;
    static char *buf = NULL;

    // EXTENSION
    // if fmt==NULL, flush buffer
    // myPrintf(NULL) == fflush(stdout)
    if (!fmt) {
        if (buf) {
            write(1, buf, strlen(buf));
            free(buf);
            buf = NULL;
        }
        OS_SEM_UP(guard);
        return;
    }

    va_list args;
    va_start(args, fmt);

    // format output to `local_buf`
    // assert if error or input is longer than buffer
    char local_buf[2048 + 1];
    int format_res = vsnprintf(local_buf, sizeof(local_buf), fmt, args);
    assert(format_res > 0 && format_res < sizeof(local_buf));
    
    // append local_buf to buf
    size_t new_buf_size = strlen(local_buf) + 1;
    if (buf)
        new_buf_size += strlen(buf);
    assert(buf = realloc(buf, new_buf_size));
    strcat(buf, local_buf);

    // print if contains '\n'
    if (isatty(1) && strchr(buf, '\n')) {
        write(1, buf, new_buf_size);
        free(buf);
        buf = NULL;
    }

    OS_SEM_UP(guard);
}

void *printed(void *num)
{
    myPrintf("Toto");
    myPrintf(" ");
    myPrintf("je");
    myPrintf(" ");
    myPrintf("volanie");
    myPrintf(" ");
    myPrintf("viacerich");
    myPrintf(" ");
    myPrintf("printov");
    myPrintf(" ");
    myPrintf("cislo");
    myPrintf(" ");
    myPrintf("(%d)", *(int*)num);
    myPrintf("\n");
}

void main_process(int argc, char * argv[])
{
    // 3.c
    myPrintf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    myPrintf("%s\n", __FUNCTION__);
    myPrintf(NULL); //fflush(stdout)

    int number = atoi(argv[1]);
    int indefinite = argc > 2;
    for (int i = 0; i < number; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            do
            {
                printed(&i);
            } while(indefinite);
            return;
        }
    }

    myPrintf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}

void main_thread(int argc, char *argv[])
{
    // 4.c
    myPrintf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    myPrintf("%s\n", __FUNCTION__);
    myPrintf(NULL); //fflush(stdout)

    pthread_t *ctx = malloc(sizeof(pthread_t)*atoi(argv[1]));
    assert(ctx);
    int *ids = malloc(sizeof(int)*atoi(argv[1]));
    assert(ids);
    int i;
    for (i = 0; i < atoi(argv[1]); ++i) {
            ids[i] = i;
            assert(pthread_create(ctx+i, NULL, printed, ids+i) == 0);
    }
    for (i = 0; i < atoi(argv[1]); ++i) {
            assert(pthread_join(ctx[i], NULL) == 0);
    }

    myPrintf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}

int main(int argc, char *argv[])
{
    os_base_init(FALSE, TRUE);
    OS_SEM_INIT(guard, 1);

    //myPrintf("Pred forkom");
    ////myPrintf(NULL);
    //fork();
    //myPrintf("Za forkom");

    //myPrintf("Pred forkom\n");
    //fork();
    //myPrintf("Za forkom\n");

    main_thread(argc, argv);
    myPrintf(NULL); //fflush(stdout)
    sleep(5);
    main_process(argc, argv);
    myPrintf(NULL); //fflush(stdout)
    sleep(5);

    OS_SEM_DESTROY(guard);
    os_base_destroy();
    return 0;
}
