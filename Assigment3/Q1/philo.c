#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_PHILOSOPHERS 5
#define NUM 5

void dine(int n);
pthread_t philosopher[NUM];
pthread_mutex_t chopstick[NUM];

int main()
{
    int i;
    void *mesg;
    for (i = 1; i <= NUM; i++)
    {
     pthread_mutex_init(&chopstick[i], NULL);
    }
    for (i = 1; i <= 5; i++)
    {
        pthread_create(&philosopher[i], NULL, (void *)dine, (int *)i);
    }
    for (i = 1; i <= 5; i++)
    {
         pthread_join(philosopher[i], &mesg);
    }
    for (i = 1; i <= NUM; i++)
    {
        pthread_mutex_destroy(&chopstick[i]);
    }
    return 0;
}
    void dine(int n)
    {
        while(1){
        printf("\nPhilosopher % d is thinking ", n);
        pthread_mutex_lock(&chopstick[n]);
        pthread_mutex_lock(&chopstick[(n + 1) % NUM]);
        printf("\nPhilosopher % d is eating ", n);
        sleep(3);
        pthread_mutex_unlock(&chopstick[n]);
        pthread_mutex_unlock(&chopstick[(n + 1) % NUM]);
        printf("\nPhilosopher % d Finished eating ", n); 
        }
    }