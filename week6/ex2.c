#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) 
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void sortingProcesses(int a[], int b[], int c[], int n) {
    int t;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
                swap(&b[i], &b[j]);
                swap(&c[i], &c[j]);
            }
            else if (a[i] == a[j])
            {
                if (b[i] > b[j])
                {
                    swap(&a[i], &a[j]);
                    swap(&b[i], &b[j]);
                    swap(&c[i], &c[j]);
                }
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    // number of processes
    int n;
    scanf("%d", &n);

    int arrivalTime[n];
    int burstTime[n];
    int processesIndexes[n];

    for (int i = 0; i < n; i++)
    {
        printf("Arrival time of process [%d]: ", i+1);
        scanf("%d", &arrivalTime[i]);
        printf("Burst time of process [%d]: ", i+1);
        scanf("%d", &burstTime[i]);
        processesIndexes[i] = i+1;
    }

    sortingProcesses(arrivalTime, burstTime, processesIndexes, n);

    int CT[n];
    int TAT[n];
    int WT[n];

    int time = 0;
    int available[n];
    int allTime = 0;
    int nextPInd;
    int maxBurst = 0;
    int maxBurstInd = 0;

    for (int i = 0; i < n; i++)
    {
        allTime = allTime + burstTime[i];
        available[i] = 1;
        if (burstTime[i] > maxBurst)
        {
            maxBurst = burstTime[i];
            maxBurstInd = i;
        }
    }

    while (time < allTime)
    {
        int nextPInd = maxBurstInd;
        int minBurst = maxBurst;
        for (int i = 0; i < n; i++)
        {
            if (arrivalTime[i] <= time && available[i] > 0)
            {
                if (burstTime[i] <= minBurst)
                {
                    minBurst = burstTime[i];
                    nextPInd = i;
                }
            }
        }
        if (nextPInd == maxBurstInd && available[maxBurstInd] == -1)
            time = time + 1;
        else
        {
            CT[nextPInd] = time + burstTime[nextPInd] - arrivalTime[nextPInd];
            TAT[nextPInd] = time + burstTime[nextPInd];
            WT[nextPInd] = time - arrivalTime[nextPInd];
            available[nextPInd] = -1;
            time = time + burstTime[nextPInd];    
        }
    }

    double ATT, AWT;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        a = a + TAT[i];
        b = b + WT[i];
    }
    ATT = (double) a/n;
    AWT = (double) b/n;

    /*
        The processes can be printed in not the same order
        as it will be input in a program.
        Nevertheless, the numbers of processes still the same 
    */
    printf("processN\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        int processN = processesIndexes[i];
        printf("Process%d\t%d\t%d\t%d\t%d\t%d\n", 
                processN, 
                arrivalTime[i],
                burstTime[i],
                CT[i],
                TAT[i],
                WT[i]
            );
    }
    printf("Average Turnaround time: %f\n", ATT);
    printf("Average waiting time: %f", AWT);
    return 0;
}