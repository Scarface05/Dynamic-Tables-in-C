#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

struct timespec start;
struct timespec end;

typedef struct dynamic_table
{
	size_t current_size; // Current size of the dynamic table.
	size_t maximum_size; // Maximum size of the dynamic table.
	float factor_decrease; // Factor by which the table dynamic table size is to be decreased.
	float factor_increase; // Factor by which the table dynamic table size is to be increased.
	int array[]; // Flexible Array Member containing the required data.
}d_table;

//Function prototype for the function that calculates CPU time for execution on an operation/function.
double time_elapsed(struct timespec *start, struct timespec *end);

//Function prototype for the function that initialises the Dynamic Table structure.
d_table *init(d_table *dt, float init_factor_increase, float init_factor_decrease);

//Function prototype to print the contents of the dynamic table
void print(d_table *dt);

//Function prototype to insert values into the dynamic table(works like push operation on a stack). It takes 3 arguments, the data to be insert, factors with which the size of the dynamic table are supposed to be increased and decreased.
d_table *insert(d_table *dt, int data, float init_factor_increase, float init_factor_decrease);

//Function prototype to delete values from the dynamic table. It deletes the last element to be inserted(works like pop operation on a stack)
d_table *delete(d_table *dt);

//Function prototype to make the calls of the operations insert and delete. 
void operations(d_table *dt, float init_factor_increase, float init_factor_decrease, int frequency_of_operations);

