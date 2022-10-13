#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    // int fd;
    // errno = 0;
    // if ( (fd = open("/home/diego/Programming/main.c", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU, S_IRWXG, S_IRWXO) ) < 0)
    // {
    //     perror("Failed to open file");
    // }

    int fd;
    char *position = "/home/diego/Programming/main.cpp"; 
    fd = creat(position, S_IRUSR | S_IRGRP | S_IROTH);
    errno = 0;
    if (0 > fd)
    {
        perror("An error has ocurred");
    }

    return 0;
}