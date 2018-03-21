#include <iostream>
#include <cunistd>

using namespace std;

#define ever (;;)
int main(){
    
   // for ever;
    int fpid1, fpid2;
    fpid1 = fork();

    if (fpid1 < 0) {
        cout << "创建进程失败" << endl; //创建进程失败
    } else if(fpid1 == 0) { //返回0是子进程
        cout << "这是第一个子进程, pid为 " + getpid()) << endl;
    } else {    //返回2是父进程
        cout << "这是父进程, pid " + getpid()) << endl;

        fpid2 = fork();
        if (fpid <0) {
            cout << "创建第二个进程失败" << endl;
        } else if (fpid2 == 0) {
            cout << "这是第二个子进程，pid为 " + getpid()) << endl;
        } else {
            cout << "这是第二个子进程的父进程，pid为 " + getpid() << endl;
        }
    }

    return 0;
}