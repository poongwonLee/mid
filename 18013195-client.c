#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
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
	mkfifo(FIFO ,0666);
	//쓰기전용으로 연다
	fd = open(FIFO, O_RDONLY);
	do{
		if((num = read(fd, buf, 100)) == -1)
				perror("read error");
		else{
			//입력받은 마지막에 null을 넣어 오류 방지한다.
			buf[num] = '\0';
			//받은 문자열숫자를 정수형 숫자로 변환한다.
			int n=atoi(buf);

			printf("	%d+1 = %d\n",n,n+1);
		}
	}	while (num >0);

		return 0;
}

				
