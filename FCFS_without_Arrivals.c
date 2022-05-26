#include<stdio.h>

int main(){
    int n;
    printf("Enter number of process\n");
    scanf("%d",&n);

    int i,p[n],b[n],a[n],w[n],tA[n];
    
    for(i = 0;i < n;i++){
        p[i] = i + 1;
    }

    printf("Enter burst time\n");
    for(i = 0;i < n;i++){
        scanf("%d",&b[i]);
    }

    w[0] = 0;
    for(i=1;i<n;i++)
    {
        w[i]=0;
        for(int j=0;j<i;j++)
            w[i] += b[j];
    }

    for(i = 0;i < n;i++){
        tA[i] = w[i] + b[i];
    }

    float tat_avg = 0.0,tat_total = 0.0,wt_avg = 0.0,wt_total = 0.0;
    for(i = 0;i < n;i++){
        tat_total += tA[i];
        wt_total += w[i];
    }
    tat_avg = tat_total / n;
    wt_avg = wt_total / n;
 
    printf("OUTPUT\n");
    printf("Process\tBurst\tWaiting\tTurnaround\n");
    for(i = 0;i < n;i++){
        printf("%d\t%d\t%d\t%d\n",p[i],b[i],w[i],tA[i]);
    }

    printf("Average Waiting time: %f\n",wt_avg);
    printf("Average turnaround time: %f\n",tat_avg);

    return 0;
}

/*
OUTPUT:
Enter number of process
4
Enter burst time
6
5
5
3
OUTPUT
Process Burst   Waiting Turnaround
1       6       0       6
2       5       6       11
3       5       11      16
4       3       16      19
Average Waiting time: 8.250000
Average turnaround time: 13.000000

*/
