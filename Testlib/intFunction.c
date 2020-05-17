#include "intFunction.h"

// print fonction for an integer
void printInt(int* a)
{
	printf("%d\n", *a);
}

// Both allocation (init) and copy of a into b
void initCopyInt(const int* a, int** b)
{
	*b = (int*)malloc(sizeof(int));
	**b = *a;
}

// this function realise :
// - delete the value (set the variable to 0)
// - free the memory
// - set the pointer to Null
void deallocateInt(int** a)
{
	**a = 0;
	free(*a);
	*a = NULL;
}
