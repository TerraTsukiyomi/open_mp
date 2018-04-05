#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define w 100

using namespace std;

int main(int argc, char *argv[])
{
	int i, j, x1, y1, x2, y2, k;
	double m1[w][w], m2[w][w], m3[w][w];

	x1 = atoi(argv[1]);
	y1 = atoi(argv[2]);
	x2 = atoi(argv[3]);
	y2 = atoi(argv[4]);

	if (y1 != x2)
	{
		printf("!!!Error!!!\n");
		exit(-1);
	}
	for (i = 0; i < x1; i++)
	{

		for (j = 0; j < y1; j++)
		{
			printf("matr1 A[%d][%d]=", i + 1, j + 1);
			scanf("%d", &m1[i][j]);
		}
	}

	for (i = 0; i < x2; i++)
	{
		for (j = 0; j <y2; j++)
		{
			printf("matr2 A[%d][%d]=", i + 1, j + 1);
			scanf("%d", &m2[i][j]);
		}

	}

	for (i = 0; i < x1; i++)
		for (k = 0; k < y2; k++)
			for (j = 0; j < x2; j++)
				m3[i][k] += (m1[i][j])*(m2[j][k]);

	for (i = 0; i < x1; i++)
	{
		for (k = 0; k < y2; k++)
		{
			printf("%d ", m3[i][k]);

		}
		printf("\n");
	}

	system("pouse");
	return 0;
}
