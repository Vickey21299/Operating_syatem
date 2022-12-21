#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

int forkstate[5];
pthread_t philosopher[5];

void *eat1(void *args)
{ 
    int f1 = (int)args;
    int f2;
        f1 = 0;
        f2 = 1;
  
    
    while(forkstate[f1] != 0){
        printf("Philosper%d is thinking for  fork%d\n",f1,f1);
        sleep(2);}
    forkstate[f1]=1;

    while(forkstate[f2] != 0){
        printf("Philosper%d is thinking for  fork%d\n",f1,f2);
        sleep(2);
        }
    forkstate[f2]=1;
    
    sleep(2); //eating
    printf("\n philosopher%d  with fork%d and fork %d is eating\n",f1, f1,f2);

    forkstate[f1] = 0;
    forkstate[f2] = 0;
}
void *eat2(void *args)
{
    int f1 = (int)args;
    int f2;
        f1 = 1;
        f2 = 2;

    while(forkstate[f1] != 0){
        printf("Philosper%d is thinking for  fork%d\n",f1,f1);
        sleep(2);}
    forkstate[f1]=1;

    while(forkstate[f2] != 0){
        printf("Philosper%d is thinking for  fork%d\n",f1,f2);
        sleep(2);
        }
    forkstate[f2]=1;
    
    sleep(2); //eating
    printf("\n philosopher%d  with fork%d and fork %d is eating\n",f1, f1,f2);

    forkstate[f1] = 0;
    forkstate[f2] = 0;
}
void *eat3(void *args)
{
    int f1 = (int)args;
    int f2;
        f1 = 2;
        f2 = 3;
  
    
    while(forkstate[f1] != 0){
        printf("Philosper%d is thinking for  fork%d\n",f1,f1);
        sleep(2);}
    forkstate[f1]=1;

    while(forkstate[f2] != 0){
        printf("Philosper%dis thinking for  fork%d\n",f1,f2);
        sleep(2);
        }
    forkstate[f2]=1;
    
    sleep(2); //eating
    printf("\nphilosopher%d with fork%d and fork %d is eating\n",f1, f1,f2);

    forkstate[f1] = 0;
    forkstate[f2] = 0;
}void *eat4(void *args)
{
    int f1 = (int)args;
    int f2;
        f1 = 3;
        f2 = 4;
  
    
    while(forkstate[f1] != 0){
        printf("Philosper%d is thinking for  fork%d\n",f1,f1);
        sleep(2);}
    forkstate[f1]=1;

    while(forkstate[f2] != 0){
        printf("Philosper%d is thinking for  fork%d\n",f1,f2);
        sleep(2);
        }
    forkstate[f2]=1;
    
    sleep(2); //eating
    printf("\n philosopher%d  with fork%d and fork %d is eating\n",f1, f1,f2);

    forkstate[f1] = 0;
    forkstate[f2] = 0;
}void *eat5(void *args)
{
    int f1 = (int)args;
    int f2;
        f1 = 0;
        f2 = 4;
  
    
    while(forkstate[f1] != 0){
        printf("Philosper%d is thinking for  fork%d\n",f1,f1);
        sleep(2);}
    forkstate[f1]=1;

    while(forkstate[f2] != 0){
        printf("Philosper%d is thinking for  fork%d\n",f1,f2);
        sleep(2);
        }
    forkstate[f2]=1;
    
    sleep(2); //eating
    printf("\n\n philosopher%d  with fork%d and fork %d is eating\n\n\n",f1, f1,f2);

    forkstate[f1] = 0;
    forkstate[f2] = 0;
}


int main()
{
     while(true){
    forkstate[0]=0;
    forkstate[1]=0;
    forkstate[2]=0;
    forkstate[3]=0;
    forkstate[4]=0;
   
    pthread_create(&philosopher[0], NULL, &eat1, 0);
    pthread_create(&philosopher[1], NULL, &eat2, 1);
    pthread_create(&philosopher[2], NULL, &eat3, 2);
    pthread_create(&philosopher[3], NULL, &eat4, 3);
    pthread_create(&philosopher[4], NULL, &eat5, 4);

    pthread_join(philosopher[0], NULL);
    pthread_join(philosopher[1], NULL);
    pthread_join(philosopher[2], NULL);
    pthread_join(philosopher[3], NULL);
    pthread_join(philosopher[4], NULL);
    return 0;
	 }
}