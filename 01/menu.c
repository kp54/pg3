#include <stdio.h>

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
