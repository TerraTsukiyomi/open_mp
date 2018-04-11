#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <conio.h>
#include<omp.h>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	const long MATRIX_RANGE = 5000;
	long matrix[3][MATRIX_RANGE][MATRIX_RANGE];
	srand(static_cast<unsigned> (time(NULL)));
	long k = 0;

	double f, t1, t2;
	int i, j, allp, numt, allt;
	f = t1 = t2 = 0;
	allp = omp_get_num_procs();
	allt = omp_get_num_threads();
	t1 = omp_get_wtime();

#pragma omp parallel reduction(+:f) num_threads(2)
	{

#pragma omp sections
		{
#pragma omp section
			{
				while (k <= 1) {
					for (long i = 0; i < MATRIX_RANGE; i++)
						for (long j = 0; j < MATRIX_RANGE; j++)
							matrix[k][i][j] = rand() % 80000 + 10000;
					k++;
				}
			}

#pragma omp section
			{
#pragma omp for
				for (long i = 0; i < MATRIX_RANGE; i++)
					for (long j = 0; j < MATRIX_RANGE; j++)
						matrix[2][i][j] += matrix[0][i][j] * matrix[1][i][j];
				//printf("All Processors=%d Number Thread=%d All Threads=%dResult[%d %d] = %.1f\n", allp, numt, allt, i, j, f);
			}
		}
	}
	//k = 0;
	//while (k <= 2) {
	//	for (int i = 0; i < MATRIX_RANGE; i++)
	//		for (int j = 0; j <= MATRIX_RANGE; j++)
	//			if (j == MATRIX_RANGE) cout << endl; else cout << matrix[k][i][j] << " ";
	//	cout << endl;
	//	k++;
	//}

	t2 = omp_get_wtime();
	printf("\nRuntime=%f\n\n", t2 - t1);
	printf("F=%.1f\n", floor(f + 0.5));
	cout << "Нажмите любую клавишу...";
	_getch();
	return 0;
}