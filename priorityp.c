#include <stdio.h>

int main()
{
    int n, choice;
    int at[10], bt[10], pr[10];
    int ct[10], tat[10], wt[10], rt[10], resp[10];
    int i;

    printf("Priority CPU Scheduling\n");
    printf("1. Non Preemptive Priority\n");
    printf("2. Preemptive Priority\n");
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
    }

    for(i=0;i<n;i++)
    {
        printf("Enter Priority for P%d: ",i+1);
        scanf("%d",&pr[i]);
        resp[i] = -1;
    }

    if(choice==1)   // Non Preemptive
    {
        int completed=0, time=0, index, min;
        int visited[10]={0};

        while(completed<n)
        {
            min=9999;
            index=-1;

            for(i=0;i<n;i++)
            {
                if(at[i]<=time && visited[i]==0 && pr[i]<min)
                {
                    min=pr[i];
                    index=i;
                }
            }

            if(index==-1)
            {
                time++;
                continue;
            }

            resp[index] = time - at[index];

            time += bt[index];
            ct[index] = time;

            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            visited[index] = 1;
            completed++;
        }
    }

    else if(choice==2)   // Preemptive
    {
        int complete=0, time=0, index, min;

        while(complete<n)
        {
            min=9999;
            index=-1;

            for(i=0;i<n;i++)
            {
                if(at[i]<=time && rt[i]>0 && pr[i]<min)
                {
                    min=pr[i];
                    index=i;
                }
            }

            if(index==-1)
            {
                time++;
                continue;
            }

            if(resp[index]==-1)
                resp[index] = time - at[index];

            rt[index]--;
            time++;

            if(rt[index]==0)
            {
                complete++;

                ct[index]=time;
                tat[index]=ct[index]-at[index];
                wt[index]=tat[index]-bt[index];
            }
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

    float avgwt=0,avgtat=0;

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i],resp[i]);

        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f",avgtat/n);

    return 0;
}
