#include <stdio.h>
#include <string.h>

int main() {
    int i = 0, processNumber[10], burstTime[10], n, waitTime[10], temp = 0, j, turnaroundTime[10];
    float avgWaitTime = 0, avgTat = 0;

    for (i = 0; i < 10; i++) {
        processNumber[i] = i;
    }

    printf("\n Enter the no of process ");
    scanf("%d", &n);
    printf("\n Enter the burst time of each process");

    for (i = 0; i < n; i++) {
        printf("\n p%d", i);
        scanf("%d", &burstTime[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burstTime[i] > burstTime[j]) {
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                temp = processNumber[i];
                processNumber[i] = processNumber[j];
                processNumber[j] = temp;
            }
        }
    }

    waitTime[0] = 0;
    for (i = 1; i < n; i++) {
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
        avgWaitTime += waitTime[i];
    }

    printf("\n process no \t burst time\t waiting time \t turn around time\n");
    for (i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitTime[i];
        avgTat += turnaroundTime[i];
        printf("\n p%d\t\t%d\t\t%d\t\t%d", processNumber[i], burstTime[i], waitTime[i], turnaroundTime[i]);
    }

    avgWaitTime /= n;
    avgTat /= n;
    printf("\n\n\t Average waiting time %f\n\t Average turn around time %f", avgWaitTime, avgTat);

    return 0;
}
