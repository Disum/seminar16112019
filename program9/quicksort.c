#include "quicksort.h"
int find_place(double *a, int n, double x, int (*p)(double, double));
void swap(double *a, double *b);

/* Предполагается, что n>0, и по указателю a расположен массив из n элементов.
 * Быстрая сортировка.
 * */
void quicksort(double *a, int n, int (*p)(double, double))
{
	int place;

	if( n<2 )
		return;

	while( n>1 )
	{
		place = find_place(a, n, a[(int)(n/2)], p);

		if( place==0 )// a[(int)(n/2)] меньше или равен всех элементов
		{
			swap(a, a + (int)(n/2));
			a += 1;
			n -= 1;
		}

		if( place<=(n - place) )
		{
			quicksort(a, place, p);
			a += place;
			n -= place;
		} else
		{
			quicksort(a + place, n - place, p);
			n = place;
		}
	}
}

/* Предполагается, что n>0 и по указателю a расположен массив из n элементов.
 * Ф-ия возвращает i: a[i]<=x<=a[i + 1]. Если x меньше или равен всех элементов, то возвращается нуль.
 * Если x больше всех, то возвращается n.
 * */
int find_place(double *a, int n, double x, int (*p)(double, double))
{
	int i = 0, j = n - 1;

	while( i<=j )
	{
		if( p(x, a[i])>0 )// Ищем a[i]>=x
		{
			i++;
			continue;
		}

		if( p(a[j], x)>-1 )// Ищем a[j]<x
		{
			j--;
			continue;
		}

		swap(a + i, a + j);

		i++;
		j--;
	}

	return i;
}

void swap(double *a, double *b)
{
	double buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}
