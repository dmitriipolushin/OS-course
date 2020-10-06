#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char const *argv[])
{
    struct rusage usage;
    int size = 1024*1024*10;
    for(int i = 0; i < 10; i++){
        void *array = malloc(size);
        memset(array, 0, size);
        getrusage(RUSAGE_SELF, &usage);
        printf("usage: %ld\n", usage.ru_maxrss);
        sleep(1);
    }
    
    return 0;
}
