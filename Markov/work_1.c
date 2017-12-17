#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){

	FILE *fpa, *fpb;
	char word[256];
	int i=0, count[122]={0};

	fpa = fopen("work1.txt", "r");	

	while(fgets(word,256,fpa) != NULL){
		while(word[i] != '\0'){
			if(word[i] >= 'a' && word[i] <= 'z'){
				count[word[i]]++;
			}
			else if(word[i] >= 'A' && word[i] <= 'Z'){
				count[word[i]]++;
			}
			i++;
		}
	}
	
	fpb = fopen("work1B.txt", "w");
	
	for(i=0; i<122; i++){
		if((i>=65&&i<=90)||(i>=97&&i<=122)){
			printf("%c : %d times \n", i, count[i]);
			fprintf(fpb, "%d:%c\n", count[i], i);
		}
	}
	
	fclose(fpa);
	fclose(fpb);
	
	return 0;
}
