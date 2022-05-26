#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{	
	int pd1[2],pd2[2];
	char s1[100] = "BVRIT",s2[100] = "Hyderabad", s3[100], s4[100];
	pipe(pd1);
	pipe(pd2);
	int p = fork();
	if(p > 0)
	{
		close(pd1[0]);
		write(pd1[1],s1,20);
		close(pd1[1]);
		wait(NULL);
		close(pd2[1]);
		read(pd2[0],s4,20);
		printf("\nString 2 : %s",s4);
		close(pd2[0]);
	}
	else if(p == 0)
	{
		close(pd1[1]);
		read(pd1[0],s3,20);
		printf("\nString 1: %s \n",s3);
		close(pd1[0]);
		close(pd2[0]);
		write(pd2[1],s2,20);
		close(pd2[1]);
		exit(0);
	}
printf("\n");
}
/*
OUTPUT:
String 1: BVRIT 

String 2 : Hyderabad
*/

