#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){

	FILE *fpa, *fpb;
	char wordA, wordB;
	int i=0, j=0, count[122]={0};
	char space=0x20;

	fpa = fopen("work2.txt", "r");
	fpb = fopen("work2b.txt", "w");
	/**while(fgets(word,256,fp) != NULL){
		while(word[i] != '\0'){
			if(word[i] >= 'a' && word[i] <= 'z'){
				count[word[i]]++;
			}
			else if(word[i] >= 'A' && word[i] <= 'Z'){
				count[word[i]]++;
			}
			i++;
		}
	}**/
	
	//while((wordA=getc(fp)) != EOF){
	//	printf("%c", wordA);
	//}
	//printf("\n");

	//for(i=0; i<122; i++){
	//	if((i>=65&&i<=90)||(i>=97&&i<=122)){
	//		printf("%c : %d times \n", i, count[i]);
	//	}
	//}

	while((wordB=getc(fpa)) != EOF){
		/**switch(word[i]){
			case 0x21:
				word[i] = space;
			case 0x22:
				word[i] = space;
			case 0x23:
				word[i] = space;
			case 0x24:
				word[i] = space;**/
		printf("%c", wordB);		
		
		for(j=33; j<65; j++){
			if(wordB == j){
				wordB = space;
			}	
		}
		for(j=91; j<97; j++){
			if(wordB == j){
				wordB = space;
			}
		}
		for(j=123; j<127; j++){
			if(wordB == j){
				wordB = space;
			}
		}
		fprintf(fpb, "%c", wordB);		
	}
	printf("\n");
	fclose(fpa);
	fclose(fpb);

	fpb = fopen("work2b.txt", "r");
	
	while((wordA=getc(fpb)) != EOF){
		printf("%c", wordA);
	}
	printf("\n");
	fclose(fpb);
	return 0;
}
