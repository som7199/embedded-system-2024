#include <stdio.h>

void main()
{
	const int i = 10;
	printf("i : %d\n", i);

	// error: assignment of read-only variable 뜸!
	/*
	i = 20;
	printf("i : %d\n", i);
	*/

	/*
	int* pi = &i;
	printf("*pi : %d\n", *pi);
	*/
	const int* pi2 = &i;
	printf("*pi2 : %d\n", *pi2);

	*pi2 = 20;
}
