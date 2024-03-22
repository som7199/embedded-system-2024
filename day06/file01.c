#include <stdio.h>
#include <stdlib.h>

void main()
{
  char msg[20] = "FileTest!!!";

  FILE* fp;   // 파일포인터
  fp = fopen("test.txt", "w");  // 파일 오픈
  if(fp == NULL) {
    fprintf(stderr, "Error");
    exit(1);
  }

  fprintf(fp, "%s", msg);       // 파일로 출력
  printf("%s", msg);

  fclose(fp);
}
