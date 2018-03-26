#include <iostream>
#include <unistd.h>

int main(){
    pid_t pid;
    if((pid = fork()) < 0) {
        cout << "error forking" << endl;
    } else if (pid == 0) {
        sleep(8);
        cout << "orphan" << endl; //一旦一个进程结束，它的子进程就变成了孤儿进程
    } else {
        sleep(4);
        cout << "dead" << endl;
    }

    return 0;
}