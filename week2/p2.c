#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    // File to be created
    const char *filename = "example.txt";

    // File permissions: Read & Write for owner, Read-only for group and others
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // Equivalent to 0644

    // Create file using creat() system call
    int fd = creat(filename, mode);

    // Error handling
    if (fd == -1) {
        perror("creat() error");
        exit(EXIT_FAILURE);
    }

    printf("File '%s' created successfully with file descriptor: %d\n", filename, fd);

    // Close file descriptor
    if (close(fd) == -1) {
        perror("close() error");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
