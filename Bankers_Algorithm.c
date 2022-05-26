#include<stdio.h>
int main(){
    int i , j , k , c , n , c1 , r ;
    int alloc[10][10] ,avail[10] , max[10][10] , need[10][10] , status[10] ;
    printf("Enter no.of processors");
    scanf("%d",&n);
    printf("Enter no.of resources");
    scanf("%d",&r);
    printf("Enter max no.of resources");
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < r ; j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter allocation no.of resources");
    for(i = 0 ; i < n ;i ++){
        for(j = 0 ; j < r ; j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter available resources");
    for(i = 0 ; i < r ; i++)
        scanf("%d",&avail[i]);
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < r ; j++){
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d",need[i][j]);
        }
        printf("\n");
    }
    for(i = 0 ; i < n ; i++)
        status[i] = 0;
    int flag = 1;
    while(flag){
        flag = 0;
        for(i = 0 ; i < n ; i++){
            c = 0;
            for(j = 0 ; j < r ; j++){
                if(status[i] == 0 && avail[j] >= need[i][j]){
                    c++;
                    if(c == r){
                        for(k = 0 ; k < r ; k++)
                            avail[k] = avail[k] + alloc[i][k];
                   
                    status[i] = 1;
                    printf("\nP%d",i+1);
                    flag = 1;
                }
            }
        }
    }
}

    c1 = 0;
    for(i = 0 ; i < n ; i++){
        if(status[i] == 1)
            c1++;
    }
    if(c1 == n)
        printf("Process safe");
    else
        printf("Process is not safe");
}
}
/*
OUTPUT:

Enter no.of processors5
Enter no.of resources3
Enter max no.of resources7
5
3
3
2
2
9
0
2
2
2
2
4
3
3
Enter allocation no.of resources0
1
0
3
0
2
3
0
2
2
1
1
0
0
2
Enter available resources3
3
2
743
020
600
011
431

P2
P3
P4
P5
P1
Process safe
*/
