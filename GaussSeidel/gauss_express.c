#include<stdio.h>

void express_matrix(float **a, float *b, int *n){

	int i, j;

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
}
