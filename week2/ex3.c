#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int count = atoi(argv[1]);
    for (int i = 1; i < count+1; i++)
    {
        for (int j = 0; j < 2*i-1; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
    
    return 0;
}
