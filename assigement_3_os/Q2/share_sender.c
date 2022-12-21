#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
int main()
{
    void *shared_memory;
    char buff[1024];
    int shmid;
    shmid = shmget((key_t)1122, 1024, 0666 | IPC_CREAT);
    shared_memory = shmat(shmid, NULL, 0);
    printf("Data is adding to shared_memory....\n");
    char str[50][6] = {{0}};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            str[j][i] = rand() % 26 + 65;
        }
    }
    int i = 0;
    while (i < 50)
    {
        strcpy(shared_memory, str[i]);
        sleep(1);
        printf("#%d\tData send : %s \n", i,(char *)shared_memory);
        i++;
        if((i+1)%5==0){
            printf("Recived id : %d\n",i+1);
        }
    }
}
