#include<stdio.h>
#include<math.h>

int main(void){

	FILE *fp;
	char word, words[10], www[7];
	double digit[27]={0}, space, numberw=0, H=0, em=0;
	int count=0, i=0, k=0, nu=0;
	int number=0, ntwo=0, nthree=0;

	fp = fopen("usethisfile.txt", "r");

	while(fgetc(fp) != EOF){
		number++;
		if((number+1)%2==0){
			ntwo++;
		}
		else if((number+1)%3==0){
			nthree++;
		}
	}
	fclose(fp);

	fp = fopen("fileone.txt", "r");

	//while(fscanf(fp, "%c %d", word, &nu) != EOF){
	while(fgets(words, 10, fp) != NULL){
		if(k>25){
			break;
		}
		sscanf(words, "%c %d", &word, &nu);
		/*number : 全文字数の合計*/
		numberw = numberw + nu;
		digit[k] = nu;
		//printf("%d %f %d\n", nu, digit[k], k);
		k+=1;
	}
	fclose(fp);

	space = number - numberw;
	digit[26] = space;

	//printf("%f\n", number);
	for(i=0; i<27; i++){
		em = digit[i]/number;
		H = H - (em*log2(em));
		//printf("em = %f  H = %f\n", em, H);
	}

	printf("H = %f\n", H);

	fp = fopen("filepair.txt", "r");

	k=0;
	double digittwo[625]={0};
	while(fgets(words, 10, fp) != NULL){
		if (k>625){
			break;
		}
		sscanf(words, "%s %d", www, &nu);
		/*number : 全文字数の合計*/
		//numberw = numberw + nu;
		digittwo[k] = nu;
		//printf("%f %d\n", digittwo[k], k);
		k++;
	}

	H=0;
	i=0;
	while(digittwo[i]!=0){
		em = digittwo[i]/ntwo;
		H = H - (em*log2(em));
		//printf("em = %f  H = %f i = %d\n", em, H, i);
		i++;
	}
	fclose(fp);
	printf("H = %f\n", H);


	fp = fopen("filethree.txt", "r");
	k=0;
	double digitthree[15625]={0};
	while(fgets(words, 10, fp) != NULL){
		if (k>15625){
			break;
		}
		sscanf(words, "%s %d", www, &nu);
		/*number : 全文字数の合計*/
		//numberw = numberw + nu;
		digitthree[k] = nu;
		//printf("%d %f %d\n", nu, digittwo[k], k);
		k++;
	}
	H=0;
	i=0;
	while(digitthree[i]!=0){
		em = digitthree[i]/nthree;
		H = H - (em*log2(em));
		printf("em = %f  H = %f i = %d\n", em, H, i);
		i++;
	}
	fclose(fp);
	printf("H = %f\n", H);

	return 0;
}
