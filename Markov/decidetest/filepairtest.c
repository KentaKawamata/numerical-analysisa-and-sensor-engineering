#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(void){

	FILE *fpr, *fpwa, *fpwb, *fpwc, *fpwd;
	int one[26][2] = {{0}}, two[625][3] = {{0}}, three[15625][4] = {{0}}, i=0, j=0, k=0, m=0, n=0, DA=0, DB=0, DC=0;
	char word[256]={};
	struct words{
		char tango[256];
		int count;
	};
	struct words charactor[256];
	char moji[256];

	fpr = fopen("usethisfile.txt", "r");

	for(i=0; i<256; i++){
		charactor[i].count=0;
	}
	for(i=0; i<26; i++){
		one[i][0]=i+97;
		one[i][1]=0;
	}
	i=0;
	
	while(fgets(word, 256, fpr) != NULL){
		while(word[i] != 0x00){
			if(word[i] >= 'a' && word[i] <= 'z'){
				DA=1;
			}
			if(word[i+1] >= 'a' && word[i+1] <= 'z'){
				DB=1;
			}
			if(word[i+2] >= 'a' && word[i+2] <= 'z'){
				DC=1;
			}
			if(DA == 1){
				one[word[i]-97][1]++;
			}
			if(DA == 1 && DB == 1){
				do{
					if((two[j][0]==word[i]) && (two[j][1]==word[i+1])){
						two[j][2]++;
						break;
					}
					else if(two[j][0]==0){
						two[j][0] = word[i];
						two[j][1] = word[i+1];
						two[j][2]++;
						break;
					}
				}while(two[j++][0] != 0);
			}
			j=0;
			if((DA==1&&DB==1) && (DC==1)){
				do{
					if(((three[j][0]==word[i]) && (three[j][1]==word[i+1])) && (three[j][2]==word[i+2])){
						three[j][3]++;
						break;
					}
					else if(three[j][0]==0){
						three[j][0] = word[i];
						three[j][1] = word[i+1];
						three[j][2] = word[i+2];
						three[j][3]++;
						break;
					}
				}while(three[j++][0] != 0);
			}
			if(isalpha(word[i])){
				moji[k] = word[i];
				k++;
			}
			if((isalpha(word[i])==0)&&word[i-1]!=0x20){
				moji[k]='\0';
				for(m=0; m<n; m++){
					if(strcmp(charactor[m].tango, moji)==0){
						charactor[m].count++;
						break;
					}
				}
				if(m == n){
					strcpy(charactor[n].tango, moji);
					charactor[n].count = 1;
					n++;
				}
				k=0;
			}
			i++;
			j=0;
			DA=0;
			DB=0;
			DC=0;
		}
		k=0;
		i=0;
		printf("********check********\n");
	}

	fclose(fpr);
	fpwa = fopen("filepair.txt", "w");
	fpwb = fopen("filethree.txt", "w");
	fpwc = fopen("filecharactor.txt", "w");
	fpwd = fopen("fileone.txt", "w");

	for(i=0; i<26; i++){
		fprintf(fpwd, "%c:%d\n", one[i][0], one[i][1]);
	}
	fclose(fpwd);	

	i=0;
	while(two[i][0] != 0){
		//printf("%c%c : %d\n", two[i][0], two[i][1], two[i][2]);
		fprintf(fpwa, "%C%C:%d\n", two[i][0], two[i][1], two[i][2]);
		i++;
	}
	fclose(fpwa);

	i=0;
	while(three[i][0] != 0){
		fprintf(fpwb, "%c%c%c:%d\n", three[i][0], three[i][1], three[i][2], three[i][3]);
		i++;
	}
	fclose(fpwb);
	
	i=0;
	while(charactor[i].count != 0){
		printf("%s %d\n", charactor[i].tango, charactor[i].count);
		fprintf(fpwc, "%s:%d\n", charactor[i].tango, charactor[i].count);
		i++;
	}
	fclose(fpwc);

	return 0;
}
