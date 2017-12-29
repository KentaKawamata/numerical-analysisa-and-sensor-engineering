#include<stdio.h>

int main(void){

	FILE *fp;
	int three[15625][4] = {{0}}, i=0, j=0;
	char word[256]={};

	fp = fopen("test.txt", "r");

	
	while(fgets(word, 256, fp) != NULL){
		while(word[i] != 0x00){
			do{
				if(((three[j][0]==word[i]) && (three[j][1]==word[i+1])) && (three[j][2]==word[i+2])){
					if(word[j+1]==0x00||word[j+2]==0x00){
						break;
					}
					three[j][3]++;
					break;
				}
				else if(three[j][0]==0){
					if((isalpha(word[j])==0)&&(word[j]!=" ")){
						break;
					}
					if((isalpha(word[j+1])==0)&&(word[j+1]!=" ")){
						break;
					}
					if((isalpha(word[j+2])==0)&&(word[j+2]!=" ")){
						break;
					}
					three[j][0] = word[i];
					three[j][1] = word[i+1];
					three[j][2] = word[i+2];
					three[j][3]++;
					break;
				}
			}while(three[j++][0] != 0);
			j=0;
			i++;
		}
		i=0;
		//printf("********check********\n");
	}

	fclose(fp);
	fp = fopen("filethree.txt", "w");

	i=0;
	while(three[i][0] != 0){
		fprintf(fp, "%c%c%c\ %d\n", three[i][0], three[i][1], three[i][2], three[i][3]);
		i++;
	}
	fclose(fp);
	
	return 0;
}
