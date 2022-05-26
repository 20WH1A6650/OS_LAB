#include<stdio.h>    
 
int main()  
{  
    int i, p, sum=0,count=0, y, tq, wt=0, tat=0, at[10], bt[10], st[10];  
    float avg_wt, avg_tat;  
    printf(" Total number of process in the system: ");  
    scanf("%d", &p);  
    y = p;
   
for(i=0; i<p; i++)  
{  
printf("\nEnter the Arrival and Burst time of the Process[%d]\n", i+1);  
printf("Arrival time is: ");  
scanf("%d", &at[i]);  
printf("Burst time is: ");
scanf("%d", &bt[i]);  
st[i] = bt[i];
}  

printf("Enter the Time Quantum for the process: ");  
scanf("%d", &tq);  

printf("\n Process No \t\t Burst Time \t\t\t TAT \t\t\t Waiting Time ");  
for(sum=0, i = 0; y!=0; )  
{  
if(st[i] <= tq && st[i] > 0)    
{  
    sum = sum + st[i];  
    st[i] = 0;  
    count=1;  
    }    
    else if(st[i] > 0)  
    {  
        st[i] = st[i] - tq;  
        sum = sum + tq;    
    }  
    if(st[i]==0 && count==1)  
    {  
        y--;  
        printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        count =0;    
    }  
    if(i==p-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}

avg_wt = wt * 1.0/p;  
avg_tat = tat * 1.0/p;  
printf("\n Average Turn Around Time: \t%f", avg_tat);  
printf("\n Average Waiting Time: \t%f", avg_wt);  
}        
