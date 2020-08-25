#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[])
{
    int intVar;
    float floatVar;
    double doubleVar;

    intVar = INT_MAX;
    floatVar = FLT_MAX;
    doubleVar = DBL_MAX;

    printf("%lu \n %lu \n %lu", sizeof(intVar), sizeof(floatVar), sizeof(doubleVar));

    return 0;
}
