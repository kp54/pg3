#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char eng[256];
	char jpn[256];
	struct node* next;
} node;

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
	printf("%16p\t%8s\t%8s\t%16p\n", &init,init.eng,init.jpn,init.next);
	printf("%16p\t%8s\t%8s\t%16p\n", &a,a.eng,a.jpn,a.next);
	printf("%16p\t%8s\t%8s\t%16p\n", &b,b.eng,b.jpn,b.next);

	return 0;
}
