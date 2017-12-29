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
		if(one[i] == 0x5f) one[i] = 0x20;
		fprintf(fpw, "%c", one[i]);
		i++;
	}
	fclose(fpw);
	return;
}

void randomtwo(int sum, FILE *fp){

	FILE *fpw;
	int i=0, j=0, k=0, ran=0, A=0x00;
	char two[200]={}, ch[2]={};

	for(i=0; i<100; i++){
		ran = rand() % sum + 1;
		rewind(fp);

		if(i==0){
			for(j=0; j<ran; j++){
				ch[0] = fgetc(fp);

				if(j==ran-1){
					ch[0] = fgetc(fp);
					ch[1] = fgetc(fp);

					two[k] = ch[0];
					two[k+1] = ch[1];
					A = two[k+1];
					k+=2;
					break;
				}
			}
		}
		else{
			j=0;
			while((ch[0]=fgetc(fp)) != EOF){
				if(ch[0]==A && j>ran){
					ch[0] = fgetc(fp);
					ch[1] = fgetc(fp);
								
					two[k] = ch[0];
					two[k+1] = ch[1];
					A = two[k+1];
					k+=2;
					break;
				}
				j++;
			}
		}
	}

	fpw = fopen("randomdata/randomtwo.txt", "w");
	i=0;
	while(i<100){
		if(two[i] == 0x5f) two[i] = 0x20;
		if(two[i+1] == 0x5f) two[i+1] = 0x20;
		fprintf(fpw, "%c%c", two[i], two[i+1]);
		i+=2;
	}
	fclose(fpw);
	return;
}

void randomthree(int sum, FILE *fp){

	FILE *fpw;
	int i=0, j=0, k=0, ran=0, A=0x00;
	char three[300]={}, ch[3]={};

	for(i=0; i<100; i++){
		ran = rand() % sum + 1;
		rewind(fp);

		if(i==0){
			for(j=0; j<ran; j++){
				ch[0] = fgetc(fp);

				if(j==ran-1){
					ch[0] = fgetc(fp);
					ch[1] = fgetc(fp);
					ch[2] = fgetc(fp);
								
					three[k] = ch[0];
					three[k+1] = ch[1];
					three[k+2] = ch[2];
					A = three[k+2];
					k+=3;
					break;
				}
			}
		}
		else{
			j=0;
			while((ch[0]=fgetc(fp)) != EOF){
				if(ch[0]==A && j>ran){
					ch[0] = fgetc(fp);
					ch[1] = fgetc(fp);
					ch[2] = fgetc(fp);
								
					three[k] = ch[0];
					three[k+1] = ch[1];
					three[k+2] = ch[2];
					A = three[k+2];
					k+=3;
					break;
				}
				j++;
			}
		}
	}

	fpw = fopen("randomdata/randomthree.txt", "w");
	i=0;
	while(i<100){
		if(three[i] == 0x5f) three[i] = 0x20;
		if(three[i+1] == 0x5f) three[i+1] = 0x20;
		if(three[i+2] == 0x5f) three[i+2] = 0x20;
		fprintf(fpw, "%c%c%c", three[i], three[i+1], three[i+2]);
		i+=3;
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
	rewind(fp);
	randomtwo(count, fp);
	rewind(fp);
	randomthree(count, fp);
	
	fclose(fp);
	return;
}
