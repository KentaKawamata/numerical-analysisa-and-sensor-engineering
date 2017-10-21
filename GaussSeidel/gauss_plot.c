#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>

int main(void)
{
	char buffer[256];
	char tok[] = "	";	
	char *cor;
	float **a;
	float *b;
	float com[2]={0, 0};
	int i=0, j=0, k=0, N;
	FILE *fp;

	fp = fopen("gauss_dataset.txt", "r");

	if(fp == NULL){
		printf("Can not find textfile\n");
		return 0;
	}
	int n[2]={};	
	float *x;

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
	
	i=j=0;
	while((fgets(buffer, 255, fp)) != NULL){		
		cor = strtok(buffer, tok);
		while(cor != NULL){
			sscanf(cor, "%f\t", &a[i][j]);
			j++;
			cor = strtok(NULL, tok);
		}
		i++;
		j=0;
	}	
	fclose(fp);

	for(i=0; i<n[0]; i++){
		b[i] = a[i][n[1]];
	}
	
	printf("行列A= [\n");
	for(i=0; i<n[0]; i++){
		printf("\t[ ");
		for(j=0; j<n[1]; j++){
			printf("%.4lf", a[i][j]);
			if(j == n[1]-1){
				printf("  ],");
			}
			else{
				printf("\t");
			}
		}	
		if(i == n[0]-1){
			printf("\t]");
		}
		printf("\n\n");
	}

	printf("行列B= [\n");
	for(i=0; i<n[0]; i++){
		printf("\t[ %.4lf ],", b[i]);
		if(i == n[0]-1){
			printf("\t]");
		}
		printf("\n\n");
	}

	float sum=0;

	/* 収束判定 */
	for(i=0; i<n[0]; i++){
		for(j=0; j<n[1]; j++){
			if(i != j){
				sum += a[i][j];
			}
		}	
		if(fabsf(a[i][i]) <= fabsf(sum)){
			printf("狭義対角優位行列ではないため, 収束しない可能性(%d列目)\n", i+1);
		}
		sum = 0;
	}
	printf("狭義対角優位行列より, 収束可能性\n");

	sum = 0;
	float serve[100]={}; 

	for(i=0; i<n[1]; i++){
		if(i == 1){
			x[i] = 1.0;
		}
		x[i] = 0.0;
		serve[i] = 0;
	}

	do{
		k++;
		com[1] = com[0];
		printf("part%d:\t", k);
		for(i=0;i<n[0];i++){
			sum=0.0;
			
			for(j=0;j<n[1];j++){
				if(j==i) continue;
				sum+=a[i][j]*x[j];
			}
			x[i]=(b[i]-sum)/a[i][i];
			com[0] = x[i]; 
			printf("x%d=%.4lf\t", i+1, x[i]);
			if(i == n[0]-1){
				printf("\n");
			}
		}
		serve[k-1] = x[0];
		if(k >= 100){
			printf("収束せず\n");
			k = 101;
			break;
		}
        }while(fabsf(com[1] - com[0]) > 0.0001);	

	if(k!=101){
	printf("収束に要した回数 : %d\n", k);
	}
 
	for(i=0; i<n[0]; i++){     
                free(a[i]);
	}
        free(a);	
	free(b);
	free(x);
	
	fp = fopen("gauss_plotdata.txt", "w");
	if (fp == NULL)
        {
        	printf("ファイルオープンエラー\n");
                return 0;
        }	
	for(i=0; i<100; i++){
		fprintf(fp, "%d %lf\n", i+1, serve[i]);
	}
	printf("serve data\n");
	fclose(fp);	

	return 0;
}
