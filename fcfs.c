#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    int temp;
    float twt = 0, ttat = 0, awt, att;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process %d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &bt[i]);
    }


    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }


    ct[0] = at[0] + bt[0];
    wt[0] = 0;
    tat[0] = bt[0];

    for(i = 1; i < n; i++) {

        if(ct[i-1] < at[i]) {
            // CPU Idle
            ct[i] = at[i] + bt[i];
            wt[i] = 0;
        }
        else {
            wt[i] = ct[i-1] - at[i];
            ct[i] = ct[i-1] + bt[i];
        }

        tat[i] = wt[i] + bt[i];
    }

    for(i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
    }

    awt = twt / n;
    att = ttat / n;

    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", att);

    return 0;
}
