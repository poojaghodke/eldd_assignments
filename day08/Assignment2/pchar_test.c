#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include "pchar_ioctl.h"

int main(int argc, char *argv[])
{
    int fd, ret;
    info_t info;
    if (argc != 2)
    {
        printf("invalid usage.\n");
        printf("usage1: %s clear\n", argv[0]);
        printf("usage2: %s info\n", argv[0]);
        _exit(2);
    }

    fd = open("/dev/pchar0", O_RDWR);
    if (fd < 0)
    {
        perror("open() failed");
        _exit(1);
    }

    // fifo clear
    if (strcmp(argv[1], "clear") == 0)
    {
        ret = ioctl(fd, FIFO_CLEAR);
        if (ret != 0)
            perror("ioctl() failed");
        else
            printf("fifo cleared.\n");
    }
    else if (strcmp(argv[1], "info") == 0)
    {
        // fifo get info
        info_t info;
        ret = ioctl(fd, FIFO_INFO, &info);
        if (ret != 0)
            perror("ioctl() failed");
        else
            printf("fifo info: size=%d, filled=%d, empty=%d.\n", info.size, info.len, info.avail);
    }
    else
    {
        printf("invalid usage.\n");
        printf("usage1: %s clear\n", argv[0]);
        printf("usage2: %s info\n", argv[0]);
    }
    
    // Resize the FIFO
    if(ioctl(fd, FIFO_RESIZE) == -1) {
        perror("Failed to resize FIFO");
        close(fd);
        return -1;
    }

    // Get FIFO info after resizing
    if(ioctl(fd, FIFO_INFO, &info) == -1) {
        perror("Failed to get FIFO info");
        close(fd);
        return -1;
    }
    printf("After resize: size = %d, avail = %d, len = %d\n", info.size, info.avail, info.len);

    close(fd);
    return 0;
}
