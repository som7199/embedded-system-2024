// 열거형
#include <stdio.h>

void main()
{
	enum season { SPRING = 10, SUMMER, FALL, WINTER } s;
	s = SPRING;
	printf("%d\n", s);

	s = WINTER;
	printf("%d\n", s);
}
