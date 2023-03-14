#include<stdio.h>
#include<string.h>

void main() {
	char dw[100],div[100],s1[100]={'0'},s2[100];
    int c=0,i,j;
    printf("Enter dataword :: ");
    gets(dw);
	printf("Enter divisor :: ");
    gets(div);
    printf("The dataword is :: ");
    puts(dw);
	printf("The divisor is :: ");
    puts(div);
	int n=strlen(dw);
	for(i=0;i<n;i++)
		s2[i]=dw[i];
	for(i=0;i<strlen(div)-1;i++)
		dw[n+i]='0';
	//puts(dw);
	int dn=strlen(dw);
	for(i=0;i<n;i++) {
	  if(dw[i]=='1') {
		for(j=0;j<strlen(div);j++) {
			//printf("\ni=%d, j=%d\n",i,j);
				int x=dw[i+j]-'0';
				int y=div[j]-'0';
				int z=x^y;
				dw[i+j]=z+'0';
	    }
	  }
	}
	printf("CRC :: ");
	//puts(dw);
	for(i=0;i<strlen(div)-1;i++){
		printf("%c",dw[n+i]);
	}
	for(i=0;i<strlen(div)-1;i++){
		s2[n+i]=dw[n+i];
	}
	printf("\nCodeword :: ");
	puts(s2);
}