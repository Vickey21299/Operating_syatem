#include <sys/syscall.h>
#include <linux/kernel.h>
SYSCALL_DEFINE3(kernel_2d_memcpy , float** , matrix1, float** , matrix2,int ,len){
         float buffer[5][5];
     if(__copy_from_user(buffer,matrix1,sizeof(float)*(len)))
         return -EFAULT;
     if(__copy_from_user(matrix2,buffer,sizeof(float)*(len)))
        return -EFAULT;
  return 0;
}