#include<stdio.h>
#include<string.h>
#include <stdlib.h>

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
		printf("Can not find textfile");
		return;
	}
	int n[2]={};	
	float *x;

	for(i=0; i<2; i++){
		fgets(buffer, 255, fp);
		sscanf(buffer, "%d", &n[i]);
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
	
	for(i=0; i<n[0]; i++){
		for(j=0; j<n[1]; j++){
			printf("%f\t", a[i][j]);
		}	
		printf("\n");
	}

	for(i=0; i<n[0]; i++){
		printf("%f\n", b[i]);
	}

	float sum;

	for(i=0; i<n[1]; i++){
		x[i] = 0.0;
	}

	do{
		k++;
		com[1] = com[0];
		for(i=0;i<n[0];i++){
			sum=0.0;
			
			for(j=0;j<n[1];j++){
				if(j==i) continue;
				sum+=a[i][j]*x[j];
			}
			
			x[i]=(b[i]-sum)/a[i][i];
			com[0] = x[i]; 
		}
		printf("part%d: x0=%.3lf\tx1=%.3lf\tx2=%.3lf\tx3=%.3lf\n",k ,x[0],x[1],x[2],x[3]);

        }while(com[1] != com[0]);	
	 
	for(i=0; i<n[0]; i++){        /* 各データ配列のメモリを解放 */
                 free(a[i]);
	}
        free(a);	
	free(b);
	free(x);

	return 0;
}