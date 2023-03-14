#include<stdio.h>
#include<string.h>
void main() {
	char dw[100],s1[100]={'\0'},s2[100]={'\0'};
	int sl,pad=0,c=0,t;
	printf("Enter dataword :: ");
	gets(dw);
	printf("enter segment length :: ");
	scanf("%d",&sl);
	int l=strlen(dw);
	int sum[sl];
	for(int i=0;i<sl;i++)
		sum[i]=0;
	if(l%sl!=0) // number of zeroes to be padded
	{	pad=sl-(l%sl);
	//if((l%sl)!=0) {// padding zeroes in dataword
		for(int i=0;i<pad;i++)
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
	printf("Sum :: ");
	puts(s2);// display sum
	printf("Checksum :: ");
	for(int i=0;i<sl;i++) {
		if(s2[i]=='0')
			s2[i]='1';
		else if(s2[i]=='1')
			s2[i]='0';
	}
	s2[sl]='\0';
	puts(s2);// display checksum
	strcat(dw,s2);// checksum appended with dataword to form codeword
	printf("Codeword :: ");
	puts(dw);// display codeword
}
