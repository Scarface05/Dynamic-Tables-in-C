all:dynamic_table.c
		gcc -g -o dynamic_table dynamic_table.c header.h client.c -lm

run:dynamic_table
	./dynamic_table
