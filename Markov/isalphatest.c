#include<stdio.h>
#include<ctype.h>

int main(void){
	char moto[] = "kv/;.afsfv@.sf%Hhu&D#sifsn";
	int i=0;
	char space = 0x20;

	printf("%s\n", moto);

	while(moto[i] != '\0'){
		if(isalpha(moto[i])==0){
			if((moto[i]!=0x20)||(moto[i]!=0x0a)){
				moto[i] = space;
			}
		}
		i++;
	}
		
	printf("%s\n", moto);
	return 0;
}
