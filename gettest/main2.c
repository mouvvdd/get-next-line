#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("t1", O_RDONLY)
    printf("%s", get_next_line(fd));
}