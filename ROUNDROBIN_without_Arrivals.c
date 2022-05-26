#include<stdio.h>
int main(){
	int p,bt[10],wt[10],tat[10],i,j,max,ct[10],t;
	float wtavg =0,tatavg=0,temp=0;
	printf("Enter no. of processors:");
	scanf("%d",&p);
	for(i=0;i<p;i++){
		printf("Enter the brust times for processor %d:",i);
		scanf("%d",&bt[i]);
		ct[i] = bt[i];
	}
	printf("Enter size of the time slice:");
	scanf("%d",&t);
	max = bt[0];
	for(i=1;i<p;i++)
		if(max < bt[i])
			max = bt[i];
	for(j=0;j<(max / t) +1;j++)
		for(i=0;i<p;i++)
			if(bt[i] != 0)
				if(bt[i] <= t){
					tat[i] = temp + bt[i];
					temp = temp +bt[i];
					bt[i] =0;
				}
				else{
					bt[i] = bt[i] - t;
					temp =temp +t;
				}
	for(i=0;i<p;i++){
		wt[i]= tat[i] - ct[i];
		tatavg += tat[i];
		wtavg += wt[i];
	}
	printf("\nAvg Turnaround time:%f",tatavg/p);
	printf("\nAvg waiting time:%f",wtavg/p);
	printf("\n\tPROCESSOR \t BRUST TIME \t WAITING TIME \t TURNAROUND TIME\n");
	for(i=0;i<p;i++)
		printf("\t %d \t\t %d \t\t %d \t\t %d \n",i+1,ct[i],wt[i],tat[i]);
}
/*
OUTPUT:
Enter no. of processors:5
Enter the brust times for processor 0:5
Enter the brust times for processor 1:3
Enter the brust times for processor 2:1
Enter the brust times for processor 3:2
Enter the brust times for processor 4:3
Enter size of the time slice:2

Avg Turnaround time:10.200000
Avg waiting time:7.400000
        PROCESSOR        BRUST TIME      WAITING TIME    TURNAROUND TIME
         1               5               9               14 
         2               3               9               12 
         3               1               4               5 
         4               2               5               7 
         5               3               10              13 
         
         */
