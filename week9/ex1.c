#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_NUM 1000

int inFrames(int frames[], int page, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (page == frames[i])
        {
            return i;
        }
    }
    return -1;
}

int minIndex(unsigned int* bits, int n)
{
    unsigned int min = pow(2, 16);
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (bits[i] < min)
        {
            min = bits[i];
            ind = i;
        }
    }
    return ind;
}

void shift(unsigned int* a, int r)
{
    *a = (*a >> 1) | (r << 15);
}


void moveRight(unsigned int* bits, int index, int n)
{
    for (int j = 0; j < n; j++)
        if (j != index)
            shift(&bits[index], 0);
}

int main(int argc, int const *argv[])
{
    int n;
    printf("enter the num of page frames: ");
    scanf("%d", &n);

    FILE *fs;
    int num;
    fs = fopen("input.txt", "r");
    int *array = malloc(INPUT_NUM * sizeof(int));

    int frames[n];
    unsigned int* bits = (unsigned int*)calloc(n, sizeof(int));
    int frameIndex;
    int hit = 0, miss = 0;

    for (int i = 0; i < INPUT_NUM; i++) 
    {
        fscanf(fs, "%d", &array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        frames[i] = -1;
        bits[i] = 0;
    }
    
    for (int i = 0; i < INPUT_NUM; i++)
    {
        int free_space_ind = inFrames(frames, -1, n);
        int index = inFrames(frames, frames[i], n);
        if (index != -1)
        {
            hit++;
            shift(&bits[index], 1);
            moveRight(bits, index, n);  
        }
        else
        {
            if (free_space_ind != -1)
            {
                miss++;
                frames[free_space_ind] = array[i];
                bits[free_space_ind] = 0;
                shift(&bits[free_space_ind], 1);
                moveRight(bits, free_space_ind, n);  
            }
            else
            {
                miss++;
                index = minIndex(bits, n);
                frames[index] = array[i];
                bits[index] = 0;
                shift(&bits[index], 1);
                moveRight(bits, index, n);  
            }
        }
    }

    printf("hit: %d, miss: %d", hit, miss);

    return 0;
}
