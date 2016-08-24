#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "node2.h"

extern int print_menu(void);
extern int load_dicdata(char*, char [][256], char [][256]);
extern void print_array(char [][256], int);

extern void print_list(node*);
extern node* create_node(char*, char*);
extern void concat_list(node*, node*);
extern void close_list(node*);

extern void print_tree(node2*);
extern node2* create_node2(char*, char*);
extern void insert_tree(node2*, node2*);
extern void close_tree(node2*);

extern void store_dicdata(char*, char [][256], char [][256],int);
extern void store_list(char*, node*);
extern void store_tree(char*, node2*);

int main(void)
{
	int i=0;
	int menu_num=0;
	int count1=-1;
	char eng[20][256];
		for(i=0;i<20;i++) eng[i][0]='\0';
	char jpn[20][256];
		for(i=0;i<20;i++) jpn[i][0]='\0';
	node* init=create_node("","");
	node2* root=NULL;
	
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
					if(count1==-1){
						printf("保存に失敗\n");
					}else{
						for(i=0;i<count1;i++)
							concat_list(create_node(eng[i],jpn[i]),init);
					}
					break;
					
				case 4:
					if(init->next){
						printf("%-16s\t%-8s\t%-8s\t%-16s\n", "アドレス","eng","jpn","next");
						print_list(init->next);
					}else{
						printf("標準出力する連結リストは存在しない\n");
					}
					break;
				
				case 5:
					if(count1==-1){
						printf("保存に失敗\n");
					}else{
						if(count1==0) break;
						root=create_node2(eng[0],jpn[0]);
						for(i=1;i<count1;i++)
							insert_tree(create_node2(eng[i],jpn[i]),root);
					}
					break;
				
				case 6:
					if(root){
						printf("%-16s\t%-8s\t%-8s\t%-16s\t%-16s\n", "アドレス","eng","jpn","left","right");
						print_tree(root);
					}else{
						printf("標準出力する二分木は存在しない\n");
					}
					break;
					
				case 7:
					if(0<count1) store_dicdata("out1.txt",eng,jpn,count1);
					if(init->next) store_list("out2.txt",init->next);
					if(root) store_tree("out3.txt",root);
					break;
					
				case 8:
					printf(">>未実装\n");
					break;
				
				case 9:
					if(init->next){
						close_list(init);
					}else{
						free(init);
						printf("削除する連結リストは存在しない\n");
					}
					
					if(root){
						close_tree(root);
					}else{
						printf("削除する二分木は存在しない\n");
					}
					
					printf(">>終了\n");
					
					exit(EXIT_SUCCESS);
					break;
					
				default:
					printf("値が不正です\n");
					break;
		}
		
		printf("\n");
	}
	
	return 0;
}
