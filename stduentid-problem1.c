#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
 
int main() {
     
    pid_t pid;
     
  
    pid = fork();
     
    if(pid > 0) {  // 부모 코드
      
        printf(" Parent PID is : %ld",(long)getpid());


    }
    else if(pid == 0){  // 자식 코드
       
        printf("Child PID is : %ld",(long)getpid());
    }
    else {     // fork 실패
        printf("fork Fail! \n");
        return -1;
    }
     
    return 0;
 
}
