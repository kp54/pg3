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

void concat_list(node* p, node* list)
{
	if(list->next){
		concat_list(p,list->next);
	}else{
		list->next=p;
		p->next=NULL;
	}
	
	return;
}

void close_list(node* list)
{
	if(list->next) close_list(list->next);
	
	free(list);
	
	return;
}

int main (void)
{
	node* init=NULL;
	node* a[16];
	
	init=create_node("","");
	a[0]=create_node("aaa","あああ");
	a[1]=create_node("bbb","いいい");
	
	concat_list(a[0],init);
	concat_list(a[1],init);
	
	printf("%-16s\t%-8s\t%-8s\t%-16s\n", "アドレス","eng","jpn","next");
	print_list(init);
	
	close_list(init);

	return 0;
}
