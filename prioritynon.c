#include<stdio.h>

int main()
{
    int n,i,j;
    int at[10],bt[10],pr[10],wt[10],tat[10],ct[10];
    int temp;

    float total_wt=0,total_tat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time:\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter Burst Time:\n");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);

    printf("Enter Priority:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pr[i]);

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i] > pr[j])
            {
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=at[i]; at[i]=at[j]; at[j]=temp;
            }
        }
    }

    int time=0;

    for(i=0;i<n;i++)
    {
        if(time < at[i])
            time = at[i];

        wt[i] = time - at[i];
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nProcess\tAT\tBT\tPR\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],wt[i],tat[i]);

    printf("\nAverage Waiting Time = %.2f",total_wt/n);
    printf("\nAverage Turnaround Time = %.2f",total_tat/n);

    return 0;
}
