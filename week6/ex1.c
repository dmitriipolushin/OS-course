#include <stdio.h>

void swap(int a, int b) 
{
    int t;
    t = a;
    a = b;
    b = t;
}

void sortingProcesses(int a[], int b[], int c[], int n) {
    int t;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                swap(c[i], c[j]);
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

    for (int i = 0; i < n; i++)
    {
        CT[i] = time + burstTime[i] - arrivalTime[i];
        TAT[i] = time + burstTime[i];
        WT[i] = time - arrivalTime[i];
        time = time + burstTime[i];
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
