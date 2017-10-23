#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>

void serve_data(float *serve){

	int i;
	FILE *fp;

	fp = fopen("gauss_plotdata.txt", "w");
	if (fp == NULL)
        {
        	printf("ファイルオープンエラー\n");
                return;
        }	
	for(i=0; i<100; i++){
		fprintf(fp, "%d %lf\n", i+1, serve[i]);
	}
	printf("serve data\n");
	fclose(fp);	

	return;
}
