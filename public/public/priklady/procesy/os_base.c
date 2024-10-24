#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#include "os_base.h"

#define RESET_WATCHDOG watchDog.timer = 5

//globals

struct {
   pthread_t thread;
   int timer;
   bool end;
} watchDog;

bool hasWatchDog;
sem_t printGuard;
const char * threadInCS;

//watchDog entry function

void* check(void *args)
{
    while(!watchDog.end)
    {
        sleep(1);
        sem_wait(&printGuard);
        if (watchDog.timer == 0)
        {
            printf("ERROR: It is probable we have deadlock kill program with ctrl-C\n");
        }
        else
        {
            watchDog.timer--;
        }
        sem_post(&printGuard);
    }
}

//public functions

void os_base_init(bool enableWatchDog, bool asThread)
{
    printf("Start\n");
    watchDog.end = FALSE;
    RESET_WATCHDOG;
    threadInCS = NULL;
    sem_init(&printGuard, !asThread, 1);
    hasWatchDog = enableWatchDog;
    if(hasWatchDog)
    {
        pthread_create(&watchDog.thread, NULL, check, NULL);
    }
}

void os_base_destroy()
{
    watchDog.end = TRUE;
    if(hasWatchDog)
    {
        pthread_join(watchDog.thread, NULL);
    }
    sem_destroy(&printGuard);
    printf("Stop\n");
}

void os_sem_down(sem_t * pSem, const char * semName, const char * threadName)
{
    sem_wait(&printGuard);
    int value = 0;
    sem_getvalue(pSem, &value);
    printf("%s: os_sem_down on '%s' %s\n", threadName, semName, (value > 0) ? "entering" : "blocked");
    sem_post(&printGuard);
    sem_wait(pSem);
}

void os_sem_up(sem_t * pSem, const char * semName, const char * threadName)
{
    sem_wait(&printGuard);
    printf("%s: os_sem_up on '%s'\n", threadName, semName);
    sem_post(&printGuard);
    sem_post(pSem);
}

void os_work(const char * threadName)
{
    sleep(1);

    sem_wait(&printGuard);
    printf("%s: ---work---\n", threadName);
    RESET_WATCHDOG;
    sem_post(&printGuard);
}

void os_cs_work(const char * threadName)
{
    sem_wait(&printGuard);
    if (threadInCS != 0)
    {
        printf("ERROR: muttual exclusion violated in CS is: '%s' and '%s'\n", threadInCS, threadName);
    }
    threadInCS = threadName;
    sem_post(&printGuard);

    sleep(1);

    sem_wait(&printGuard);
    printf("%s: ---CS-work---\n", threadName);
    threadInCS = NULL;
    RESET_WATCHDOG;
    sem_post(&printGuard);
}

