#include <stdio.h>
#define swap(a, b) \
    int temp = a; \
    a = b; \
    b = temp;

int main(int argc, char const *argv[])
{
    int a;
    int b;
    scanf("%d %d", &a, &b);
    swap(a, b);
    printf("%d %d", a, b);
    return 0;
}