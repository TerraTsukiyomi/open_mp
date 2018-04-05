#include<stdio.h>
#include<omp.h>
#include<math.h>
#define N 100000
#define LIM 5000
int main(void)
{
	double f, t1, t2;
	int i, j, allp, numt, allt;
	f = t1 = t2 = 0;
	allp = omp_get_num_procs();
	allt = omp_get_num_threads();
	t1 = omp_get_wtime();
#pragma omp parallel private(i,j) reduction(+:f) num_threads(2) if(N>LIM)
	{
#pragma omp for
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				f += (double)j*(double)i / (double)N;
		numt = omp_get_thread_num();
		printf("All Processors=%d Number Thread=%d All Threads=%dResult[%d %d] = %.1f\n",allp,numt,allt,i,j,f);
	}
	t2 = omp_get_wtime();
	printf("\nRuntime=%f\n\n", t2 - t1);
	printf("F=%.1f\n", floor(f + 0.5));
	return 0;
}