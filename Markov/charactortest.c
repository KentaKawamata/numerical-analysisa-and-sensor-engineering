#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

main(void)
{
	FILE *fp;
	int c;
	struct tangohyo
	{
		char tango[100];	/* 単語 */
		int count;	/* カウント */
	};
	struct tangohyo a[100];
	char moji[31];	/* 文字 */
	int i,n=0, j=0 ,m;

	/* ファイルの読み込み */
	if((fp=fopen("test.txt","r"))==NULL){
		printf("File not open...\n");
		exit(1);
	}

	/* 判断 */
	while((c=fgetc(fp)) != EOF){
		/* cがアルファベットなら */
		if(isalpha(c)){
			moji[j] = c;
			j++;
		}
		else{
			moji[j]='\0';
			for(m=0;m < n;m++){
				//単語が既に登録されてたとき
				if(strcmp(a[m].tango,moji)==0){
					a[m].count++;
					break;
				}
			}
			if(m == n){//登録されてなかった時
				(strcpy(a[n].tango,moji));
				a[n].count = 1;
				n++;
			}
			j=0;
		}
	}
	fclose(fp);

	/*　ファイルに出力　*/
	fp = fopen("wordtestB.txt","w");
	for(i=0;i < n;i++){		
		printf("%s	%d\n",a[i].tango,a[i].count);
		fprintf(fp,"%s	%d\n",a[i].tango,a[i].count);
	}
	fclose(fp);
	
	return 0;
}
