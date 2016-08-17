#include <stdio.h>
#include <stdlib.h>

extern int print_menu(void);
extern int load_dicdata(char*, char [][256], char [][256]);
extern void print_array(char [][256], int);

int main(void)
{
	int i=0;
	int menu_num=0;
	int count1=0;
	char eng[20][256];
		for(i=0;i<20;i++) eng[i][0]='\0';
	char jpn[20][256];
		for(i=0;i<20;i++) jpn[i][0]='\0';
	
	while(1){
		menu_num=print_menu();
		
		switch(menu_num){
				case 1:
					count1=load_dicdata("dicdata.txt",eng,jpn);
					if(count1==-1){
						printf("読み込み失敗\n");
					}else{
						printf("読み込み成功\n");
						printf("単語数 %d個\n", count1);
					}
					break;
					
				case 2:
					print_array(eng,count1);
					print_array(jpn,count1);
					break;
					
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
					printf(">>未実装\n");
					break;
				
				case 9:
					printf(">>終了\n");
					exit(EXIT_SUCCESS);
					break;
					
				default:
					printf("値が不正です\n");
		}
	}
	
	return 0;
}
