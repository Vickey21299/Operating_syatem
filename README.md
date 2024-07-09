# Interprocess Communication Project (Assigment 2 question2 )

## Description

This project involves writing two programs, P1 and P2, to demonstrate interprocess communication using three different techniques: Unix domain sockets, FIFOs, and shared memory.

### Task Details

1. **Program P1**:
   - Generates an array of 50 random strings (characters) of fixed length.
   - Sends a group of five consecutive elements of the array of strings to P2, along with the IDs of the strings (where the ID is the index of the array corresponding to the string).
   - Waits for an acknowledgment from P2 and sends the next five strings, starting with the successor of the acknowledged ID.

2. **Program P2**:
   - Accepts the received strings and sends back the highest ID received to acknowledge the strings.
   - Prints the IDs and the strings on the console.

### Techniques Used

The communication mechanism between P1 and P2 is implemented using three different techniques:
1. **Unix Domain Sockets**
2. **FIFOs (Named Pipes)**
3. **Shared Memory**

## Installation and Running the Project

### Prerequisites

- Unix-based operating system (Linux or macOS recommended)
- C/C++ compiler (gcc or g++)
- Make (optional but recommended for ease of building)

### Building the Project

To build the project, navigate to the project directory and run:

sh
make all
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

