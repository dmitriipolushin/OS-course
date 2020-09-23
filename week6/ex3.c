#include <stdio.h>

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
        }
    }
}

int main(int argc, char const *argv[])
{
    // number of processes
    int n;
    int q;
    printf("number of processes: ");
    scanf("%d", &n);
    printf("quantum: ");
    scanf("%d", &q);

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

    // sorting processes by arrival time
    sortingProcesses(arrivalTime, burstTime, processesIndexes, n);

    int CT[n];
    int TAT[n];
    int WT[n];
    int time = 0;
    int allTime = 0;
    int available[n];
    int remBurstTime[n];

    for (int i = 0; i < n; i++)
    {
        CT[i] = 0;
        TAT[i] = 0;
        allTime = allTime + burstTime[i];
        available[i] = 1;
        remBurstTime[i] = burstTime[i]; 
    }

    int currentP = 0;
    int currentQ = 3;

    while (time < allTime)
    {
        if (remBurstTime[currentP] <= currentQ && available[currentP] > 0)
        {
            printf("delete %d %d %d\n", currentP, remBurstTime[currentP], currentQ);
            available[currentP] = -1;
            CT[currentP] = CT[currentP] + time + remBurstTime[currentP] - arrivalTime[currentP];
            TAT[currentP] = TAT[currentP] + time + remBurstTime[currentP];
            WT[currentP] = time - arrivalTime[currentP];
            currentQ = currentQ - remBurstTime[currentP];
            time = time + remBurstTime[currentP];
            currentP = currentP + 1;
        }
        else if (available[currentP] > 0)
        {
            printf("continue %d %d %d\n", currentP, remBurstTime[currentP], currentQ);
            remBurstTime[currentP] = remBurstTime[currentP] - currentQ;
            time = time + currentQ;
            currentP = currentP + 1;
            currentQ = 3;
        }
        else currentP = currentP + 1;
        if (currentP == n)
        {
            currentP = 0;
        }
        if (currentQ == 0)
        {
            currentQ = 3;
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