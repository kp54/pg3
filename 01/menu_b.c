#include <stdio.h>
#include <stdlib.h>

char menu_list[16][128]={
		"1. ファイルの読み込み",
		"2. 配列の内容を標準出力",
		"3. 連結リストに保存",
		"4. 連結リストの内容を標準出力",
		"5. 二分木に保存",
		"6. 二分木の内容を標準出力",
		"7. ファイルの書き出し",
		"8. オリジナル機能",
		"9. 終了",
	};

int print_menu(void)
{
	int menu_num=9;
	
	int i=0;
	
	for(;i<menu_num;i++)
		printf("%s\n",menu_list[i]);
	
	printf(">? ");
	scanf("%d",&menu_num);
	
	return menu_num;
}

int main(void)
{
	int menu_num=0;
	
	while(1){
		menu_num=print_menu();
		
		switch(menu_num){
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
					printf(">>%s\n",menu_list[menu_num-1]);
					break;
				
				case 9:
					printf(">>%s\n",menu_list[menu_num-1]);
					exit(EXIT_SUCCESS);
					break;
					
				default:
					printf("値が不正です\n");
		}
	}
	
	return 0;
}
