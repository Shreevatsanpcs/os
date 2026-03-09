#include <stdio.h>

int main()
{
    int n, choice;
    int at[10], bt[10], rt[10], wt[10], tat[10];
    int i, j;

    printf("CPU Scheduling - SJF\n");
    printf("1. Non Preemptive SJF\n");
    printf("2. Preemptive SJF (SRTF)\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("\nEnter Arrival Times:\n");
    for(i=0;i<n;i++)
    {
        printf("AT for P%d: ",i+1);
        scanf("%d",&at[i]);
    }

    printf("\nEnter Burst Times:\n");
    for(i=0;i<n;i++)
    {
        printf("BT for P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    if(choice==1)   // Non Preemptive
    {
        int p[10], temp;

        for(i=0;i<n;i++)
            p[i]=i+1;

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(bt[i] > bt[j])
                {
                    temp=bt[i];
                    bt[i]=bt[j];
                    bt[j]=temp;

                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }

        wt[0]=0;

        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
                wt[i]+=bt[j];
        }

        printf("\nProcess\tAT\tBT\tWT\tTAT\n");

        float avg_wt=0,avg_tat=0;

        for(i=0;i<n;i++)
        {
            tat[i]=wt[i]+bt[i];
            avg_wt+=wt[i];
            avg_tat+=tat[i];

            printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
        }

        printf("\nAverage Waiting Time = %.2f",avg_wt/n);
        printf("\nAverage Turnaround Time = %.2f",avg_tat/n);
    }

    else if(choice==2)   // Preemptive
    {
        int time=0,complete=0,smallest;
        int total_wt=0,total_tat=0;

        while(complete<n)
        {
            smallest=-1;

            for(i=0;i<n;i++)
            {
                if(at[i]<=time && rt[i]>0)
                {
                    if(smallest==-1 || rt[i]<rt[smallest])
                        smallest=i;
                }
            }

            if(smallest==-1)
            {
                time++;
                continue;
            }

            rt[smallest]--;
            time++;

            if(rt[smallest]==0)
            {
                complete++;
                int finish=time;

                total_wt+=finish-at[smallest]-bt[smallest];
                total_tat+=finish-at[smallest];
            }
        }

        printf("\nAverage Waiting Time = %f",(float)total_wt/n);
        printf("\nAverage Turnaround Time = %f",(float)total_tat/n);
    }

    else
    {
        printf("Invalid Choice");
    }

    return 0;
}
