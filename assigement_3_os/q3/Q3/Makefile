obj-m += task.o

all:
		make -C  /lib/modules/$(shell uname -r)/build M=$(PWD) modules
hu:
		gcc task2.c -o task 
		./task
		rm -f task
clean:
		make -C  /lib/modules/$(shell uname -r)/build M=$(PWD) clean