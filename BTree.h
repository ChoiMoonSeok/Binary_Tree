#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "Node.h"
#include "que.h"
#define INIT_ROOT -2147483647

BTreeNode *BTreeInit();

int BTreeAdd(BTreeNode *Root, int data);

BTreeNode *BTreeSearch(BTreeNode *Root, int data);

int BTreeDel(BTreeNode *Root, int data);

