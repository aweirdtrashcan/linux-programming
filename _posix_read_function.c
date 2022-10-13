#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(void)
{
    // int fd;
    // int i = 0;
    // int buf;
    // ssize_t ret;
    // ssize_t len = sizeof(buf);
    // errno = 0;

    // fd = open("/home/diego/Programming/c/main.c", O_RDWR, 0666);

    // if (fd == -1)
    // {
    //     perror("open error");
    //     return -2;
    // }

    // errno = 0;

    // while (len != 0 && (ret = read(fd, &buf, len)) != 0)
    // {
    //     i++;
    //     if (ret == -1)
    //     {
    //         continue;
    //         perror("read");
    //         break;
    //     }

    //     len -= ret;
    //     buf += ret;
    // }

    // printf("value of i: %d\nvalue of buf: %d\n", i, buf);

    char buf[BUFSIZ];
    ssize_t nr;

    int fd = 0;

    errno = 0;
    start:
    nr = read(fd, buf, BUFSIZ);
    if (nr == -1)
    {
        if (errno == EINTR)
            goto start;
        if (errno == EAGAIN)
            perror("Error reading file, Try again");
        else
            perror("Error reading file");
    }

    return 0;
}