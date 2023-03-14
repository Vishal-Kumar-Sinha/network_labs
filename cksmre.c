#include<stdio.h>
#include<string.h>

int checkequals(int sl,int l,char s2[]) {
	int flag=1;
	for(int i=0;i<sl;i++) {
		if(s2[i]!='0')
			flag=0;
	}
	return flag;
}
void main() {
	char dw[100],s1[100]={'\0'},s2[100]={'\0'};
	int sl,pad=0,c=0,t;
	printf("Enter codeword :: ");
	gets(dw);
	printf("enter segment length :: ");
	scanf("%d",&sl);
	int l=strlen(dw);
	int sum[sl];
	for(int i=0;i<sl;i++)
		sum[i]=0;
	if(l%sl!=0) // number of zeroes to be padded
	{	pad=sl-(l%sl);
	//if((l%sl)!=0) {
		for(int i=0;i<pad;i++)// padding zeroes in dataword
			s1[i]='0';
	}
	s1[pad]='\0';
	strcat(s1,dw); // storing new dataword in s1
	printf("Dataword after padding zeroes :: ");
	puts(s1);// dataword updated
	for(int i=0;i<strlen(s1);i=i+sl) {c=0;	//generating checksum	
		for(int j=i+sl-1;j>=i;j--) {
			t=(sum[j-i]+(s1[j]-48)+c)%2;
			c=(sum[j-i]+(s1[j]-48)+c)/2;
			sum[j-i]=t;
		}
		if(c==1) {
			for(int k=sl-1;k>=0;k--) {//adding and complementing			
				t=(sum[k]+c)%2;
				c=(sum[k]+c)/2;
				sum[k]=t;
			}
		}
	}
	for(int i=0;i<sl;i++) //integer to character
		s2[i]=sum[i]+48;
	for(int i=0;i<sl;i++) {
		if(s2[i]=='0')
			s2[i]='1';
		else if(s2[i]=='1')
			s2[i]='0';
	}
	s2[sl]='\0';
	if(!checkequals(sl,l,s2)) {
		printf("Rejected\n");
	}
	else {
		printf("Accepted\n");
		printf("Dataword :: ");
		for(int i=0;i<l-sl;i++) {// display codeword
				printf("%c",dw[i]);
		}
		printf("\n");
	}
}
