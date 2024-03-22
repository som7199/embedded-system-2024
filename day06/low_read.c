#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 100
void error_handling(char* message);

int main(void)
{
  int fd;
  char buf[BUF_SIZE];

  fd = open("data.txt", O_RDONLY);      // data.txt를 읽기 전용으로 열기
  if(fd == -1)
    error_handling("open() error!");
  printf("file descriptor: %d \n", fd);

  if(read(fd, buf, sizeof(buf)) == -1)  // read 함수로 배열 buf에 읽어들인 데>
    error_handling("read() error!");
  printf("file data : %s", buf);
  close(fd);
  return 0;
}

void error_handling(char* message)
{
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}
