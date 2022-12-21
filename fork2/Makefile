go:
	gcc simple_shell.c -lreadline -pthread -lreadline -o shell
	make compile
	./shell
	rm -f shell
	rm -f ls
	rm -f mkdir
	rm -f cat
	rm -f rm
	rm -f date

compile:
	gcc ls.c -o ls
	gcc mkdir.c -o mkdir
	gcc cat.c -o cat
	gcc rm.c -o rm
	gcc date.c -o date