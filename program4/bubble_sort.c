#include "bubble_sort.h"
void swap(double *a, double *b);

void swap(double *a, double *b)
{
	double buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

/* Предполагается, что n>0, и по указателю a расположен массив из n элементов.
 * Пузырьковая сортировка.
 * */
void bubble_sort(double *a, int n, int (*p)(double, double))
{
	int i, counter, check;

	for( counter = 0; counter<(n - 1); counter++ )
	{
		check = 1;
		for( i = 0; i<(n - 1 - counter); i++ )
		{
			if( p(a[i],a[i + 1])>0 )
			{
				check = 0;
				swap(a + i, a + i + 1);
			}
		}
		if( check )
			return;
	}
}
