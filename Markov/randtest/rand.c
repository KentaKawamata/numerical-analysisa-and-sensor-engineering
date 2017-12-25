#include<stdio.h>
#include<stdlib.h>

int main(void){

	FILE *fpra, *fpwa, *fpwb, *fpwc;
	int count=0, ran=0;
	int repeat=100, i=0, j=0, k=0, number=0;
	char one[100]={}, ch, hcc[2]={}, hc[3]={}, A='\0', two[200]={}, three[300]={};

	fpra = fopen("usethisfile.txt", "r");

	while((ch=fgetc(fpra)) != EOF){
		if(isalpha(ch)!=0){
			count++;
		}
	}
	printf("*****end count*****\n");

	printf("count = %d\n", count);

	/* repeat回繰り返し値を格納 */
	for(i=0; i<repeat; i++){
		ran = rand() % count+1;
		rewind(fpra);
		for(k=0; k<=ran-1; k++){
			ch = fgetc(fpra);
		
			if((k == ran-1) && (isalpha(ch))){
				one[j] =ch;
				j++;
				break;
			}
			else if(isalpha(ch)==0){
				k--;
			}
		}
	}

	j=0;
	for(i=0; i<repeat+100; i++){
		ran = rand() % count+1;
		//printf("ran = %d\n", ran);
		rewind(fpra);
		for(k=number; k<ran; k++){
			hcc[0] = fgetc(fpra);
			
			if(hcc[0]==A){
				hcc[1] = fgetc(fpra);
								
				two[j] = hcc[0];
				two[j+1] = hcc[1];
				printf("two[j+1] = %c %d\n", two[j+1], j);
				A = two[j+1];
				number=k+1;
				j+=2;
				break;
			}
			if(k==ran-1){
				printf("***first***\n");
				hcc[1] = fgetc(fpra);

				two[j] = hcc[0];
				two[j+1] = hcc[1];
				printf("first two[j+1] = %c %d\n", two[j+1], j);
				A = two[j+1];
				number=k+1;
				j+=2;
				break;
			}
		}
	}

	j=0;
	number=0;
	for(i=0; i<repeat+200; i++){
		ran = rand() % count+1;
		rewind(fpra);
		for(k=number; k<ran; k++){
			hc[0] = fgetc(fpra);
			
			if(hc[0]==A){
				hc[1] = fgetc(fpra);
				hc[2] = fgetc(fpra);
								
				three[j] = hc[0];
				three[j+1] = hc[1];
				three[j+2] = hc[2];
				printf("three[j+2] = %c %d\n", three[j+2], j);
				A = three[j+2];
				number=k+1;
				j+=3;
				break;
			}
			else if(k==ran-1){
				printf("***first***\n");
				hc[1] = fgetc(fpra);
				hc[2] = fgetc(fpra);

				three[j] = hc[0];
				three[j+1] = hc[1];
				three[j+2] = hc[2];
				printf("three[j+2] = %c %d\n", three[j+2], j);
				A = three[j+2];
				number=k+1;
				j+=3;
				break;
			}
		}
		if(j>=300){
			break;
		}
	}
	
	fclose(fpra);
	printf("*****end read*****\n");

	fpwa = fopen("randone.txt", "w");
	fpwb = fopen("randtwo.txt", "w");
	fpwc = fopen("randthree.txt", "w");

	i=0;
	while((isalpha(one[i]))!=0){
		//printf("%c", one[i]);
		fprintf(fpwa, "%c", one[i]);
		i++;
	}
	printf("\n");
	i=0;
	while(i<200){
		fprintf(fpwb, "%c", two[i]);
		printf("%c", two[i]);
		i++;
	}
	i=0;
	while(i<300){
		fprintf(fpwc, "%c", three[i]);
		//printf("%c%c%c", three[i][0], three[i][1], three[i][2]);
		i++;
	}
		
	printf("\n*****end write*****\n");
	fclose(fpwa);
	fclose(fpwb);
	fclose(fpwc);

	return 0;
}
