#include "header.h"
// Please read the header.h file for documentation of the code.
int main(void)
{
	int i,j,k;
	// Structure for the dynamic table
	d_table *dt;
	int frequency_of_operations;	
	float init_factor_increase[] = {1.25, 1.5, 1.75, 2, 3};
	float init_factor_decrease[] = {0.25, 0.5, 0.75};
	for(k = 0; k < 3; k++)
	{
		if (k == 0)
		{
			printf("The ratio of the operations is 1:1\n");
			frequency_of_operations = 2;
		}
		else if (k == 1)
		{
			printf("The ratio of the operations is 3:2\n");
			frequency_of_operations = 5;
		}
		else
		{
			printf("The ratio of the operations is 4:2\n");
			frequency_of_operations = 6;
		}
		for(i = 0; i < 5; i++)
		{
			for(j = 0;j < 3; j++)
			{

				printf("The factor of increase is : %f while the factor of decrease is : %f\n",init_factor_increase[i],init_factor_decrease[j]);
				clock_gettime(CLOCK_REALTIME, &start);		
				operations(dt, init_factor_increase[i], init_factor_decrease[j], frequency_of_operations);
				clock_gettime(CLOCK_REALTIME, &end);
				printf("The function took %lf milliseconds to execute \n", time_elapsed(&start, &end));
			}
		}
	}
}
