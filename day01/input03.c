#include <stdio.h>

void main()
{
	char ch, ch2;
	int n;
	/*
	printf("문자 : ");
	scanf("%c", &ch);
	*/

	printf("학번 : ");
	scanf("%d", &n);
	//  printf("%c, %d\n", ch, n);

	getchar();
	printf("이름 : ");
	scanf("%c", &ch2);
	printf("%d, %c\n", n, ch2);
}
