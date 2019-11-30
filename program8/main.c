#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "merge_sort.h"
int f_up(double a, double b);
int f_down(double a, double b);

int f_up(double a, double b)
{
	if( a>b )
		return 1;

	if( a<b )
		return -1;

	return 0;
}

int f_down(double a, double b)
{
	if( a>b )
		return -1;

	if( a<b )
		return 1;

	return 0;
}

int main(int argc, const char *argv[])
{
	int n, result_read;
	double *a, *b;
	clock_t time_begin;

	if( ((argc!=2) && (argc!=3)) || (sscanf(argv[1], "%d", &n)!=1) || (n<=0) )
	{
		fprintf(stderr, "Usage: %s size_of_array [file_with_array]\t\t([size_of_array]>0)\t(array is random if no file_with_array)\n", argv[0]);
		return 1;
	}

	if( !(a = (double *)malloc(n*sizeof(double))) )
	{
		fprintf(stderr, "Can not allocate memory!\n");
		return 2;
	}
	if( !(b = (double *)malloc(n*sizeof(double))) )
	{
		fprintf(stderr, "Can not allocate memory!\n");
		free(a);
		return 2;
	}
	// Память выделена

	if( argc==3 )
	{
		result_read = read_array(argv[2], a, n);
		if( result_read<0 )
		{
			switch( result_read )
			{
			case -2:
				fprintf(stderr, "Can not read element from %s\n", argv[2]);
				break;
			case -1:
				fprintf(stderr, "Can not open file %s\n", argv[2]);
				break;
			default:
				fprintf(stderr, "Unknown error %d in file %s\n", result_read, argv[2]);
			}

			free(a);
			free(b);
			return 3;
		}
	} else
	{
		rand_array(a, n);
	}
	// Массив считан или сгенерирован случайный

	printf("Array a[]:\n");
	print_array(a, n);

	time_begin = clock();
	merge_sort(a, b, n, &f_down);
	printf("Time: %.2f seconds\nArray a[]:\n", (float)( clock() - time_begin )/CLOCKS_PER_SEC);
	print_array(a, n);

	free(a);
	free(b);
	return 0;
}
