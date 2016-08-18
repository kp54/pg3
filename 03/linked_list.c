#include <stdio.h>

#include "node.h"

void print_list (node* p)
{
	printf("%16p\t%8s\t%8s\t%16p\n", p,p->eng,p->jpn,p->next);
	if(p->next) print_list(p->next);
	return;
}
