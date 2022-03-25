#include <stdio.h>
#include "tree.h"

int main()
{
	int a[] = {40, 20, 60, 70, 10, 50, 30};
	int n = 7;
	tree_t t1;
	init(&t1);
	for(int i = 0; i < n; ++i)
	{
		insert(&t1, a[i]);
	}
	inorder(&t1);
	
	iterator_t it;
	init_it(&it, &t1);
	while(has_next(&it))
	{
		printf("%d ", next(&it));
	}
	
}