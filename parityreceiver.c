#include<stdio.h>
#include<string.h>
void codeword(char str[100]) {
	for(int i=0;i<strlen(str)-1;i++){
		printf("%c",str[i]);
	}
	printf("\n");
}
void main() {
	char str[100],ch;
    int c=0,count=0;
    printf("Enter codeword :: ");
    gets(str);
    printf("The codeword is :: ");
    puts(str);
    while(str[c]!='\0') {
        if((str[c]=='1'))
            count++;
        c++;
    }
	printf("Total no of 1's :: %d\n",count);
	printf("\nEnter 'o' for odd and 'e' for even :: ");
	scanf("%c",&ch);
	switch(ch) {
		case 'e':	//even parity
			if(count%2==0) {
				printf("\nEven parity :: Accepted\nDataword :: ");
				codeword(str);
    		}
    		else {
    			printf("\nEven parity :: Rejected\n");
    		}
		break;
		case 'o'://odd parity
			if(count%2==0) {
    			printf("\nOdd parity :: Rejected\n");
    		}
    		else {
    			printf("\nOdd parity :: Accepted\nDataword :: ");
				codeword(str);
    		}
		break;
	}
}
