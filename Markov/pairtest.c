#include<stdio.h>

int main(void){
	char word[] = "abc de fg hijk ablmn";
	int two[625][3] = {{0}}, i=0, j=0, DA=0, DB=0;

	printf("%s\n", word);

	while(word[i] != 0x00){
		if(word[i] >= 'a' && word[i] <= 'z'){
			DA=1;
		}
		if(word[i+1] >= 'a' && word[i+1] <= 'z'){
			DB=1;
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
		i++;
		DA=0;
		DB=0;
	}

	i=0;
	while(two[i][0] != 0){
		printf("%c%c : %d\n", two[i][0], two[i][1], two[i][2]);
		i++;
	}

	return 0;
}
