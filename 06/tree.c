#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node2.h"

node2* create_node2 (char* eng, char* jpn)
{
	node2* p=(node2*)malloc(sizeof(node2));
	
	strcpy(p->eng,eng);
	strcpy(p->jpn,jpn);
	p->left=NULL;
	p->right=NULL;
	
	return p;
}

void print_tree(node2* p)
{
	printf("%16p\t%8s\t%8s\t%16p\t%16p\n", p,p->eng,p->jpn,p->left,p->right);
	
	if(p->left) print_tree(p->left);
	if(p->right) print_tree(p->right);
	
	return;
}

void insert_tree(node2* p, node2* tree)
{
	if(!tree->left){
		tree->left=p;
	}else{
		insert_tree(p,tree->left);
	}
	
	return;
}

void close_tree(node2* tree)
{
	if(tree->left) close_tree(tree->left);
	if(tree->right) close_tree(tree->right);
	
	free(tree);
	
	return;
}
