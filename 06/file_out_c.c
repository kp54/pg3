#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "node2.h"

extern void print_list(node*);
extern node* create_node(char*, char*);
extern void concat_list(node*, node*);
extern void close_list(node*);

extern void print_tree(node2*);
extern node2* create_node2(char*, char*);
extern void insert_tree(node2*, node2*);
extern void close_tree(node2*);

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

void store_list0 (FILE* fp, node* list)
{
	fprintf(fp,"%s %s\n", list->eng,list->jpn);
	
	if(list->next) store_list0(fp, list->next);
	
	return;
}

void store_list (char* filename, node* list)
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

void store_tree0 (FILE* fp, node2* tree)
{
	fprintf(fp,"%s %s\n", tree->eng,tree->jpn);
	
	if(tree->left) store_tree0(fp,tree->left);
	if(tree->right) store_tree0(fp,tree->right);
	
	return;
}

void store_tree (char* filename, node2* tree)
{
	FILE* fp=NULL;
	
	if((fp=fopen(filename,"w"))==NULL){
		printf("二分木をファイルに出力するのに失敗しました。\n");
		return;
	}
	
	if(tree) store_tree0(fp,tree);
	
	fclose(fp);
	printf("二分木をファイルに出力するのに成功しました。\n");
	
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
	
	node2* root=create_node2(eng[0],jpn[0]);
	for(i=1;i<3;i++)
		insert_tree(create_node2(eng[i],jpn[i]),root);
	
	printf("[連結リスト]\n");
	printf("%-16s\t%-8s\t%-8s\t%-16s\n", "アドレス","eng","jpn","next");
	print_list(init);
	
	printf("[二分木]\n");
	printf("%-16s\t%-8s\t%-8s\t%-16s\t%-16s\n", "アドレス","eng","jpn","left","right");
	print_tree(root);
	
	store_dicdata("out1.txt",eng,jpn,3);
	store_list("out2.txt",init);
	store_tree("out3.txt",root);
	
	close_list(init);
	close_tree(root);
	
	return 0;
}
