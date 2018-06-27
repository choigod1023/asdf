#include <stdio.h>
int main()
{

	int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;

	float avg_wt, avg_tat;
	printf("Enter nubmer of process: ");
	scanf("%d", &n);
	printf("\nEnter Burst Time:\n");
	for (i = 0; i < n; i++)
	{
		printf("P[%d]: ", i + 1);
		scanf("%d", &bt[i]);
		p[i] = i + 1;
	}
	for (i = 0; i < n; i++)
	{
		pos = i;
		for (j = i + 1; j < n; j++)
		{
			if (bt[j] < bt[pos])
				pos = j;
		}
		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}
	wt[0] = 0;
	for (i = 1; i < n; i++)
	{
		wt[i] = 0;
		wt[i] = wt[i - 1] + bt[i - 1];
		total += wt[i];
	}

	avg_wt = total*1.0 / n;
	total = 0;

	printf("\nProcess\tBurstTime\tWaiting Time\tTurnaroundTime");
	for (i = 0; i < n; i++)
	{
		tat[i] = 0;
		for (j = 0; j <= i; j++)
		{
			tat[i] = tat[i] + bt[j];
		}
		total += tat[i];
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t",p[i] , bt[i], wt[i], tat[i]);
	}

	avg_tat = total*1.0 / n;
	printf("\n\nAverage Waiting Time= %.2f", avg_wt);
	printf("\nAverage Turnaround Time= %.2f\n", avg_tat);
	getch();
	return 0;
}