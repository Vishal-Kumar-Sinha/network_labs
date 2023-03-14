#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {
	char dw[100],div[100],s2[100]={'\0'},s1[100];
    int c=0,i,j;
    printf("Enter codeword :: ");
    gets(dw);
	printf("Enter divisor :: ");
    gets(div);
    printf("The codeword is :: ");
    puts(dw);
	printf("The divisor is :: ");
    puts(div);
	int dn=strlen(dw);
	for(i=0;i<dn-strlen(div)+1;i++)
		s1[i]=dw[i];
	int n=strlen(dw)-strlen(div)+1;
	for(i=0;i<n;i++) {
	  if(dw[i]=='1') {
		for(j=0;j<strlen(div);j++) {
				int x=dw[i+j]-'0';
				int y=div[j]-'0';
				int z=x^y;
				dw[i+j]=z+'0';
	    }
	  }
	}
	for(i=0;i<strlen(div)-1;i++){
		s2[i]=dw[n+i];
	}
	for(i=0;i<strlen(s2);i++){
		if(s2[i]!='0') {
			printf("Rejected\n");
			exit(0);
		}
	}
	printf("Accepted\nDataword :: ");
	puts(s1);
}
