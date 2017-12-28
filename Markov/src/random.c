#include<stdio.h>
#include<stdlib.h>

void randomone(int sum, FILE *fp){

	FILE *fpw;
	int i=0, j=0, k=0, ran;
	char ch, one[100]={};

	for(i=0; i<100; i++){
		ran = rand() % sum+1;
		rewind(fp);
		for(j=0; j<=ran-1; j++){
			ch = fgetc(fp);
			if(j==ran-1){
				one[k] = ch;
				k++;
				break;
			}
		}
	}

	fpw = fopen("randomdata/randomone.txt", "w");
	i=0;
	while(i<100){
		fprintf(fpw, "%c", one[i]);
		i++;
	}
	fclose(fpw);
	return;
}


void randomword(void){

	FILE *fp;
	int count=0;

	fp = fopen("usethisfile.txt", "r");
	while(fgetc(fp) != EOF){
		count++;
	}
	rewind(fp);

	randomone(count, fp);
	
	fclose(fp);
	return;
}
