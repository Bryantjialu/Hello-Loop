#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void createChild(int n, int flag)
{
  if (n == 11) {
    return;
  }

  if (flag < 0)
  {
    printf("创建第%d个进程失败！\n", n);
  }
  else if (flag == 0)
  {
    printf("这是子进程%d，进程标识符是%d\n", n, getpid());
  }
  else
  {
    printf("这是子进程%d的父进程，进程标志是%d\n", n, getpid());
    pid_t pid = fork();
    createChild(n+1, pid);
  }
}
int main(void)
{
  pid_t pid1, pid2; //进程标识符

  pid1 = fork(); //创建一个新的进程
  if (pid1 < 0) { //如果返回的pid小于0则标示创建进程失败
    printf("创建进程失败!\n");
  }
  else if (pid1 == 0)  { //如果pid为0则表示当前执行的是子进程
    printf("这是子进程1,进程标识符是%d\n", getpid());
  }
  else { //否则为父进程
    printf("这是父进程，进程标识符是%d\n", getpid());
    pid2 = fork();
    createChild(2, pid2);
  }

  return 0; //返回
}
