#include<stdio.h>
#include<string.h>

int main(void)
{
	int n, m;

	

	float a[3][3]={{5,1,1},{1,4,1},{2,1,3}};
	float x[3]={0,0,0},b[3]={10,12,13}; // 初期値xはすべて0とした
	float sum;
	float com[2]={0, 0}; 
	int i, j, k, N;

	do{
		com[1] = com[0];
		for(i=0;i<3;i++){
			sum=0.0;
			
			for(j=0;j<3;j++){
				if(j==i) continue;
				sum+=a[i][j]*x[j];
			}
			
			x[i]=(b[i]-sum)/a[i][i];
			com[0] = x[i]; 
		}
		printf("part%d: x0=%.3lf\tx1=%.3lf\tx2=%.3lf\tx3=%.3lf\n",k ,x[0],x[1],x[2],x[3]);

	}while(com[1] != com[0]);

	return 0;
}
