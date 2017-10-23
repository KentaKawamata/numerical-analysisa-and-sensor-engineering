#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>

int main()
{
	float **a, *b, *x, *serve[100];
	int i, j, n[2]={};
	char buffer[256];
	char tok[]="	";
	char *cor;
	FILE *fp;

	fp = fopen("gauss_dataset.txt", "r");
	if(fp == NULL){
		printf("Can not find textfile\n");
		return 0;
	}

	for(i=0; i<2; i++){
		fgets(buffer, 255, fp);
		sscanf(buffer, "%d", &n[i]);
		if(n[i] < 1 || n[i] > 10){
			printf("行列は1*1 ~ 10*10行列にて定義すること\n");
			return 0;
		}
	}
	
	a = (float **)malloc(sizeof(float *) * n[0]);
	b = (float *)malloc(n[0] * sizeof(float *));	
	x = (float *)malloc(n[1] * sizeof(float *));

	for(i=0; i<n[0]; i++){
		a[i] = (float *)malloc((n[1]+1) * sizeof(float));
	}

	for(i=0; i<n[0]; i++){
		fgets(buffer, 255, fp);
		cor = strtok(buffer, tok);
		for(j=0; j<n[1]+1; j++){
			sscanf(cor, "%f\t", &a[i][j]);
			cor = strtok(NULL, tok);
		}
	}
	fclose(fp);	

	substitute_B(a, b, n);
	express_matrix(a, b, n);
	judgment_matrix(a, n);
	substitute_X(x, n);	
	substitute_serve(serve);	
	gauss(a, b, x, serve, &n);
	serve_data(serve);
	 
	for(i=0; i<n[0]; i++){     
                free(a[i]);
	}
        free(a);	
	free(b);
	free(x);

	return 0;
}
