#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#define ever (;;)

using namespace std;
int pause;
/*
void createChild(int n, int flag)
{

    if (flag < 0)
    { //如果返回的pid小于0则标示创建进程失败
        printf("创建第%d个进程失败！\n", n);
    }
    else if (flag == 0)
    { //如果pid为0则表示当前执行的是子进程
        printf("这是子进程%d，进程标识符是%d\n", n, getpid());
        pid_t pid = fork();
        createChild(n+1, pid);
    }
    else
    { //否则为父进程
        printf("这是子进程%d的父进程，进程标志是%d\n", n, getpid());
        pid_t pid = fork();
        createChild(3, pid);
    }
    
    if (n == 3) {
        return;
    }
}
*/

class childProcessBinaryTree {
    int level;
    pid_t left;
    pid_t right;
    void createProcess(int currentLevel) {
        left = fork();

        if (left < 0) {
            cout << "Created process failed" << endl;
        } else if (left == 0) { // child process
            cout << "This is left child process(" << getpid() << ")" << endl;
            if (currentLevel < level) {
                this->createProcess(currentLevel + 1);
            }
        } else if (left > 0) { // parent process
            cout << "Process(" << getpid() << ") has created a left child process(" << left << ")" << endl;

            right = fork();

            if (right < 0) {}
            else if (right == 0) { //child process
                cout << "This is right child process(" << getpid() << ")" << endl;
                if (currentLevel < level) {
                    this->createProcess(currentLevel + 1);
                }
            } else {
                cout << "Process(" << getpid() << ") has created a right child process(" << right << ")" << endl;
            }
        }
    }

public:
    childProcessBinaryTree(int level): level(level) {
        this->createProcess(1);

	cin >> pause;
    }
};

int main(void)
{ 
    new childProcessBinaryTree(3);
    return 0; //返回
}
