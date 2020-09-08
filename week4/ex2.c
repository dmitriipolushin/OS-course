#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int f;
    for (int i = 0; i < 3; i++)
    {
        f = fork();
        sleep(5);        
    }
    /*
    we get the 8 processes, because we fork our program three times
    after the first fork there are two processes
    after the second for every of previous two we have another two -> 4
    after the third for every of previous four we have another two -> 8
    a.out─┬─a.out─┬─a.out───a.out
      │       └─a.out
      ├─a.out───a.out
      └─a.out
    */
    return 0;
}
