#include "Node.h"

#ifndef __Node_H__
#define __Node_H__
typedef struct BTreeNode
{
    int data;
    struct BTreeNode *RightNode;
    struct BTreeNode *LeftNode;
} BTreeNode; 
#endif

typedef struct QueNode
{
    struct QueNode *next;
    struct BTreeNode *Data;
} QueNode;

QueNode *QueInit();

int QueAppend(QueNode *Root, BTreeNode *tail);

QueNode *QuePop(QueNode *Root);

int MkEmptyQue(QueNode *Root);