#include "min_sort.h"
void swap(double *a, double *b);

/* Предполагается, что n>0, и по указателю a расположен массив из n элементов.
 * Сортировка нахождением минимума.
 * */
void min_sort(double *a, int n, int (*p)(double, double))
{
	int i, j, i_min;

	for( j = 0; j<(n - 1); j++)
	{
		i_min = j;
		for( i = (j + 1); i<n; i++ )
		{
			if( p(a[i_min], a[i])>0 )
				i_min = i;
		}

		swap(a + i_min, a + j);
	}
	
}

void swap(double *a, double *b)
{
	double buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}
