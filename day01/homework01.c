#include <stdio.h>

void main()
{
	char name[10];
	int age;
	printf("이름 입력 : ");
	scanf("%s", name);
	printf("나이 입력 : ");
	scanf("%d", &age);

	printf("이름 : %s \n나이 : %d\n", name, age);
}
