#include<stdio.h>
#include<string.h>
#include<math.h>

char dw[100],cw[100];  // c_l is codeword length, p_n is number of redundant bits
char calcbit(int p,int c_l) { //calculate bit in position p
	int count=0,i,j;
	i=p-1;
	while(i<c_l) {
		for(j=i;j<i+p;j++) {
			if(cw[j]=='1') // If current bit is 1
				count++;
		}
		i=i+2*p;
	}
	if(count%2==0)
		return '0';
	else
		return '1';
}

void ham(char dw[],int n) {
	int i,p_n=0,c_l,j,k;
	i=0;
	while(n>((int)pow(2,i)-(i+1))) {
		p_n++;
		i++;
	}
	c_l=p_n+n;
	j=k=0;
	for(i=0;i<c_l;i++) { //messagebit traversal
		if(i==((int)pow(2,k)-1)) {//position-index relation
			cw[i]='0';
			k++;
		}
		else {
			cw[i]=dw[j];
			j++;
		}
	}
	for(i=0;i<p_n;i++) {
		int pos=(int)pow(2,i);
		char value=calcbit(pos,c_l);
		cw[pos-1]=value;//updating parity bit value
	}
	printf("Codeword :: ");
	puts(cw);// Print the Hamming Code
}

void main() {
	printf("Enter dataword :: ");
	gets(dw);
	int n=strlen(dw);
	ham(dw,n);
}