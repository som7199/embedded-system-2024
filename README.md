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

## 4일차

## 5일차