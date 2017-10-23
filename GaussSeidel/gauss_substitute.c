#include<stdio.h>

void substitute_serve(float *serve){

	int i;
	for(i=0; i<100; i++){
		serve[i] = 0.0;
	}
	return;
}

void substitute_B(float **a, float *b, int *n){

	int i;
	
	for(i=0; i<n[0]; i++){
		b[i] = a[i][n[1]];
	}
	return;
}

void substitute_X(float *x, int *n){

	int i;

	for(i=0; i<n[1]; i++){
		if(i == 0){
			x[i] = 1.0;
		}
		x[i] = 0.0;
	}
	return;
}
