#ifndef __TREEINTERCEPTION__
#define __TREEINTERCEPTION__

node2* scan_tree(node2* tree, int depth)
{
	node2* tmp=NULL;
	
	if(depth==0){
		if(!((tree->left)&&(tree->right))){
			return tree;
		}else{
			return NULL;
		}
	}else{
		tmp=scan_tree(tree->left,depth-1);
		if(tmp) return tmp;
		tmp=scan_tree(tree->right,depth-1);
		return tmp;
	}
}

void insert_tree_INTERCEPTOR (node2* p, node2* tree)
{
	node2* tmp=NULL;
	int d=-1;
	
	while(!tmp){
		d++;
		tmp=scan_tree(tree,d);
	}
	
	if(!tmp->left){
		tmp->left=p;
	}else{
		tmp->right=p;
	}
	
	return;
}
#define insert_tree insert_tree_INTERCEPTOR

#endif
