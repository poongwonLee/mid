#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO "FIFO"
int main(void)
{
	char buf[100];
	int num, fd;
	int n;	
	// FIFO 을 FIFO 파일로 만들어 줌 permission는 0666으로
	mkfifo(FIFO,  0666);
	//쓰기전용으로 연다
	fd = open(FIFO, O_WRONLY);
	// 표준 입력 파일을 끝까지 읽어들임
    	// Ctrl + D 를 누르면 표준 입력파일에 EOF 를 넣을 수 있음
	while(fgets(buf, sizeof(buf), stdin), !feof(stdin)){
	//파일 지정번호가 fd일 파일에 입력한 buf를 기록한다.
		write(fd, buf, strlen(buf));
		
	}
	return 0;
}
