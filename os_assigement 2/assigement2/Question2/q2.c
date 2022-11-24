#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define Kernel_2D_memcpy 451

void check_equal(float lhs[5][5], float rhs[5][5])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        for(int j =0;j<5;j++){
            printf(" %.2f ",rhs[i][j]);

        
        if (lhs[i][j] != rhs[i][j])
        {
            printf("Error : LHS[%d] != RHS[%d]\n", i, i);
            return;
        }
        }
        printf("\n");
    }
    printf("Message : Success LHS = RHS \n");
}

int main()

{
    float arry1[5][5] = {{1.1, 2.1, 3.1, 4.1,3.4},
     {5.1, 6.1, 7.1, 7.1,4.3}, {2.2, 3.2, 4.2, 5.2,6.5},
     {2.2, 3.2, 4.2, 5.2,7.6},{2.2, 3.2, 4.2, 5.2,8.9}};
    float arry2[5][5];
    long sys_call_status;

    sys_call_status = syscall(Kernel_2D_memcpy, arry1, arry2, 25);

    if (sys_call_status != EFAULT)
    {
        printf("Message : System Call 451 successfuly invoked \n");
        check_equal(arry1,arry2);
    }

    return 0;
}
