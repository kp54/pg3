#ifndef __NODE__
#define __NODE__

typedef struct node{
	char eng[256];
	char jpn[256];
	struct node* next;
} node;

#endif
