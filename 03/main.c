#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

extern void print_list(node*);

int main (void)
{
	node init,a,b;
	strcpy(init.eng,"");
	strcpy(init.jpn,"");
	init.next=&a;
	
	strcpy(a.eng,"aaa");
	strcpy(a.jpn,"あああ");
	a.next=&b;
	
	strcpy(b.eng,"bbb");
	strcpy(b.jpn,"いいい");
	b.next=NULL;
	
	printf("%-16s\t%-8s\t%-8s\t%-16s\n", "アドレス","eng","jpn","next");
	print_list(&init);

	return 0;
}
