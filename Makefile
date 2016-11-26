main: main.c test modules/*
	gcc main.c -o main -l ncurses
test: test.c
	gcc test.c -o test