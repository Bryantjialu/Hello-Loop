#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    pid_t pid;

    if((pid = fork()) < 0) {
        cout << "error fork" << endl;
    } else if( pid == 0) {
        cout << "zombie" << endl;
    } else {
        sleep(10);
    }
}