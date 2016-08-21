#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node2{
	char eng[256];
	char jpn[256];
	struct node2* left;
	struct node2* right;
} node2;

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

int main (void)
{
	int i=0;
	node2* root;
	node2* a[3];
	
	a[0]=create_node2("aaa","あああ");
	a[1]=create_node2("bbb","いいい");
	a[2]=create_node2("ccc","ううう");
	root=a[0];
	
	insert_tree(a[1],root);
	insert_tree(a[2],root);

	printf("%-16s\t%-8s\t%-8s\t%-16s\t%-16s\n", "アドレス","eng","jpn","left","right");
	print_tree(root);
		
	for(i=0;i<3;i++)
		free(a[i]);
	
	return 0;
}
