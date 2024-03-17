 #include <stdio.h>
 2 #define MAX 20
 3
 4 void main()
 5 {
 6   int arr[MAX];
 7   int num, inNum;
 8
 9   printf("Input Data >> ");
10   scanf("%d", &num);
11   printf("배열 입력\n");
12   for(int i = 0; i < num; i++) {
13     scanf("%d", &inNum);
14     arr[i] = inNum;
15   }
16   //배열 출력
17   printf("순차 출력 > ");
18   for(int i = 0; i < num; i++) {
19     printf("%d ", arr[i]);
20   }
21   printf("\n");
22
23   // 역순으로 출력
24   printf("역순 출력 > ");
25   for(int i = num - 1; i > -1; i--) {
26     printf("%d ", arr[i]);
27   }
28   printf("\n");
29 }
