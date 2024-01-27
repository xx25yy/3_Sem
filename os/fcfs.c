
#include <stdio.h> 
int main()
{
    int n, arrivalTime[20], burstTime[20], startTime[20], finishTime[20], waitingTime[20], turnaroundTime[20];
    float
        avgTat,
        avgWt;
    char processName[20][20];
    printf("Enter No. of Processes\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Processes Name, Arrival Time and Burst Time:");
        scanf("%s%d%d", &processName[i],
              &arrivalTime[i], &burstTime[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            startTime[i] = arrivalTime[i];
            waitingTime[i] = startTime[i] - arrivalTime[i];
            finishTime[i] = startTime[i] + burstTime[i];
            turnaroundTime[i] =
                finishTime[i] - arrivalTime[i];
        }
        else
        {
            startTime[i] = finishTime[i - 1];
            waitingTime[i] = startTime[i] - arrivalTime[i];
            finishTime[i] = startTime[i] +
                            burstTime[i];
            turnaroundTime[i] = finishTime[i] - arrivalTime[i];
        }
    }
    int totTat = 0;
    int totWt = 0;
    printf("\nProcess Arrival \tBurst \tStart \tTuraround \tWait \tFinish");
    for (int i = 0; i < n; i++)
    {
        printf("\n%s\t%4d\t\t%4d\t%4d\t%4d\t\t%4d\t%4d", processName[i], arrivalTime[i], burstTime[i],
               startTime[i], turnaroundTime[i], waitingTime[i], finishTime[i]);
        totWt += waitingTime[i];
        totTat += turnaroundTime[i];
    }
    avgTat = (float)totTat / n;
    avgWt = (float)totWt / n;
    printf("\nAverage Turnaround Time:%.2f", avgTat);
    printf("\nAverage Wait Time:%.2f", avgWt);
}