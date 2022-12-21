#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
    int r;
    r = mkfifo("myfifo",0777);
    printf("created");
return 0;
}