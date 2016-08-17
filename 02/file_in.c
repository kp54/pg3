#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_dicdata (char* filename, char e[][256], char j[][256])
{
	int cnt=0;
	char jp[256]={'\0'};
	char en[256]={'\0'};
	FILE* fp=NULL;
	
	if((fp=fopen(filename,"r"))==NULL) return -1;
	
	while(fscanf(fp,"%s %s",en,jp)!=EOF){
		strcpy(e[cnt],en);
		strcpy(j[cnt],jp);
		cnt++;
	}
	
	fclose(fp);
	
	while((e[cnt]=="")&&(j[cnt]=="")) cnt--;
	
	return cnt;
}

void print_array(char a[][256], int n)
{
	int i=0;
	
	printf("2次元配列の標準出力-------------\n");
	
	for(i=0;i<n;i++)
		printf("[%2d] = %s\n", i,a[i]);
	
	printf("--------------------------------\n");
	
	return;
}
