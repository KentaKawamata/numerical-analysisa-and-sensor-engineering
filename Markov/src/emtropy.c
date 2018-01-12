#include<stdio.h>
#include<math.h>

void emtropyone(int sum){

	FILE *fp;
	double H=0, em=0, digit[27]={0};
	int i=0, num;
	char line[50]={}, word;

	fp = fopen("countdata/fileone.txt", "r");

	while(fgets(line, 50, fp) != NULL){
		if(i>26) break;
		sscanf(line, "%c %d", &word, &num);
		digit[i] = num;
		i++;
	}
	fclose(fp);

	for(i=0; i<27; i++){
		em = digit[i]/sum;
		H = H - (em*log2(em));
	}
	printf("H = %f\n", H);
	return;
}

void emtropytwo(int sum){

	FILE *fp;
	double digit[729]={0}, H=0, em=0;
	int i=0, num;
	char line[10]={}, word[10];

	fp = fopen("countdata/filetwo.txt", "r");
	
	while(fgets(line, 10, fp) != NULL){
		if(i>729) break;
		sscanf(line, "%s %d", word, &num);
		digit[i] = num;
		i++;
	}
	fclose(fp);
	i=0;
	while(digit[i]!=0){
		em = digit[i]/sum;
		H = H - (em*log2(em));
		i++;
	}
	printf("H = %f\n", H);
	return;
}

void emtropythree(int sum){

	FILE *fp;
	double digit[19683]={0}, H=0, em=0;
	int i=0, num;
	char line[10]={}, word[10];

	fp = fopen("countdata/filethree.txt", "r");
	
	while(fgets(line, 10, fp) != NULL){
		if(i>19683) break;
		sscanf(line, "%s %d", word, &num);
		digit[i] = num;
		i++;
	}
	fclose(fp);
	i=0;
	while(digit[i]!=0){
		em = digit[i]/sum;
		H = H - (em*log2(em));
		i++;
	}
	printf("H = %f\n", H);
	return;
}

void emtropy(void){

	FILE *fp;
	int count=0;
	fp = fopen("usethisfile.txt", "r");

	while(fgetc(fp)!=EOF){
		count++;
	}
	printf("%d\n", count);
	fclose(fp);
	printf("-------------start chalculate--------------\n");
	emtropyone(count);
	emtropytwo(count);
	emtropythree(count);

	return;
}
