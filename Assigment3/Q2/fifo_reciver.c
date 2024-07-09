#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int res;
    char buff[5];
    int m = 1;
    printf("Recieveing Data by using Named FIFO(pipe)\n");
    while (m<50)
    {
        m++;
        res = open("myfifo",O_RDONLY);
        read(res, buff, 5);
        printf("  Data recieved at index [%d] from FIFO  :%s\n",m, buff);
        usleep(100);
        close(res);
        int id[1];
        id[0] = m;
        res = open("myfifo",O_WRONLY);
        write(res, id, sizeof(id));// id == array index after 5 data sending to fifo_sender to get notify 
        if (m%5==0){
            printf("  Sent id: %d\n",id[0]);
        }
        close(res);
    }
    return 0;
}