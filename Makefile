all: 4_main.o 4_func.o 4_print_arr.o
	gcc 4_main.o 4_func.o 4_print_arr.o -o 4 && del -f *.o

4_main.o: 4_main.c 4_head.h
	gcc -c 4_main.c

4_func.o: 4_func.c 4_head.h
	gcc -c 4_func.c

4_print_arr.o: 4_print_arr.c 4_head.h
	gcc -c 4_print_arr.c