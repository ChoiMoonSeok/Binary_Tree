#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct BTreeNode
{
    int data;
    struct BTreeNode *RightNode;
    struct BTreeNode *LeftNode;
} BTreeNode;

typedef struct RootNode
{
    BTreeNode *Root;
} RootNode;

RootNode *b_tree_init();

int b_tree_add(RootNode *tree_root, int data);

int b_tree_delete(RootNode *tree_root, int data);