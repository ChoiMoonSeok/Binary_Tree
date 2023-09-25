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

typedef struct EdgeNode
{
    struct QueNode *head;
    struct QueNode *tail;
} EdgeNode;

EdgeNode que_init();

int que_append(EdgeNode *edge, BTreeNode *que_data);

QueNode *que_pop(EdgeNode *edge);