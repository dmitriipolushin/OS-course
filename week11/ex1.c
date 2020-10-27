#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int f = open("ex1.txt", O_RDWR);
    char newString[] = "This is a nice day";
    int size = sizeof(newString);
    ftruncate(f, size);
    char *src;
    src = mmap(NULL, size, PROT_WRITE, MAP_SHARED, f, 0);
    strcpy(src, newString);
    return 0;
}
