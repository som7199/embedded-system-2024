# embedded-system-2024
IoT 개발자 임베디드 시스템 학습 리포지토리

## 1일차
- 개발 환경 구축
	- 라즈베리파이 설정
	- https://www.raspberrypi.com/software/
	- 라즈베리파이 SD카드 포맷
	- https://www.sdcard.org/downloads/formatter/sd-memory-card-formatter-for-windows-download/
	- PuTTy
	- https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html
	
- Secure SHell(SSH) : 원격지 호스트 컴퓨터에 접속하기 위해 사용되는 인터넷 프로토콜
	- SSH 오픈소스인 PuTTY를 사용하여 라즈베리파이에 원격 접속을 할 것
	
## 2일차
sd카드 포맷 → sd카드에 라즈베리파이 os(SSH 설정 잊지말고) 저장 → PuTTy 원격 설정!

* 명령어
- pwd : 현재 디렉토리
- mkdir : 새 디렉토리 생성
- rm -fr 디렉토리명 : 디렉토리 삭제
- ls : 디렉토리(directory)에 있는 내용(디렉토리, 파일 등)을 확인
- ls -a : 숨겨진 파일이나 디렉토리도 보여준다.
- ls -l : 자세한 내용 출력! 내용> 퍼미션(권한), 포함된 파일수, 소유자, 그룹, 파일크기, 수정일자, 파일이름
- ls /etc : etc 파일은 시스템의 모든 기본 설정 파일이 담겨있음
- sudo nano /etc/nanorc : 관리자 권한으로 nano 환경 설정 (nano 편집기)
	- set autoindent 주석 해제
	- set linenumbers 주석 해제
	- set tabsize 2로 변경

## 3일차
- 자기 참조 구조체와 동적할당을 이용한 연결리스트
```c
typedef struct NODE {
  int data;
  struct NODE *next;
} node;

typedef struct {
  node *head;
} headNode;
```

```c
// 후위삽입 - 새 노드를 제일 뒤로!
void rear_addNode(headNode *pnode, int _data)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = _data;
  newNode->next = NULL;

  // 아무런 노드도 생성되지 않은 경우
  if(pnode->head == NULL)
  {
    pnode->head = newNode;
  }
  // 이미 생성된 노드들이 있는 경우
  else
  {
    node* curr = pnode->head;
    // 마지막 노드까지 순회하다가!
    while(curr->next != NULL){
      curr = curr->next;
    }
    // 마지막 노드에 새로운 노드 연결!!!
    curr->next = newNode;
  }
}
```

## 4일차
- 동적 할당을 받는 경우, 메모리 공간에 할당 받지 못한 경우를 생각해서 조건문 써주기!
```c
// 전위삽입 - 새 노드가 제일 앞으로!
void pre_addNode(headNode* pnode, int _data)
{
  node* newNode = (node*)malloc(sizeof(node));
  // if(newNode == NULL) return -1;
  if(newNode != NULL) {
    newNode->data = _data;
    newNode->next = pnode->head;    // headNode 자체가(headNode 필드의 head가)>
    pnode->head = newNode;
  }
}

```

## 5일차
- 새로운 컴파일 방법!
	- makeT 디렉토리 생성
	- nano makefile
	```c
	test:
		gcc -o test main.c inputf.c printf.c

	```
	- make 명령어 치고 나면 gcc -o test main.c inputf.c printf.c 되고 test 실행 파일 만들어짐
	- ./test 하면 실행됨!
	- 큰 프로젝트는 makefile에다가 컴파일 형태의 관계를 작성해주고 진행한대..!
	
## 6일차
- 파일 입출력
	- fopen(), fprintf()처럼 f 붙으면 표준입출력 => 파일포인터로 접근!
	- open(), write(), read() 이런건 리눅스에서 사용하는 파일 입출력 => 파일 디스크립터로 접근!
		- 파일 디스크립터 : 시스템으로부터 할당 받은 파일 또는 소켓에 부여된 정수
		- 파일과 소켓은 생성의 과정을 거치면 파일 디스크립터가 할당됨
		- 파일 또는 소켓을 생성할 때마다 운영체제는 해당 파일 또는 소켓에 부여된 숫자(파일 디스크립터)를 건네줌

- 리눅스 기반에서 실행
	```SHell
	gcc som.c -o test // som.c라는 파일을 컴파일해서 test라는 실행파일을 만들기
	./test			// 현재 디렉터리의 test라는 이름의 파일을 실행시키기
	```
	
## 7일차
- 과제 진행 중...