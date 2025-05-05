// Write a program to read n characters from a file and append them back to the same file using dup2 function.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char filename[] = "input.txt";
    int n = 10;
    
    int fd = open(filename, O_RDWR);
    char buffer[MAX_BUFFER_SIZE];
    
    int bytes_read = read(fd, buffer, n);
    close(fd);
    
    fd = open(filename, O_WRONLY | O_APPEND);
    dup2(fd, STDOUT_FILENO);
    printf("%.*s", bytes_read, buffer);
    close(fd);
    printf("\nSuccessfully appended the characters to the file.\n");
    return 0;
}
