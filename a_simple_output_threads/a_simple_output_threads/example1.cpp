#include <stdio.h>
#include <omp.h>
int main(void)
{
	int count, num;
	count = omp_get_num_threads();
	printf("\nAll threads: %d\n\n", count);
#pragma omp parallel num_threads(5)
	{
		num = omp_get_thread_num();
		printf("Thread number: %d\n", num);
		count = omp_get_num_threads();
		printf("All threads: %d\n", count);
	}
	count = omp_get_num_threads();
	printf("\nAll threads: %d\n\n", count);

}