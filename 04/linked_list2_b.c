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

node* create_node(char* eng, char* jpn)
{
	node* p=(node*)malloc(sizeof(node));
	
	strcpy(p->eng,eng);
	strcpy(p->jpn,jpn);
	p->next=NULL;
	
	return p;
}

int main (void)
{
	node* init=create_node("","");
	node* a=create_node("aaa","あああ");
	node* b=create_node("bbb","いいい");
	
	init->next=a;
	a->next=b;
		
	printf("%-16s\t%-8s\t%-8s\t%-16s\n", "アドレス","eng","jpn","next");
	print_list(init);
	
	free(init);
	free(a);
	free(b);

	return 0;
}
