#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

extern void print_list(node*);
extern node* create_node(char*, char*);
extern void concat_list(node*, node*);
extern void close_list(node*);

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

void store_list0(FILE* fp, node* list)
{
	fprintf(fp,"%s %s\n", list->eng,list->jpn);
	
	if(list->next) store_list0(fp, list->next);
	
	return;
}

void store_list(char* filename, node* list)
{
	FILE* fp=NULL;
	
	if((fp=fopen(filename,"w"))==NULL){
		printf("連結リストをファイルに出力するのに失敗しました。\n");
		return;
	}
	
	if(list) store_list0(fp,list);
	
	fclose(fp);
	printf("連結リストをファイルに出力するのに成功しました。\n");
	
	return;
}

int main (void)
{
	int i=0;
	char eng[3][256]={"aaa","bbb","ccc"};
	char jpn[3][256]={"あああ","いいい","ううう"};
	node* init=create_node("","");
	for(i=0;i<3;i++)
		concat_list(create_node(eng[i],jpn[i]),init);
	
	printf("[連結リスト]\n");
	printf("%-16s\t%-8s\t%-8s\t%-16s\n", "アドレス","eng","jpn","next");
	print_list(init);
	
	store_dicdata("out1.txt",eng,jpn,3);
	store_list("out2.txt",init);
	
	close_list(init);
	
	return 0;
}
