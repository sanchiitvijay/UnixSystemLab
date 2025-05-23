#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    struct stat statbuf;

    if (stat("foo", &statbuf) < 0) {
        perror("stat error for foo");
        exit(1);
    }

    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
        perror("chmod error for foo");
        exit(1);
    }

    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
        perror("chmod error for bar");
        exit(1);
    }

    exit(0);
}
