#include <stdio.h>

// extern 키워드
extern char* input();
extern void showf(char*);

void main()
{
  char* str = input();
  //printf("%s", str);
  showf(str);
  showf("\n");
}
