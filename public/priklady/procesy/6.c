/*
 * Napiste program, ktory usporiada thready podla poradia urcenom na obrazku.
 * Na dosiahnutie ciela pouzite minimum prostriedkov synchronizacie
 * 
 *           ____P3____P4____
 *          /                \
 *   P1___P2________P5________P6
 *
 */
#include <pthread.h>
#include <semaphore.h>

#include "os_base.h"

sem_t p1_p2;
sem_t p2_p3p5;
sem_t p3_p4;
sem_t p4p5_p6;

void* P1(void *args)
{
    OS_WORK();
    OS_SEM_UP(p1_p2);
}

void* P2(void *args)
{
    OS_SEM_DOWN(p1_p2);
    OS_WORK();
    OS_SEM_UP(p2_p3p5);
    OS_SEM_UP(p2_p3p5);
}

void* P3(void *args)
{
    OS_SEM_DOWN(p2_p3p5);
    OS_CS_WORK();
    OS_SEM_UP(p3_p4);
}

void* P4(void *args)
{
    OS_SEM_DOWN(p3_p4);
    OS_CS_WORK();
    OS_SEM_UP(p4p5_p6);
}

void* P5(void *args)
{
    OS_SEM_DOWN(p2_p3p5);
    OS_CS_WORK();
    OS_SEM_UP(p4p5_p6);
}

void* P6(void *args)
{
    OS_SEM_DOWN(p4p5_p6);
    OS_SEM_DOWN(p4p5_p6);
    OS_WORK();
}

int main (int argc, char * argv[])
{
    pthread_t p1, p2, p3, p4, p5, p6;

    os_base_init(TRUE, TRUE);

    OS_SEM_INIT(p1_p2, 0);
    OS_SEM_INIT(p2_p3p5, 0);
    OS_SEM_INIT(p3_p4, 0);
    OS_SEM_INIT(p4p5_p6, 0);

    pthread_create(&p6, NULL, P6, NULL);
    pthread_create(&p5, NULL, P5, NULL);
    pthread_create(&p4, NULL, P4, NULL);
    pthread_create(&p3, NULL, P3, NULL);
    pthread_create(&p2, NULL, P2, NULL);
    pthread_create(&p1, NULL, P1, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);
    pthread_join(p5, NULL);
    pthread_join(p6, NULL);

    OS_SEM_DESTROY(p1_p2);
    OS_SEM_DESTROY(p2_p3p5);
    OS_SEM_DESTROY(p3_p4);
    OS_SEM_DESTROY(p4p5_p6);
    
    os_base_destroy();

    return 0;
}

//Bonus napiste taketo riesenie kde pouzijete samostatne procesy namiesto threadov.
//pomocka os_base_init(FALSE, FALSE), man sem_init
