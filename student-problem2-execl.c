#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char** argv)
{
	

	pid_t pid;
	
	printf("execlaration function execution\n");
	pid = fork(); //fork 예시
	if (pid)
	{
		//부모프로세스
	}
	else
	{
		//자식프로세스
		execl("/bin/ls", "ls", "-al", (char*)NULL); //exec 예시
		// 다음 코드는 execlause 실패시에만 실행한다
	// /bin/ls가 코드를 대체하기 때문이다
		return -1;
	}

	return 0;
}

