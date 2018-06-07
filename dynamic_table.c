#include "header.h"

d_table *init(d_table *dt, float init_factor_increase, float init_factor_decrease)
{
	dt = malloc(sizeof(d_table) + sizeof(int));
	dt->maximum_size = 1;
	dt->current_size = 0;
	dt->factor_increase = init_factor_increase;
	dt->factor_decrease = init_factor_decrease;
	dt->array[dt->current_size] = rand() % 10;
	dt->current_size++;
	return(dt);
}

d_table *insert(d_table *dt, int data,float init_factor_increase,float init_factor_decrease)
{
	if(dt->maximum_size == 0)
	{
		free(dt);
		dt = init(dt, init_factor_increase, init_factor_decrease);
	}
	else if(dt->current_size == dt->maximum_size)
	{
		dt->maximum_size = ceil(dt->maximum_size * dt->factor_increase);
		dt = realloc(dt,(sizeof(d_table) + sizeof(int) * (dt->maximum_size))); 
		dt->array[dt->current_size] = data;
		dt->current_size++;		
	}
	else
	{
		dt->array[dt->current_size] = data;
		dt->current_size++;		
	}
	return(dt);
}

d_table *delete(d_table *dt)
{
	if(dt->current_size>=1)
	{
		dt->array[dt->current_size - 1] = INT_MIN;
		dt->current_size--;
		if(dt->current_size <= dt->maximum_size * dt->factor_decrease)
		{
			dt->maximum_size = floor(dt->maximum_size * dt->factor_decrease);
			dt = realloc(dt,(sizeof(d_table) + sizeof(int) * (dt->maximum_size)));		
		}
	}
	//else
	//	printf("Cannot delete, the table is empty\n");
	return(dt);
}

void operations(d_table *dt, float init_factor_increase, float init_factor_decrease, int frequency_of_operation)
{
	int i = 0;
	int j = 2;
	int k = 2;
	clock_t t;	
	double max_time_insert = 0;
	double avg_time_insert = 0;
	double max_time_delete = 0;
	double avg_time_delete = 0;
	clock_gettime(CLOCK_REALTIME, &start);	
	dt = init(dt, init_factor_increase,init_factor_decrease);
    clock_gettime(CLOCK_REALTIME, &end);
    max_time_insert = time_elapsed(&start, &end);
    avg_time_insert = time_elapsed(&start, &end);
	srand((unsigned) time(&t));
	for( i = 0; i < 999999; ++i )
	{
		int seed = rand() % frequency_of_operation;
		if(seed == 0)
		{
			clock_gettime(CLOCK_REALTIME, &start);	
			//printf("Inserting\n");
			dt = insert(dt, rand()%10,init_factor_increase,init_factor_decrease);
			clock_gettime(CLOCK_REALTIME, &end);	
			if(time_elapsed(&start, &end) > max_time_insert)
				max_time_insert = time_elapsed(&start, &end);
			avg_time_insert = (avg_time_insert + time_elapsed(&start, &end));
			j++;
		}
		else
		{
			clock_gettime(CLOCK_REALTIME, &start);	
			//printf("Deleting\n");
			dt = delete(dt);
			clock_gettime(CLOCK_REALTIME, &end);
			if(time_elapsed(&start, &end) > max_time_delete)
				max_time_delete = time_elapsed(&start, &end);
			avg_time_delete = (avg_time_delete + time_elapsed(&start, &end));
			k++;
		}
	}
	avg_time_insert /= j;
	avg_time_delete /= k;
	printf("The maximum time for insert was:%lf\n", max_time_insert);
	printf("The average time for insert was:%lf\n", avg_time_insert);
	printf("The maximum time for deletion was:%lf\n", max_time_delete);
	printf("The average time for deletion was:%lf\n", avg_time_delete);	
	//print();
	free(dt);
}

double time_elapsed(struct timespec *start, struct timespec *end)
{
	double t = 0.0;
	t = (end->tv_sec - start->tv_sec) * 1000;
	t += (end->tv_nsec - start->tv_nsec) * 0.000001;
	return t;
}

void print(d_table *dt)
{
	printf("Final size is %ld\n",dt->current_size);	
	int i;
	for(i = 0; i < dt->current_size; i++)
	{
		if (dt->array[i] == INT_MIN)
			break;
		printf("%d\n", dt->array[i]);
	}
}
