#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

int main() {
    while (true) {
        clock_t start, end;
        cout << "run" << endl;
        start = clock();

        while (clock() - start < 5 * 1000000) {

        }
        cout << "sleeping" << endl;
        sleep(5); //linux下是5s windows下是5微秒
    }
}