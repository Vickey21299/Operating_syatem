#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
#include <math.h> 

int main(){
    struct timespec start1, stop1;
     clock_gettime( CLOCK_REALTIME, &start1 );
    chdir("/home/vickey/Desktop/program_linux1");

    pid_t p1 = fork();
    if(p1 <0){
        printf("Error in fork\n");
    }
    else if(p1 == 0){
        printf("child 1\n");
         struct sched_param parameters;
        
             parameters.sched_priority = 0;
        int works = sched_setscheduler(getpid (),SCHED_OTHER,&parameters);
        char * test[]={"/home/vickey/Desktop/linux1/script.sh",NULL};
         execvp(test[0],test);   
    }
    else{
        struct timespec start2, stop2;
            clock_gettime( CLOCK_REALTIME, &start2 );
            chdir("/home/vickey/Desktop/program_linux2");

        
        pid_t p2 = fork();

        if(p2 <0){

            printf("Error in fork\n");
        }
        else if(p2 == 0){
            printf("Child 2\n");
             struct sched_param parameters;
        
             parameters.sched_priority = 50;
        int works = sched_setscheduler(getpid(), SCHED_FIFO, &parameters);
        char * test[]={"/home/vickey/Desktop/linux1/script.sh",NULL}; 
            execvp(test[0],test);     
            
         }
        else{
             struct timespec start3, stop3;
            clock_gettime( CLOCK_REALTIME, &start3 );
           chdir("/home/vickey/Desktop/program_linux3");
            pid_t p3 = fork();

            if(p3 <0){
                printf("Error in fork\n");
            }
            else if(p3 == 0){
            printf("Child3\n");
            struct sched_param parameters;
            parameters.sched_priority = 50;
           int works = sched_setscheduler(getpid(), SCHED_RR, &parameters);
           char * test[]={"/home/vickey/Desktop/linux1/script.sh",NULL};
           execvp(test[0],test); 
            }
            else{
                wait(&p3);
                clock_gettime( CLOCK_REALTIME, &stop3 );
                wait(&p2);
                clock_gettime( CLOCK_REALTIME, &stop2 );
                 wait(&p1);
                clock_gettime( CLOCK_REALTIME, &stop1 );
             printf(" Time by process 1--> %lf seconds \n",((double) (stop1.tv_sec - start1.tv_sec) + (double) ((stop1.tv_nsec - start1.tv_nsec)/(double) 1000000000L)));
             printf(" Time by process 2 --> %lf seconds\n",((double) (stop2.tv_sec - start2.tv_sec) + (double) ((stop2.tv_nsec - start2.tv_nsec)/(double) 1000000000L)));
             printf(" Time by process 3 --> %lf seconds\n",((double) (stop3.tv_sec - start3.tv_sec) + (double) ((stop3.tv_nsec - start3.tv_nsec)/(double) 1000000000L)));
             FILE *filepointer;
        filepointer = fopen("data.txt","w+");
        //fputs("%f",((double) (stop.tv_sec - start.tv_sec) + (double) ((stop.tv_nsec - start.tv_nsec)/(double) 1000000000L)),filepointer);
        fprintf(filepointer,"%d ",34);
        
        fprintf(filepointer,"%f ",((double) (stop1.tv_sec - start1.tv_sec) + (double) ((stop1.tv_nsec - start1.tv_nsec)/(double) 1000000000L)));
        fprintf(filepointer,"%f ",((double) (stop2.tv_sec - start2.tv_sec) + (double) ((stop2.tv_nsec - start2.tv_nsec)/(double) 1000000000L)));
        fprintf(filepointer,"%f ",((double) (stop3.tv_sec - start3.tv_sec) + (double) ((stop3.tv_nsec - start3.tv_nsec)/(double) 1000000000L)));
        fclose(filepointer);
                
            }
    
        }
    }

}
