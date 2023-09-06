#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "Node.h"
#define INIT_ROOT -2147483647

typedef struct QueNode
{
    struct QueNode *next;
    struct BTreeNode *Data;
} QueNode;


QueNode *QueInit()
{
    QueNode *Root = (QueNode *)malloc(sizeof(QueNode));
    Root->next = NULL;
    
    return Root;
};

int QueAppend(QueNode *Root, BTreeNode *tail)
{
    QueNode *tmp = Root; 
    while (tmp->next != NULL){
        tmp = tmp->next;
    }

    QueNode *end = (QueNode *)malloc(sizeof(QueNode));
    end->Data = tail;
    end->next = NULL;

    tmp->next = end;

    return 0;
}

QueNode *QuePop(QueNode *Root)
{
    if (Root->next != NULL){
        QueNode *First = Root->next;

        QueNode *tmp = First->next;

        Root->next = tmp;

        return First;
    }
    else{
        QueNode *tmp = (QueNode *)malloc(sizeof(QueNode));
        tmp->Data->data = INIT_ROOT;
        return tmp;
    }
}

int MkEmptyQue(QueNode *Root){
    QueNode *tmp = NULL;
    while (Root->next != NULL){
        tmp = QuePop(Root);
        free(tmp);
    }
    return 0;
}