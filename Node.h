#ifndef __Node_H__
#define __Node_H__
typedef struct BTreeNode
{
    int data;
    struct BTreeNode *RightNode;
    struct BTreeNode *LeftNode;
} BTreeNode;
#endif