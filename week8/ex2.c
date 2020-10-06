#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * after starting executing program the free space is decreasing 
 * and si and so becomes nonzero to allocate enough memory
*/

/*
 * after running top -d1 we can see information about existing processes
 * we can see how many of virtual memory is used by our program
 * how many of CPU it takes and its priority
*/

int main(int argc, char const *argv[])
{
    int size = 1024*1024*10;
    for(int i = 0; i < 10; i++){
        void *array = malloc(size);
        memset(array, 0, size);
        sleep(10);
    }
    
    return 0;
}
