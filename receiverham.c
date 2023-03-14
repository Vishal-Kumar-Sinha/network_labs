#include <stdio.h>
#include<string.h>
#include <math.h>
char dw[100],cw[100];  // c_l is codeword length, p_n is number of redundant/parity bits
char calcbit(int p,int c_l) { //calculate bit in position p
	int count=0,i,j;
	i=p-1;
	while(i<c_l) {
		for(j=i;j<i+p;j++) { //message bit numbers for XOR operation to get parity bit
			if(cw[j]=='1')
				count++;//for odd number of 1's XOR is 1 and for even 1's XOR is 0
		}
		i=i+2*p;
	}
	if(count%2==0) //XOR operation
		return '0';
	else
		return '1';
}
void correction(int pos,char cw[]) { //correction of hamming code
	if(cw[pos-1]=='0')
        cw[pos-1]='1';
    else
        cw[pos-1]='0';
    printf("\nCorrected Hamming code :: ");
    puts(cw);
}
void makedw(int c_l,int p_n,char cw[]) {
	int i,j,k=0;
	j=0;
	for(i=0;i<c_l;i++) { //messagebit traversal
		int x=((int)pow(2,j))-1;
		if(i!=x) {//position-index relation
			dw[k++]=cw[i];
		}
		else	j++;
	}
	printf("Dataword :: ");
	puts(dw);
}
void ham(int c_l,char cw[]) {
	int n,i=0,p_n=0,j,k;
	while(c_l>=(int)pow(2,i)) {
		p_n++;
		i++;
	}		
	n=c_l-p_n;
	int error_pos=0;
	for(i=0;i<p_n;i++) {
		int position=(int)pow(2,i);
		char value=calcbit(position,c_l);
		if(value!='0')
			error_pos+=position;
	}
	if(error_pos==0 || error_pos>c_l) {
		printf("The received Codeword is correct.\nCodeword :: ");
		puts(cw);
		makedw(c_l,p_n,cw);
	}
	else {
		printf("Error at bit position :: %d",error_pos);
		correction(error_pos,cw);
		makedw(c_l,p_n,cw);
	}
}
void main()
{
	printf("Enter received codeword :: ");
	gets(cw);
	int c_l=strlen(cw);
	ham(c_l,cw);
}