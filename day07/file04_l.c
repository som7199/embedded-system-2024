/* som.txt 만들고 이 내용을 복사해서 somcpy.txt 생성하기! - 리눅스 버전 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 100
void error_handling(char* message);

int main(void)
{
  // 리눅스 입출력 함수(파일 디스크립터로 접근)
  int fd, fd1, fd2;
  char buf[100] = "hey!!!";
  char buf2[1024];

  // fd = open("som_l.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXO|S_IRWXU);
  fd = open("som_l.txt", O_CREAT|O_RDWR|O_TRUNC, 0644);
  if(fd < 0)
    error_handling("som_l.txt open() error!");
  printf("file descriptor : %d\n", fd);

  if(write(fd, buf, sizeof(buf)) < 0)
    error_handling("som_l.txt write() error!");
  close(fd);

  /*
  if(read(fd, buf2, 1024) < 0)
    error_handling("som_l.txt read() error!");
  printf("som_l.txt 내용 : %s\n", buf2);
  close(fd);
  */
  
  fd1 = open("som_l.txt", O_RDONLY);
  if(fd1 < 0)
    error_handling("som_l.txt open() error!");
  printf("file descriptor : %d\n", fd1);

  if(read(fd1, buf2, 1024) < 0)
    error_handling("som_l.txt read() error!");
  printf("som_l.txt 내용 : %s\n", buf2);
  close(fd1);

  fd2 = open("somcpy_l.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
  if(fd2 < 0)
    error_handling("somcpy_l.txt open() error!");
  printf("file descriptor : %d\n", fd2);

  if(write(fd2, buf2, sizeof(buf2)) < 0)
    error_handling("somcpy_l.txt write() error!");
  close(fd2);
  return 0;
}

void error_handling(char* message)
{
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}
