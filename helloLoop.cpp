#include <iostream>
#include <cunistd>

using namespace std;

#define ever (;;)
int main(){
    
   // for ever;
    int fpid;
    fpid = fork();

    if (fpid < 0) {
        cout << "error in fork!" << endl;
    } else if(fpid == 0) {
        cout << "this is child process, pid " + getpid());
    } else {
        cout << "this is parent process, pid " + getpid());
    }

    return 0;
}