#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void){
	FILE *fp;
	char word[256]={}, three[5000][3]={};
	int number[5000]={0}, i=0, j=0;

	fp = fopen("usethisfile.txt", "w");

	while(fgets(word, 256, fp)!=NULL){
		while(word[i]!=EOF){
			do{
				if((three[j][0]==word[i]&&three[j][1]==word[i+1]) && three[j][2]==word[i+2]){

					number[j]++;
					break;
				}
				else if(three[j][0]==" "){
					three[j][0] = word[i];
					three[j][1] = word[i+1];
					three[j][2] = word[i+2];
					three[j][3]++;
					if(isalpha(word[i])==0){
						three[j][0]=' ';
					}
					if(isalpha(word[i+1])==0){
						three[j][1]=' ';
					}
					if(isalpha(word[i+2])==0){
						three[j][2]=' ';
					}
					break;
				}
			}while(three[j++][0] != 0);
			i++;
		}
	}

	fp = fopen("filethree.txt", "w");
	
	i++;
	while(number[i]!=0){
		fprintf(fp, "%d%d%d %d", three[i][0], three[i][1], three[i][2], number[i]);
		i++;
	}
	fclose(fp);

	return 0;
}

