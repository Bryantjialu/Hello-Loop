#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void createChild(int n, int flag) {
  if (flag < 0){
    printf("创建第%d个进程失败！\n", n);
  } else if (flag == 0) {
    printf("这是子进程%d，进程标识符是%d\n", n, getpid());
  } else {
    printf("这是子进程%d的父进程，进程标志是%d\n", n, getpid());
  }
}
int main(void)
{
  pid_t pid[10]; //进程标识符

  pid[0] = fork();    //创建一个新的进程
  while (true) {
    if (pid[0] < 0) {//如果返回的pid小于0则标示创建进程失败
      printf("创建进程失败!\n");
    } else if (pid[0] == 0) {//如果pid为0则表示当前执行的是子进程
      printf("这是子进程1,进程标识符是%d\n", getpid());
    }
    else {//否则为父进程
      printf("这是父进程，进程标识符是%d\n", getpid());
      pid[1] = fork();
      createChild(2, pid[1]);
      /*pid[1] = fork();
      if (pid[1] < 0) {
        printf("创建第二个进程失败！\n");
      }
      else if (pid[1] == 0) {//第二个子进程
        printf("这是子进程2，进程标识符是%d\n", getpid());
      }
      else {
        printf("这是子进程2的父进程，进程标志是%d\n", getpid());
        pid[2] = fork();
        if (pid[2] < 0) {
          printf("创建第三个进程失败！\n");
        }
        else if (pid[2] == 0) {
          printf("这是子进程3，进程标识符是%d\n", getpid());
        }
        else {
          printf("这是子进程3的父进程，进程标志是%d\n", getpid());
        }
      }
      */
    }
  }
  return 0; //返回
}
