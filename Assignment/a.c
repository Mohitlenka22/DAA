#include <stdio.h>

int main() {
    int n, i, j, quantum, wt[20], tat[20], at[20], bt[20], rt[20], ct[20], t = 0;
    float avwt = 0, avtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the quantum: ");
    scanf("%d", &quantum);

    printf("Enter arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                if (rt[i] > quantum) {
                    t += quantum;
                    rt[i] -= quantum;
                } else {
                    t += rt[i];
                    ct[i] = t;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }

    printf("\nProcess Arrival Time Burst Time Completion Time Waiting Time TurnaroundTime\n");
    for (i = 0; i < n; i++) {
        printf("P%-8d%-16d%-16d%-16d%-16d%-16d\n", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
        avwt += wt[i];
        avtat += tat[i];
    }
    avwt /= n;
    avtat /= n;
    printf("\nAverage Waiting Time: %.2f", avwt);
    printf("\nAverage Turnaround Time: %.2f", avtat);
    return 0;
}
