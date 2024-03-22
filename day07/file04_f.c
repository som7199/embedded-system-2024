/* som.txt 만들고 이 내용을 복사해서 somcpy.txt 생성하기! - 표준 입출력 버전 >
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 50
void error_handling(char* message);

int main(void)
{
  // 표준 입출력 함수 (fopen처럼 f 붙는거! 파일포인터로 파일을 가리킴)
  FILE* fp;
  char buf[BUF_SIZE] = "name:som,age:24,hello";

  fp = fopen("som.txt", "w");
  if (fp == NULL) {
    fprintf(stderr, "ERROR");
    exit(1);
  }
  fprintf(fp, "%s", buf);
  fclose(fp);

  fp = fopen("som.txt", "r");
  if(fp == NULL) {
    fprintf(stderr, "ERROR");
    exit(1);
  }
  fscanf(fp, "%s", buf);
  fclose(fp);

  FILE *fp2;
  fp2 = fopen("somcpy.txt", "w");
  if (fp == NULL) {
    fprintf(stderr, "ERROR");
    exit(1);
  }
  fprintf(fp2, "%s", buf);
  fclose(fp2);
}
