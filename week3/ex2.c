#include <stdio.h>

// function to swap values of two variables with each other
void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

// function to sort array using BubbleSort method
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // input part
    printf("input the length of array\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("input the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // performing part
    bubbleSort(arr, n);
    
    // output part
    printf("sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    return 0;
}
