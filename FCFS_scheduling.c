#include<stdio.h>

int main()
{
    int n, burst_time[20], arrival_time[20], waiting_time[20], turnaround_time[20];
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter total number of processes (maximum 20): ");
    scanf("%d", &n);

    printf("\nEnter Process Arrival Time and Burst Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    waiting_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = 0;
        for (int j = 0; j < i; j++)
        {
            waiting_time[i] += burst_time[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

    avg_turnaround_time /= n;
    printf("\nAverage Turnaround Time: %.2f ms\n", avg_turnaround_time);

    for (int i = 0; i < n; i++)
    {
        avg_waiting_time += waiting_time[i];
    }

    avg_waiting_time /= n;
    printf("\nAverage Waiting Time: %.2f ms\n\n", avg_waiting_time);

    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    return 0;
}

