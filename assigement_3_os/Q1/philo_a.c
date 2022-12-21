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
         int ph=*(int *)n;
         printf("Philosopher %d is thinking\n",ph);
         sem_wait(&chopstick[ph]);
         printf("Philosopher %d picks the left chopstick\n",ph);
         sem_wait(&chopstick[(ph+1)%5]);
         printf("Philosopher %d picks the right chopstick\n",ph);
         printf("Philosopher %d begins to eat\n",ph);
         sem_post(&chopstick[(ph+1)%5]);
         sem_post(&chopstick[ph]);
        printf("Philosopher %d has finished eating\n",ph);
 
 			
 }