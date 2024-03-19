#include <stdio.h>

char* input()
{
  // static 키워드 => 프로그램이 끝날 때까지 살아있게 되니까 main()에서 쓸 수>
  static char str[10];
  static char *pstr = str;

  printf("입력 > ");
  scanf("%s", str);

  return pstr;
}
