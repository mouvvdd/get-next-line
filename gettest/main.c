#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    char *buffer;
    int rd;
    int fd = open("t1", O_RDWR);

    buffer = malloc(5 * sizeof(char));
    rd = read(fd, buffer, 5);
    // buffer[rd] = '\0';
    printf("B===============D : %s\n", buffer);

}