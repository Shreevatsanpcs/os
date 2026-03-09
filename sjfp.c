#include <stdio.h>

int main()
{
    int n, choice;
    int at[10], bt[10], rt[10], ct[10], wt[10], tat[10], resp[10];
    int i, j;

    printf("CPU Scheduling - SJF\n");
    printf("1. Non Preemptive SJF\n");
    printf("2. Preemptive SJF (SRTF)\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT for P%d: ",i+1);
        scanf("%d",&at[i]);
    }

    for(i=0;i<n;i++)
    {
        printf("Enter BT for P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
        resp[i]=-1;
    }

    if(choice==1)   // Non-Preemptive SJF
    {
        int completed=0, time=0, min, index;
        int visited[10]={0};

        while(completed<n)
        {
            min=9999;
            index=-1;

            for(i=0;i<n;i++)
            {
                if(at[i]<=time && visited[i]==0 && bt[i]<min)
                {
                    min=bt[i];
                    index=i;
                }
            }

            if(index==-1)
            {
                time++;
                continue;
            }

            resp[index]=time-at[index];

            time+=bt[index];
            ct[index]=time;

            tat[index]=ct[index]-at[index];
            wt[index]=tat[index]-bt[index];

            visited[index]=1;
            completed++;
        }
    }

    else if(choice==2)   // Preemptive SJF (SRTF)
    {
        int complete=0, time=0, smallest;

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

            if(resp[smallest]==-1)
                resp[smallest]=time-at[smallest];

            rt[smallest]--;
            time++;

            if(rt[smallest]==0)
            {
                complete++;

                ct[smallest]=time;
                tat[smallest]=ct[smallest]-at[smallest];
                wt[smallest]=tat[smallest]-bt[smallest];
            }
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    float avgwt=0,avgtat=0;

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i],resp[i]);

        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f",avgtat/n);

    return 0;
}
