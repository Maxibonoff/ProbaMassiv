// ProbaMassiv.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
const int m=20;

int _tmain(int argc, _TCHAR* argv[])
{
	int n; // Число элементов массива
	int *A;
	printf("n="); scanf("%d", &n);
	A=new int[n];
	for(int i=0; i<n; i++)
	{
		// rand() возвращает целое псевдослучайное число в интервале 0..32767
		A[i]=rand() % 101 - 50; // -50..50
		printf("%d  ", A[i]);
	}
	// Сортировкка методом прямого выбора
	/*for(int i=0; i<n-1; i++)
	{
		// i индекс элемента с которого начинается массив в котором ищем минимум
		int min=A[i], imin=i;
		for(int j=i+1; j<n; j++)
			if (A[j]<min) // i-ый элемент сравниваем со всеми последующими
			{
				min=A[j]; imin=j;
			}
		// Меняем элементы местами
		if (i!=imin) {
			A[imin]=A[i];
			A[i]=min;
		}
	}*/
	// Сортировка методом пузырька
	bool flag; 
	for(int i=0; i<n-1; i++) // 
	{
		flag=true;
		for(int j=0; j<n-i-1; j++)
			if (A[j]>A[j+1]) // Меняем элементы
			{
				int buf=A[j];
				A[j]=A[j+1];
				A[j+1]=buf;
				flag=false;
			}
		if (flag) break; // Массив отсортирован
	}


	printf("\n\n");
	for(int i=0; i<n; i++)
	{
		
		printf("%d  ", A[i]);
	}


	delete [] A; // Освобождение памяти


	return 0;
}

