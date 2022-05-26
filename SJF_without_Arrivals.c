#include<stdio.h>
int main(){
	int p[10], bt[10], wt[10], tat[10], i, k, n, temp;
	float wtavg, tatavg;
	printf("\nEnter the number of processors:");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		p[i]=i;
		printf("Enter Burst Time for Processor %d : ", i);
        scanf("%d", &bt[i]); 
	}
	for(i=0;i<n;i++)
		 for(k=i+1;k<n;k++) 
			if(bt[i]>bt[k]){
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
			}
	wt[0] = wtavg = 0;
	tat[0] = tatavg = bt[0];
	for(i=1;i<n;i++){
		wt[i] = wt[i-1] +bt[i-1];
		tat[i] = tat[i-1] +bt[i];
		wtavg = wtavg + wt[i];
		tatavg = tatavg + tat[i];
	}
	printf("\n\t PROCESSOR \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
	for(i=0;i<n;i++)
		printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
 	printf("\nAverage Waiting Time: %f", wtavg/n);
	printf("\nAverage Turnaround Time: %f", tatavg/n);
}

/*
OUTPUT:
Enter the number of processors:4
Enter Burst Time for Processor 0 : 6
Enter Burst Time for Processor 1 : 5
Enter Burst Time for Processor 2 : 5
Enter Burst Time for Processor 3 : 3

         PROCESSOR      BURST TIME       WAITING TIME    TURNAROUND TIME

         P3              3               0               3
         P2              5               3               8
         P1              5               8               13
         P0              6               13              19
Average Waiting Time: 6.000000
Average Turnaround Time: 10.750000

*/
