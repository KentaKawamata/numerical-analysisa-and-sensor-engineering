#include<stdio.h>

int main(void){

	char temp = 0x59;
	char moto = 92;
	int n = 89;

	printf("%c\n", moto);
	moto=temp;
	printf("%c\n", moto);

	if(moto==n){
		printf("%c\n", moto);
	}	

	moto++;
	printf("%c\n", moto);

	return 0;
}
