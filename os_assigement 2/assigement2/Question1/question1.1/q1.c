#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
#include <math.h> 
long long int t = 4294967296;
 int prioty;

void countA(){
    for(long long int i =1;i<t;i++){

    }
}
void countB(){
    for(long long int i =1;i<t;i++){

    }

}
void countC(){
for(long long int i =1;i<t;i++){

    }
}
void*ta(void*k){
        struct timespec start, stop;
        clock_gettime( CLOCK_REALTIME, &start );
        int  prioty1 = 0;  
        struct sched_param parameters;
        parameters.sched_priority = prioty1;
        int works = pthread_setschedparam(pthread_self(), SCHED_OTHER, &parameters);
       // printf("/n%d\n",works);
        
        countA();
        clock_gettime( CLOCK_REALTIME, &stop );
        // ((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L));
        printf(" other -->%lf\n",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)));
        FILE *filepointer;
        filepointer = fopen("threadtime.txt","a+");
        //fputs("%f",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)),filepointer);
        fprintf(filepointer,"%d ",34);
        fprintf(filepointer,"%f ",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)));
        fclose(filepointer);

}

void* tb(void*k){
     prioty =10;
 struct sched_param parameters;
        parameters.sched_priority = prioty;
        int works = pthread_setschedparam(pthread_self(), SCHED_RR, &parameters);
        //printf("\n%d\n",works);
        struct timespec start, stop;
        clock_gettime( CLOCK_REALTIME, &start );
        countA();
        clock_gettime( CLOCK_REALTIME, &stop );
        // ((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L));
        printf("rr --> %lf\n",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)));
         FILE *filepointer;
        filepointer = fopen("threadtime.txt","a+");
       fprintf(filepointer,"%d ",36);
        //fputs("%f",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)),filepointer);
        fprintf(filepointer,"%f ",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)));
        fclose(filepointer);
        prioty +=1;
}
void* tc(void*k){  
        struct sched_param parameters;
        parameters.sched_priority = prioty;
        int works = pthread_setschedparam(pthread_self(), SCHED_FIFO, &parameters);
        //printf("\n%d \n",works);
        struct timespec start, stop;
        clock_gettime( CLOCK_REALTIME, &start );
        countA();
        clock_gettime( CLOCK_REALTIME, &stop );
        // ((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L));
        printf(" fifo --> %lf \n",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)));
        FILE *filepointer;
        filepointer = fopen("threadtime.txt","a+");
        //fputs("%f",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)),filepointer);
        fprintf(filepointer,"%d ",37);
        fprintf(filepointer,"%f ",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)));
        fclose(filepointer);
        prioty+1;

}
int main(){
    int m =5;
    FILE *fp;
    fp = fopen("threadtime.txt","w");
    fclose(fp);
    while(m!=9){
    pthread_t a;
    pthread_create(&a,NULL,ta,NULL);
    
    pthread_t b;
    pthread_create(&b,NULL,tb,NULL);
    
    pthread_t c;
    pthread_create(&c,NULL,tc,NULL);
    pthread_join(a,NULL);
    pthread_join(b,NULL);
    pthread_join(c,NULL);
    m++;
    
    }


return 0;
}