#include<stdio.h>
#include<math.h>

float gauss(float **a, float *b, float *x, float *serve, int *n){

	int i, j, k=0;
	float com[2]={0, 0}, sum;

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
			break;
		}
	}while(fabsf(com[1] - com[0]) > 0.0001);
	
	if(k!=101){
		printf("収束に要した回数 : %d\n", k);
	}
	return;
}

