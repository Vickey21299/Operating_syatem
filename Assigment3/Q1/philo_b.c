#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t chopstick[5];
sem_t bowl1;
sem_t bowl2;
void * philos(void *);
int main()
 {
         int i,n[5];
         pthread_t philosopher[5];
		 sem_init (&bowl1,0,1);
		 sem_init (&bowl2,0,1);
         for(i=0;i<5;i++)
         sem_init(&chopstick[i],0,1);
         for(i=0;i<5;i++){
                 n[i]=i;
                 pthread_create(&philosopher[i],NULL,philos,(void *)&n[i]);
                 }
         for(i=0;i<5;i++)
                 pthread_join(philosopher[i],NULL);
 }
void * philos(void * n)
 { 
         int philo=*(int *)n;
         printf("Philosopher %d is thinking\n",philo);
         sem_wait(&chopstick[philo]);
         printf("Philosopher %d picks the left chopstick\n",philo);
         sem_wait(&chopstick[(philo+1)%5]);
         printf("Philosopher %d picks the right chopstick\n",philo);
		 sem_wait(&bowl1) || sem_wait(&bowl2);
		 printf("Philosopher %d has bowl to eat\n",philo);
         printf("Philosopher %d begins to eat\n",philo);
         printf("Philosopher %d has finished eating\n",philo);
         sem_post(&chopstick[(philo+1)%5]);
         sem_post(&chopstick[philo]);
        sem_post(&bowl1) || sem_post(&bowl2);
 }
