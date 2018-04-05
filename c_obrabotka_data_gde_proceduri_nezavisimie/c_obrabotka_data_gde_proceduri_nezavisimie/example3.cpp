#include <stdio.h>
#include <omp.h>
int main(void)
{
	int n, c;
#pragma omp parallel private(n) num_threads(5)
	{
		c = omp_get_num_threads();
		printf("All threads=%d\n", c);
		n = omp_get_thread_num();
		printf("Thread=%d\n", n);
#pragma omp sections
		{
#pragma omp section
			{
				printf("1 section, thread %d\n", n);
			}
#pragma omp section
			{
				printf("2 section, thread %d\n", n);
			}
#pragma omp section
			{
				printf("3 section, thread %d\n", n);
			}
		}
		printf("Parallel region, thread %d\n", n);
	}
}