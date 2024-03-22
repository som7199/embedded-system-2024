#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void main()
{
  char id[20];
  char pwrd[50];

  const char* pid = "som123";
  const char* ppwrd = "qwe123";

  int log = 0;
  while(log != 5) {
    printf("아이디를 입력하세요 > ");
    scanf("%s", id);
    printf("비밀번호를 입력하세요 > ");
    scanf("%s", pwrd);

    if(strcmp(id, pid) == 0 && strcmp(pwrd, ppwrd) == 0) {
      printf("로그인 성공!\n");

      FILE* fp;
      char buf[1024];

      fp = fopen("myinfo.txt", "r");
      if (fp == NULL) {
        fprintf(stderr, "ERROR!!!\n");
        exit(1);
      }
      fscanf(fp, "%s", buf);
      printf("%s", buf);
      fclose(fp);

      /*
      FILE* fp;
      fp = fopen("myinfo.txt", "w");
      if (fp == NULL) {
        fprintf(stderr, "ERROR!!!");
        exit(1);
      }
      fprintf(fp, "%s\n%s", id, pwrd);
      fclose(fp);
      */
      break;
    }
    else
      printf("로그인 %d회 실패\n", log + 1);
      log++;
  }
}

      
