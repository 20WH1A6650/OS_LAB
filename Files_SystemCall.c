#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
        char str[1000],str1[1000];
        int fd,fs,i=0;
        char ch;
        fd = open("sample.txt",O_CREAT | O_WRONLY| O_TRUNC);
        while((ch = getchar()) != EOF){
                str[i++]=ch;
        }
        write(fd,str,i);
        close(fd);
        fs=open("sample.txt",O_RDONLY);
        read(fs,str,i);
        printf("%s",str1);
        close(fs);
} 

/*
OUTPUT:
hello
hi
hello
hi
*/
