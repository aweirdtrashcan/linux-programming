#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{

    unsigned long word = 1720;
    size_t count;
    ssize_t bites_written;

    bites_written = read(39, &word, count);

    if( bites_written != count)
    {
        printf("error");
    }

    return 0;
}