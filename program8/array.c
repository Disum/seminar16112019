#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* Предполагается, что n>0 и по указателю array выделена память для n элементов.
 * Ф-ия возвращает:
 * -2, если не удалось прочитать элемент;
 * -1, если не удалось открыть файл;
 * 0, в случае успешного завершения.
 * */
int read_array(const char *name, double *array, int n)
{
	FILE *input;
	int i;

	if( !(input = fopen(name, "r")) )
		return -1;

	for( i = 0; i<n; i++ )
	{
		if( fscanf(input, "%lf", array + i)!=1 )
		{
			fclose(input);
			return -2;
		}
	}

	fclose(input);
	return 0;
}

/* Предполагается, что n>0 и по указателю array выделена память для n элементов. */
void rand_array(double *array, int n)
{
	int i;

	for( i = 0; i<n; i++ )
		array[i] = rand();
}

/* Предполагается, что n>0 и по указателю array выделена память для n элементов.
 * */
void print_array(double *array, int n)
{
	int i;

	if( n>20 )
		n = 20;

	for( i = 0; i<n; i++ )
		printf("Array[%d]=%lf\n", i, array[i]);
}
