#include<stdio.h>

void anchword()

int main(void){

	FILE *fpr *fpw;
	char word;
	int i=0, count[26]={0};

	fpr = fopen("usethisfile.txt", "r");	

	while(word=fgetc(fpr) != EOF){
		if(word[i] >= 'a' && word[i] <= 'z'){
			count[word[i]-97]++;
		}
		else if(word[i] >= 'A' && word[i] <= 'Z'){
			count[word[i]+32-97]++;
		}
	}
	
	fpw = fopen("countone.txt", "w");
	
	for(i=0; i<26; i++){
		//printf("%c : %d times \n", i+97, count[i]);
		fprintf(fpw, "%c : %d\n", i, count[i]);
	}
	fclose(fpb);
	
	return 0;
}
	//fp = fopen("Gutenberg.txt", "r");	
