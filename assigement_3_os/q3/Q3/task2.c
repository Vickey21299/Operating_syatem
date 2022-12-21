#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
 pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed");
    }
    else if (pid == 0)
    {
        char * test[]={"/home/vickey/home/assigement3/q3/Q3/script.sh",NULL};
         execvp(test[0],test);  
    }
    else
    {
        wait(NULL);
        printf("Child Complete");
        printf("\n");
    }
    
}