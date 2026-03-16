#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;
    int at[20], bt[20], rem_bt[20];
    int ct[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int done;
    while(remain > 0) {
        done = 1;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rem_bt[i] > 0) {
                done = 0;
                if(rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    rem_bt[i] = 0;
                    remain--;
                }
            }
        }
        if(done) {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
