#include<stdio.h>

int main(void){
	char word[] = "abc de fg hilmnjk ablmn";
	int three[15625][4] = {{0}}, i=0, j=0, DA=0, DB=0, DC=0;

	printf("%s\n", word);

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
		j=0;
		i++;
		DA=0;
		DB=0;
		DC=0;
	}

	i=0;
	while(three[i][0] != 0){
		printf("%c%c%c : %d\n", three[i][0], three[i][1], three[i][2], three[i][3]);
		i++;
	}

	return 0;
}
