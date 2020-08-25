#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RIGHT 1
#define ISOSCALES 2
#define RECTANGLE 3

int main(int argc, char *argv[])
{
    int count = atoi(argv[1]);
    int shape;
    printf("Enter the number to choose the shape of figure\n 1 - right triangle\n 2 - isosceles triangle, 3 - rectangle\n");
    scanf("%d", &shape);
    switch (shape) {
        case RIGHT:
            for (int i = 1; i < count+1; i++)
            {
                for (int j = 0; j < 2*i-1; j++)
                {
                    printf("%s", "*");
                }
                printf("\n");
            }
            break;
        case ISOSCALES:
            for (int i = 1; i < count/2+1; i++)
            {
                for (int j = 0; j < 2*i-1; j++)
                {
                    printf("%s", "*");
                }
                printf("\n");
            }
            for (int i = count/2+1; i > 0; i--)
            {
                for (int j = 0; j < 2*i-1; j++)
                {
                    printf("%s", "*");
                }
                printf("\n");
            }
            break;
        case RECTANGLE:
            for (int i = 1; i < count+1; i++)
            {
                for (int j = 0; j < count; j++)
                {
                    printf("%s", "*");
                }
                printf("\n");
            }
    }
    return 0;
}
