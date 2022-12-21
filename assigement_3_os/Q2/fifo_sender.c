#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<errno.h>
#include <sys/ipc.h>
int main()
{   // 

    char str[5];
    int res;
    printf("Sending Data using Named FIFO(pipe)");
    printf("\n");
    char alphabate[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int m=1;m++;m<=50)
    {   
        
        res = open("myfifo", O_WRONLY);
        printf("  Data sent at index [%d] is   \t\t:",m);
        for (int i = 0; i < 5; i++) {   
            str[i] = alphabate[rand() % 52];
            printf("%c",str[i]);
        }
        printf("\n");
        usleep(100);
        write(res, str, sizeof(str));
        close(res);
        //checking the indexing after  5 data transfer notify by fifo_reciver 
        res = open("myfifo", O_RDONLY);
        int index[1];
        read(res, index, sizeof(index));
        if (index[0]<=50&&index[0]%5==0){
            printf("  Read id: %d\n",index[0]); // id == array index after 5 data reciver by fifo_reciver 
        }
        close(res);
    }
    printf("Ending of fifo_Sending \n");
    return 0;
}