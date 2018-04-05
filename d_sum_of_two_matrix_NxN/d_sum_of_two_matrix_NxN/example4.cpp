#include <stdio.h>
#include <omp.h>
#include <math.h>
#define N 100000
#define LIM 5000
int main(void)
{
	double f, g, sum, t1, t2;
	int j, i, k, l, allp, numt, allt;
	sum = g = f = t1 = t2 = 0;
	allp = omp_get_num_procs();
	allt = omp_get_num_threads();
	t1 = omp_get_wtime();
#pragma omp parallel private(i,j,k,l) num_threads(128) if(N>LIM)
	{
#pragma omp sections reduction(+:f,g)
		{
#pragma omp section
			{
				for (i = 0; i<N; i++)
					for (j = 0; j<N; j++)
						f += (double)j*(double)i / (double)N;
				numt = omp_get_thread_num();
				printf("All Processors=%d Number Thread=%d All Thread = %d Result[%d %d] = %.1f\n",allp,numt,allt,i,j,f);
			}
#pragma omp section
			{
				for (k = 0; k<N; k++)
					for (l = 0; l<N; l++)
						g += (double)l*(double)k / (double)N;
				numt = omp_get_thread_num();
				printf("All Processors=%d Number Thread=%d All Thread = %d Result[%d %d] = %.1f\n",allp,numt,allt,k,l,g);
			}
		}
	}

	t2 = omp_get_wtime();
	printf("\nRuntime=%f\n\n", t2 - t1);
	sum = g + f;
	printf("Sum=%.1f\n", floor(sum + 0.5));
	return 0;
}