#include <stdbool.h>

#define FALSE 0
#define TRUE 1

//wrapers

#define OS_SEM_INIT(pSem, cnt) \
    sem_init(&pSem, FALSE, cnt)

#define OS_SEM_DOWN(pSem) \
    os_sem_down(&pSem, #pSem, __FUNCTION__)

#define OS_SEM_UP(pSem) \
    os_sem_up(&pSem, #pSem, __FUNCTION__)

#define OS_SEM_DESTROY(pSem) \
    sem_destroy(&pSem)

#define OS_WORK() \
    os_work(__FUNCTION__)

#define OS_CS_WORK() \
    os_cs_work(__FUNCTION__)

/*
 * init internal printing semaphore and watchDog thread
 */
void os_base_init(bool enableWatchDog, bool asThread);

/*
 * destroy watchDog thread and printing semaphore
 */
void os_base_destroy();

/*
 * wrapers around posix sem_wait() sem_post() functions.
 * this prints info which semaphore was touched and who touched it. 
 */
void os_sem_down(sem_t * pSem, const char * semName, const char * threadName);
void os_sem_up(sem_t * pSem, const char * semName, const char * threadName);

/*
 * functions simulating some work
 * function execution can take at least one second
 * os_cs_work checks whether more threads enetered the function
 */
void os_work(const char * threadName);
void os_cs_work(const char * threadName);
