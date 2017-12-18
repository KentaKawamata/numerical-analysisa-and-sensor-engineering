#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(void){

	char word[] = "ab cdef ghi jklmn";
	char pair[676][2]={{'\0'}};
	char c;
	int i=0, j=0, count[676]={}, A, B, C, D;

	for(i=0; i<676; i++){
		//pair[i][0]='\0';
		//pair[i][1]='\0';
		count[i]=0;
	}
	printf("%s\n", word);

	while(word[i] != '\0'){
		for(j=0; j<676; j++){
			A = strcmp(word[i],pair[j][0]);
			B = strcmp(word[i+1],pair[j][1]);
				
			C = strcmp(word[i],' ');
			D = strcmp(word[i+1],' ');
			
			if((A==0)&&(B==0)){
				count[j]++;
				break;
			}
			else if((C==0)&&(D==0)){
				if((isalpha(pair[j][0])==0)&&(isalpha(pair[j][1])==0)){
					strcpy(pair[j][0], word[i]);
					strcpy(pair[j][1], word[i+1]);
					count[j]++;
					break;
				}
			}
		}
		i++;
	}
	i=0;
			
	while(pair[i][0]!='\0'){
		printf("%c%c, %d\n", pair[i][0], pair[i][1], count[i]);
		i++;
	}
	return 0;
}
