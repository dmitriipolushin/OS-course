#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char word[256], revWord[256];
    fgets(word, 256, stdin);
    int length = strlen(word);
    for (int i = 0; i < length-1; i++)
    {
        revWord[i] = word[length-2-i];
    }
    
    printf("%s", revWord);
    
    return 0;
}
