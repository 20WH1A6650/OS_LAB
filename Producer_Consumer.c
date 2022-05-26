#include<stdio.h>
#include<stdlib.h>

int full =0, empty = 5, mutex = 1, x =0;

int wait(int s){
	s--;
return s;
}

int signal(int s){
	s++;
return s;
}

void producer(){
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	x++;
	printf("producer produces the item %d", x);
	mutex = signal(mutex);
}

void consumer(){
	mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("consumer  consumes the item %d", x);
    x--;
	mutex = signal(mutex);
}

int main(){
	int ch;
	printf("1.producer\n2.consumer\n3.exit\n");
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
					if(mutex == 1 && (empty != 0))
						producer();
					else
						printf("Buffer is full");
					break;
			case 2:
					if(mutex == 1 && (full != 0))
						consumer();
					else
						printf("Buffer is empty");
					break;
			case 3:
					exit(0);
		}
	}
}
