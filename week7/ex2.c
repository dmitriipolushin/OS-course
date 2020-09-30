#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("length of array: ");
    scanf("%d", &n);

    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
