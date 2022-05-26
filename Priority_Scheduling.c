#include <stdio.h>
void swap(int* x, int* y) {
	int temp  = *x;
	*x = *y;
	*y = temp;
}
int main(){
   int n,i,avgw=0,avgt=0,temp;
   int priority[10] = {0}, burst_time[10] = {0}, p[10] = {0},t[10] = {0}, w[10] = {0};
   printf("Enter the number of processors:");
   scanf("%d",&n);
   for(i = 0;i < n; i++){
	   printf("priority and burst time for p[%d] :",i);
	   scanf("%d %d",&priority[i],&burst_time[i]);
	   p[i] = i;
   }
   for(i =0; i < n-1; i++){
	   for(int j = i + 1; j < n; j++){
		   if(priority[i] > priority[j]){
				swap(&p[i],&p[j]);
				swap(&priority[i], &priority[j]);
				swap(&burst_time[i], &burst_time[j]);
              
		   }
		   
	   }
	   
   }
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (priority[i] == priority[j])	{
				swap(&p[i], &p[j]);
				swap(&priority[i], &priority[j]);
				swap(&burst_time[i], &burst_time[j]);
			}
		}
	}


w[0] = 0;
for(i = 1; i < n; i++){
	w[i] = w[i-1] + burst_time[i-1];
	avgw += w[i];
}
for (int i = 0; i < n; i++) {
	t[i] = w[i] + burst_time[i];
	avgt += t[i];
}
printf("\n Process  burst_time   waiting time   turnaroundtime\n");
for(i = 0; i < n; i++){
	printf("p[%d]    %d     %d       %d\n",p[i], burst_time[i], w[i],t[i]);
}
   
   
printf("\navg waiting time =  %d", avgw/n);
printf("\navg turnaround time =  %d\n", avgt/n);
    


    return 0;  
}
/*
OUTPUT:
Enter the number of processors:4
priority and burst time for p[0] :3 6
priority and burst time for p[1] :2 
2
priority and burst time for p[2] :1 14
priority and burst time for p[3] :4 6

 Process  burst_time   waiting time   turnaroundtime
p[2]       14                0       14
p[1]        2               14       16
p[0]        6               16       22
p[3]        6               22       28

avg waiting time =  13
avg turnaround time =  20
*/
