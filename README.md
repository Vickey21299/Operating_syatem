# how-to-update-your-kernel-by-checking-2D-matrix
Question 2:
Kernel memory copy (kernel 2d memcpy())

This code copy the two 2 matrix by using __copy_from_user  and copy to_ user() to read data bytes from user space and write back to user space.
 In other words, this is a version of memcpy() that relies on the kernel to do the necessary copy operations,
In my artix kernel_linux folder:
We have to change in three places 
Firsty, open linux kernel folder and update the sys.c folder by using the code
As show in Question 2/kernel_2d_memcpy.c 
Secondly, change in syscall_64.tbl file at  your kernel_linux folder at 
arch/x86/entry/syscalls
And add 451 line like this :




Thirdly, agin compile your kernel again and by  make -j$(nproc)   afterthat run 
Make modules_install
sudo cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-***
Now , reboot your kernel and
Check your program is running or not by checking run code question2.c
In which i make a hard code of 2D matrix and calling syscall function and copy that matrix to another matrix and checking that matrix is equal or not by passing the matri1, matrix2 in equal function.
And result tell that your process is correct as shown below:

 I uploaded all related file in this folder
  link: https://docs.google.com/document/d/14sN_CLcuTFNiK5Np2BAZ5P-BpmFW9ZOBOOrWtRn20Jw/edit?usp=sharing

