#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char eng[256];
	char jpn[256];
	struct node* next;
} node;

void print_list (node* p)
{
	printf("%16p\t%8s\t%8s\t%16p\n", p,p->eng,p->jpn,p->next);
	if(p->next) print_list(p->next);
	return;
}

int main (void)
{
	node* init=(node*)malloc(sizeof(node));
	node* a=(node*)malloc(sizeof(node));
	node* b=(node*)malloc(sizeof(node));
	
	strcpy(init->eng,"");
	strcpy(init->jpn,"");
	init->next=a;
	
	strcpy(a->eng,"aaa");
	strcpy(a->jpn,"あああ");
	a->next=b;
	
	strcpy(b->eng,"bbb");
	strcpy(b->jpn,"いいい");
	b->next=NULL;
	
	printf("%-16s\t%-8s\t%-8s\t%-16s\n", "アドレス","eng","jpn","next");
	print_list(init);
	
	free(init);
	free(a);
	free(b);

	return 0;
}
