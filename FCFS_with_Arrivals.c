#include<stdio.h>
void swap(int *x,int *y){
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
int main(){
    int n,i;
    printf("enter number of processes\n");
    scanf("%d",&n);
    int p[n],bt[n],at[n],wt[n],tat[n],st[n];
    for(int i = 0;i < n;i++){
        printf("enter the burst time of process %d",i);
        scanf("%d",&bt[i]);
        printf("enter the arrival time of process %d",i);
        scanf("%d",&at[i]);
        p[i] = i + 1;
    }
    st[i] = bt[i];
    st[0] = at[0];
    wt[0] = 0;
    for(i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            if(at[i] > at[j]){
                swap(&at[i],&at[j]);
                swap(&p[i],&p[j]);
                swap(&bt[i],&bt[j]);
            }
        }
    }
    for(int i = 1;i < n;i++){
        st[i] = st[i - 1] + bt[i - 1];
        wt[i] = st[i] - at[i];
    }
    int total_wt = 0,total_tat = 0;
    float avg_wt = 0,avg_tat = 0;
    for(int i = 0;i < n;i++){
        tat[i] = wt[i] + bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("process\t\tburst\t\tarrivals\twaiting\tturnaround\n");
    for(int i = 0;i < n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],at[i],wt[i],tat[i]);
    }
    avg_wt = total_wt / n;
    avg_tat = total_tat / n;
    printf("Average waiting time : %f\n",avg_wt);
    printf("Average turn around time : %f\n",avg_tat);
}

/*
OUTPUT:
enter number of processes
4
enter the burst time of process 0 6 
enter the arrival time of process 0 1
enter the burst time of process 1 5
enter the arrival time of process 1 1
enter the burst time of process 2 5
enter the arrival time of process 2 2
enter the burst time of process 3 3
enter the arrival time of process 3 4
process         burst           arrivals        waiting turnaround
1               6               1               0               6
2               5               1               6               11
3               5               2               10              15
4               3               4               13              16
Average waiting time : 7.000000
Average turn around time : 12.000000

*/
