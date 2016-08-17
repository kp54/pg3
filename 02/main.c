#include <stdio.h>

extern int load_dicdata(char*, char [][256], char [][256]);
extern void print_array(char [][256], int);

int main (void)
{
	int i=0;
	int count1=0;
	char eng[20][256];
		for(i=0;i<20;i++) eng[i][0]='\0';
	char jpn[20][256];
		for(i=0;i<20;i++) jpn[i][0]='\0';
	
	count1=load_dicdata("dicdata.txt",eng,jpn);
	
	if(count1==-1){
		printf("読み込み失敗\n");
		return 1;
	}else{
		printf("読み込み成功\n");
		printf("単語数 %d個\n", count1);
		print_array(eng,count1);
		print_array(jpn,count1);
	}
	
	return 0;
}
