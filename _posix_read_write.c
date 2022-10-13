#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define M_BUFFER_SIZE 1024

int main(void)
{
    char buf[M_BUFFER_SIZE] = "My ship is solid";
    char r_buf[M_BUFFER_SIZE];
    char *file_path = "/home/diego/Programming/c/mytext.txt";
    ssize_t nr;
    int fd, r_code;
    ssize_t count = M_BUFFER_SIZE;

    errno = 0;
    fd = creat(file_path, O_CREAT | O_TRUNC | S_IRWXG | S_IRWXO | S_IRWXU | O_RDWR);

    errno = 0;
    nr = write(fd, &buf, count);

    if (count != nr)
    {
        perror("An error ocurred while writting to a file");
        return -2;
    }

    fd = open(file_path, O_RDONLY | O_NONBLOCK);

    if (fd == -1)
    {
        perror("Open file error");
        return -3;
    }

    errno = 0;
    start:
    while (count != 0 && (r_code = read(fd, &r_buf, count)) != 0)
    {
        if (r_code == -1)
        {
            if (errno == EINTR)
            {
                goto start;
            }
            if (errno == EAGAIN)
            {
                printf("An error ocurred, please try again");
                return -4;
            }
            else
            {
                perror("An error ocurred while reading");
                return -5;
            }
        }
        count -= r_code;
    }

    printf("%s\n", r_buf);

    return 0;
}