#include<stdio.h>
#include<math.h>

void judgment_matrix(float **a, int *n){

	float sum=0;	
	int i, j;

	for(i=0; i<n[0]; i++){
		for(j=0; j<n[1]; j++){
			if(i != j){
				sum += a[i][j];
			}
		}	
		if(fabsf(a[i][i]) <= fabsf(sum)){
			printf("狭義対角優位行列ではないため, 収束しない可能性(%d列目)\n", i+1);
		}
		sum=0;
	}
	printf("狭義対角優位行列より, 収束可能性\n");
	return;
}

