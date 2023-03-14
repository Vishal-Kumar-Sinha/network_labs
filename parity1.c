#include<stdio.h>
#include<string.h>
void main() {
	char str[100]={'\0'},s1[10]={'0'},s2[10]={'1'};
    int c=0,count=0;
    printf("Enter dataword :: ");
    gets(str);
    printf("The dataword is :: ");
    puts(str);
    while(str[c]!='\0') {
        if((str[c]=='1'))
            count++;
        c++;
    }
	//even parity
	printf("Total no of 1's :: %d\n",count);
	if(count%2==0) {
    	strcat(str,s1);
		printf("\nEven parity bit is :: %s",s1);
    }
    else {
    	strcat(str,s2);
		printf("\nEven parity bit is :: %s",s2);
    }
    printf("\nEven Codeword is :: %s",str);
	//odd parity
	if(count%2==0) {
    	strcat(str,s2);
		printf("\nOdd parity bit is :: %s",s2);
    }
    else {
    	strcat(str,s1);
		printf("\nOdd parity bit is :: %s",s1);
    }
    printf("\nOdd Codeword is :: %s",str);
}
