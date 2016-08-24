#include <stdio.h>

void store_dicdata (char* filename, char eng[][256], char jpn[][256], int size)
{
	FILE* fp=NULL;
	int i=0;
	
	if((fp=fopen(filename,"w"))==NULL){
		printf("配列をファイルに出力するのに失敗しました。\n");
		return;
	}
	
	for(i=0;i<size;i++)
		fprintf(fp,"%s %s\n", eng[i],jpn[i]);
	
	fclose(fp);
	printf("配列をファイルに出力するのに成功しました。\n");
	
	return;
}

int main (void)
{
	int i=0;
	char eng[3][256]={"aaa","bbb","ccc"};
	char jpn[3][256]={"あああ","いいい","ううう"};
	
	store_dicdata("out1.txt",eng,jpn,3);
	
	return 0;
}
