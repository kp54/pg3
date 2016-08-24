#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "node2.h"

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
