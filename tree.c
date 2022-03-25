#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init(tree_t *ptr_tree)
{
	ptr_tree->root_ = NULL;
}
node_t* insert_(node_t* root, node_t* temp)
{	
	if(root == NULL)
	{
		root = temp;
	}
	else if(temp->key_ < root->key_)
	{	
		root->left_ = insert_(root->left_, temp);
	}
	else
	{
		root->right_ = insert_(root->right_, temp);
	}
	return root;
}
void insert(tree_t *ptr_tree, int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->left_ = temp->right_ = NULL;
	temp->key_ = key;
	
	ptr_tree->root_ = insert_(ptr_tree->root_, temp);
}

void inorder_(const node_t* temp)
{
	if(temp)
	{
		inorder_(temp->left_);
		printf("%d ", temp->key_);
		inorder_(temp->right_);
	}
}
void inorder(const tree_t *ptr_tree)
{
	inorder_(ptr_tree->root_); printf("\n");
}

node_t* min(node_t* current)
{
	if(current == NULL) return current;
	
	while(current->left_)
	{
		current = current->left_;
	}
	return current;
}
node_t* successor_(node_t* root, node_t* current)
{
	if(current->right_ != NULL)
		return min(current->right_);
	node_t* succ = NULL;
	while(root != NULL && root->key_ != current->key_)
	{
		if(current->key_ < root->key_)
		{
			succ = root;
			root = root->left_;
		}
		else if(current->key_ > root->key_)
		{
			root = root->right_;
		}
	}	
	return succ;
		
}

void init_it(iterator_t* ptr_it, tree_t *ptr_tree)
{
	ptr_it->ptr_tree_ = ptr_tree;
	ptr_it->current_ = min(ptr_tree->root_);
	
}
int has_next(const iterator_t* ptr_it) // boolean
{
	return ptr_it->current_ != NULL;
}
int next(iterator_t* ptr_it) // return value type
{
	int key = ptr_it->current_->key_;
	ptr_it->current_ = successor_(ptr_it->ptr_tree_->root_, ptr_it->current_);
	return key;
}