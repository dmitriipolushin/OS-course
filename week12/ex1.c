#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* randomFile;
    FILE* output;

    char str[20];
    randomFile = fopen("/dev/random", "r");
    output = fopen("ex1.txt", "w");
    fgets(str, 20, randomFile);
    fprintf(output, "%s", str);
    fclose(randomFile);
    fclose(output);
    return 0;
}
