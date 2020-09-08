#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char word[256];
    /*
    we will execute the commands until we stop the progrma using ^C
    */
    while (1) 
    {
        fgets(word, sizeof(word), stdin);
        system(word);
    }
    return 0;
}
