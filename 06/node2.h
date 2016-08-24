#ifndef __NODE2__
#define __NODE2__

typedef struct node2{
	char eng[256];
	char jpn[256];
	struct node2* left;
	struct node2* right;
} node2;

#endif
