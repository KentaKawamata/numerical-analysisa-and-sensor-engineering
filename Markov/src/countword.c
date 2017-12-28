#include<stdio.h>
#include<ctype.h>

void countone(FILE *fp){

	FILE *fpw;
	int one[27][2]={{0}}, i=0;
	char word[256]={};

	one[26][0] = 0x20;
	while(fgets(word, 256, fp) != NULL){
		while(word[i] != 0x00){
			/*word[i]がスペースだった場合27カウント*/
			if(word[i] == 0x20){
				one[26][1]++;
			}
			/*アルファベットだった場合のカウント*/
			else if(isalpha(word[i])){
				one[word[i]-97][1]++;
			}
			i++;
		}
		i=0;
	}
	
	fpw = fopen("countdata/fileone.txt", "w");

	for(i=0; i<27; i++){
		if(i<=25){
			one[i][0] = 'a'+i;
		}
		fprintf(fpw, "%c %d\n", one[i][0], one[i][1]);
	}
	fclose(fpw);
	return;
}

void counttwo(FILE *fp){

	FILE *fpw;
	int two[729][3]={{0}}, i=0, j=0;
	char word[256]={};
	
	while(fgets(word, 256, fp) != NULL){
		while(word[i] != 0x00){
			do{
				if((two[j][0]==word[i]) && (two[j][1]==word[i+1])){
					two[j][2]++;
					break;
				}
				else if(two[j][0]==0){
					if((isalpha(word[i])==0)&&(word[i]!=0x20)){
						break;
					}
					else if((isalpha(word[i+1])==0)&&(word[i+1]!=0x20)){
						break;
					}
					two[j][0] = word[i];
					two[j][1] = word[i+1];
					two[j][2]++;
					break;
				}
			}while(two[j++][0] != 0);
			i++;
			j=0;
		}
		i=0;
	}

	fpw = fopen("countdata/filetwo.txt", "w");
	
	while(two[i][0] != 0){
		fprintf(fpw, "%c%c %d\n", two[i][0], two[i][1],  two[i][2]);
		i++;
	}
	fclose(fpw);
	
	return;
}


void countthree(FILE *fp){

	FILE *fpw;
	int three[15625][4] = {{0}}, i=0, j=0;
	char word[256]={};

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
					if((isalpha(word[i])==0)&&(word[i]!=0x20)){
						break;
					}
					else if((isalpha(word[i+1])==0)&&(word[i+1]!=0x20)){
						break;
					}
					else if((isalpha(word[i+2])==0)&&(word[i+2]!=0x20)){
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
	}
	fpw = fopen("countdata/filethree.txt", "w");

	while(three[i][0] != 0){
		fprintf(fpw, "%c%c%c %d\n", three[i][0], three[i][1], three[i][2], three[i][3]);
		i++;
	}
	fclose(fpw);
	
	return;
}

void countword(void){

	FILE *fp;

	fp = fopen("usethisfile.txt", "r");

	countone(fp);
	rewind(fp);
	counttwo(fp);
	rewind(fp);
	countthree(fp);
	rewind(fp);
	fclose(fp);
	
	return;
}
