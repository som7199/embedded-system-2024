#include <stdio.h>
#include <stdlib.h>

void main()
{
  char msg[20];
  FILE* fp;
  if((fp = fopen("test.txt", "r")) == NULL) {
    fprintf(stderr, "ERROR"); // ERROR가 뜨는 내용들이 모니터에 출력됨
    exit(1);
  }

  fscanf(fp, "%s", msg);  // test.txt에 있는 문자열을 읽어와서 msg에 저장
  printf("%s\n", msg);

  fclose(fp);
}
