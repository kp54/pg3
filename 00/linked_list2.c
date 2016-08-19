#include <stdlib.h>
#include <string.h>

#include "node.h"

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
