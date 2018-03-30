#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    pid_t pid;
    int size = 4;
    while (size--) {    
    if((pid = fork()) < 0) {
        cout << "error forking" << endl;
    } else if (pid == 0) {
	cout << "child process" << endl;
	cout << "pid: " << getpid() << "  ppid: " << getppid() << endl;
        cout << "orphan" << endl; //一旦一个进程结束，它的子进程就变成了孤儿进程
   	
	sleep(8);
	cout << "pid: " << getpid() << " ppid: " << getppid() << endl; 
    } else {
        sleep(4);
  	cout << "father process" << endl;
	
        cout << "dead" << endl;
    }
    }
    return 0;
}
