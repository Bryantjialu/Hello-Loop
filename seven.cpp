#include <unistd.h>
#include <iostream>
#include <fcntl.h>

int main() {
    int fd1, fd2, fd3;
    fd1 = open("fork1.cpp", O_RDONLU);
    fd2 = open("fork2.cpp", O_RDONLU);
    fd3 = open("fork3.cpp", O_RDONLU);

    cout << fd1 << " " << fd2 << " " << fd3 << " " << endl;

    close(fd2);
    cout << "关掉第二个文件并打开第四个文件" << endl;

    int fd4;
    fd4 = open("fork4.cpp", O_RDONLU);
    cout << fd1 << " " << fd2 << " " << fd4 << " " << endl;

    return 0;
}