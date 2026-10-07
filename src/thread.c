#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "../include/thread.h"

pthread_mutex_t monitor_lock = PTHREAD_MUTEX_INITIALIZER;

void *monitor(void *arg)
{
    (void)arg;

    while (1)
    {
        sleep(10);
        
        pthread_mutex_lock(&monitor_lock);

        printf("\n[Monitor] Process Manager Running...\n");
        fflush(stdout);

        pthread_mutex_unlock(&monitor_lock);
    }

    return NULL;
}

void start_monitor_thread(void)
{
    pthread_t tid;

    pthread_create(&tid, NULL, monitor, NULL);
    pthread_detach(tid);
}
