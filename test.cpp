#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

int main() {
    while (true) {
	cout << "Run" << endl;
        clock_t start, end;
        start = clock();

        while (clock() - start < 5 * 1000000) {

        }
        cout << "sleeping" << endl;
        sleep(5); //linux下是5swindows下是5微秒
    }
}
