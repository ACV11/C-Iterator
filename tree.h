#ifndef TREE_H
#define TREE_H
struct node
{
	int key_;
	struct node* left_;
	struct node* right_;
};
typedef struct node node_t;

struct tree
{
	node_t *root_;
};
typedef struct tree tree_t;

void init(tree_t *ptr_tree);
void insert(tree_t *ptr_tree, int key);
void inorder(const tree_t *ptr_tree);

struct iterator
{
	tree_t *ptr_tree_;
	node_t* current_;
};
typedef struct iterator iterator_t;
void init_it(iterator_t* ptr_it, tree_t *ptr_tree);
int has_next(const iterator_t* ptr_it); // boolean
int next(iterator_t* ptr_it); // return value type
#endif