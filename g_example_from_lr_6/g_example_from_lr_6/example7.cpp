﻿#include<stdio.h> 
#include<time.h> 
#include<sys/time.h> 
#define M 100 
#define E 0.00001 
#define T 0.01 
double A[M][M], F[M], Xk[M], Zk[M];
double Rk[M], Sz[M], alf, bet, mf;
double Spr, Spr1, Spz;
int main()
{
	int i, j, v;
	struct timeval tv1, tv2;
	long int dt1;
	/* Генерація даних. Задається матриця з елементами, що дорівнюють 1,
	* а по діагоналі дорівнюють 2. Матриця повинна бути добре обумовленою та симетричною. При правій частині, рівній M+1, всі коріння будуть рівними 1 */
	for (mf = 0, i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (i == j)
				A[i][j] = 2.0;
			else
				A[i][j] = 1.0;
		}
		F[i] = M + 1;
		/* Обчислюється сума квадратів елементів вектора F, тобто підкорений вираз.*/
		mf += F[i] * F[i];
	}
	/* Задається начальне приближення значень коренів. В Хk зберігаються значення коренів к-ї ітерації. */
	for (i = 0; i < M; i++)
		Xk[i] = 0.2;
	/* Задається начальне приближення значень r0 та z0. */
	for (i = 0; i < M; i++)
	{
		for (Sz[i] = 0, j = 0; j < M; j++)
			Sz[i] += A[i][j] * Xk[j];
		Rk[i] = F[i] - Sz[i];
		Zk[i] = Rk[i];
	}
	/* Початковий час проведення обчислень. */
	gettimeofday(&tv1, NULL);
	do
	{
		/* Обчислюються чисельник і знаменник для коефіцієнта
		* αk = (rk-1,rk-1)/(Azk-1,zk-1) */
		Spz = 0;
		Spr = 0;
		for (i = 0; i < M; i++)
		{
			for (Sz[i] = 0, j = 0; j < M; j++)
				Sz[i] += A[i][j] * Zk[j];
			Spz += Sz[i] * Zk[i];
			Spr += Rk[i] * Rk[i];
		}
		alf = Spr / Spz; /* αk */
						 /* Обчислюється вектор розв'язку: xk = xk-1+ αkzk-1,
						 вектор нев'язки: rk = rk-1 - αkAzk-1, та чисельник для коефіцієнта βk = (rk,rk) */
		Spr1 = 0;
		for (i = 0; i < M; i++)
		{
			Xk[i] += alf * Zk[i];
			Rk[i] -= alf * Sz[i];
			Spr1 += Rk[i] * Rk[i];
		}
		/* Обчислюється коефіцієнт βk */
		bet = Spr1 / Spr;
		/* Обчислюється вектор спуску: zk = rk+ βkzk-1 */
		for (i = 0; i < M; i++)
			Zk[i] = Rk[i] + bet * Zk[i];
	}
	/* Перевіряється умова виходу з ітераційного циклу (2)*/
	while (Spr1 / mf > E*E);
	/* Час завершення виконання завдання виводиться на екран */
	gettimeofday(&tv2, (struct timezone*)0);
	dt1 = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec;
	printf("Time = %d\n", dt1);
	/* Для контролю результатів виводяться 8 перших коренів */
	printf(" %f %f %f %f %f %f %f %f\n", Xk[0], Xk[1], Xk[2], Xk[3], Xk[4], Xk[5], Xk[6], Xk[7]);
	return(0);
}
