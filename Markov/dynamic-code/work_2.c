#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){

	FILE *fpa, *fpb;
	char wordA, wordB;
	int i=0, j=0, count[122]={0};
	char space=0x20;

	fpa = fopen("koretsukae.txt", "r");
	fpb = fopen("usethisfile.txt", "w");

	while((wordB=getc(fpa)) != EOF){
		printf("%d", wordB);		
		
		if((wordB>=0x21)&&(wordB<=0x40)){
			wordB = space;
		}
		else if((wordB>=91)&&(wordB<=96)){	
			wordB = space;
		}
		else if((wordB>=123)&&(wordB<=126)){	
			wordB = space;
		}
		else if((wordB>=65)&&(wordB<=90)){	
			wordB = wordB+32;
		}
		else if((wordB>=0)&&(wordB<=32)){
		}
		fprintf(fpb, "%c", wordB);
	}
	printf("\n");
	fclose(fpa);
	fclose(fpb);

	fpb = fopen("usethisfile.txt", "r");
	
	while((wordA=getc(fpb)) != EOF){
		printf("%c", wordA);
	}
	printf("\n");
	fclose(fpb);
	return 0;
}
