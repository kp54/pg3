#include <stdio.h>
#include <stdlib.h>

extern char menu_list[16][128];
extern int print_menu(void);

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
