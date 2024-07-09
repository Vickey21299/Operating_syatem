#include<stdio.h>
#include<stdlib.h>
int main(){
    char str[50][6] = {{0}};                                      
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 50; j++){
            str[j][i] = rand() % 26 +65; 			
        }      
    }
    printf("Data sent :%s\n",str[3]);	
    return 0;
}