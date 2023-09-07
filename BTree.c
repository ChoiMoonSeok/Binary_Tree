#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "Node.h"
#include "que.h"
#define INIT_ROOT -2147483647

BTreeNode *BTreeInit()
{
    BTreeNode *Root = (BTreeNode *)malloc(sizeof(BTreeNode));
    Root->data = INIT_ROOT;
    Root->LeftNode = NULL;
    Root->RightNode = NULL;
    return Root;
}

int BTreeAdd(BTreeNode *Root, int data)
{

    if (Root->data == INIT_ROOT)
    {
        Root->data = data;
        return 0;
    }
    QueNode *mothers = QueInit();
    BTreeNode *Data = (BTreeNode *)malloc(sizeof(BTreeNode));
    Data->data = data;
    Data->LeftNode = NULL;
    Data->RightNode = NULL;

    // BFS 활용
    QueAppend(mothers, Root);
    QueNode *tmp;
    while (1)
    {
        tmp = QuePop(mothers);
        if (tmp->Data->LeftNode == NULL)
        {
            tmp->Data->LeftNode = Data;
            break;
        }
        else if (tmp->Data->RightNode == NULL)
        {
            tmp->Data->RightNode = Data;
            break;
        }
        else
        {
            QueAppend(mothers, tmp->Data->LeftNode);
            QueAppend(mothers, tmp->Data->RightNode);
        }
    }

    return 0;
}

BTreeNode *BTreeSearch(BTreeNode *Root, int data){

    
    if (Root->data == data){
        return Root;
    }
    else{
        QueNode *que = QueInit();
        QueAppend(que, Root);
        BTreeNode *Destination = NULL;

        QueNode *tmp = NULL;
        int BkPoint = 0;
        while (que->next != NULL){
            tmp = QuePop(que);
            if (tmp->Data->LeftNode->data == data){
                Destination = tmp->Data->LeftNode;
                BkPoint = 1;
                break;
            }
            else if (tmp->Data->RightNode->data == data){
                Destination = tmp->Data->RightNode;
                BkPoint = 1;
                break;
            }
            else{
                if (tmp->Data->LeftNode != NULL){
                    QueAppend(que, tmp->Data->LeftNode);
                }
                if (tmp->Data->RightNode != NULL){
                    QueAppend(que, tmp->Data->RightNode);
                }
            }
            free(tmp);
        }

        return Destination;

    }

}

int BTreeDel(BTreeNode *Root, int data)
{

    QueNode *mothers = QueInit();

    if (Root->data == data)
    {
        QueAppend(mothers, Root);
        QueNode *children = QueInit();
        QueNode *tmp = NULL;
        while (mothers->next != NULL) {
            tmp = QuePop(mothers);
            if (tmp->Data->LeftNode != NULL)
            {
                QueAppend(mothers, tmp->Data->LeftNode);
                QueAppend(children, tmp->Data->LeftNode);
            }
            if (tmp->Data->RightNode != NULL)
            {
                QueAppend(mothers, tmp->Data->RightNode);
                QueAppend(children, tmp->Data->RightNode);
            }
            free(tmp);
        }

        free(Root);
        Root = (BTreeNode *)malloc(sizeof(BTreeNode));
        tmp = QuePop(children);
        Root->data = tmp->Data->data;
        Root->LeftNode = NULL;
        Root->RightNode = NULL;

        while (children->next != NULL){
            tmp = QuePop(children);
            BTreeAdd(Root, tmp->Data->data);
        }

        return 0;
    }
    else
    {
        QueNode *children = QueInit();
        BTreeNode *Del = BTreeSearch(Root, data);

        
        QueAppend(mothers, Del);
        QueNode *tmp = NULL;
        while (mothers->next != NULL){
            tmp = QuePop(mothers);
            if (tmp->Data->LeftNode != NULL){
                QueAppend(children, tmp->Data->LeftNode);
                QueAppend(mothers, tmp->Data->LeftNode);
            }
            if (tmp->Data->RightNode != NULL){
                QueAppend(children, tmp->Data->RightNode);
                QueAppend(children, tmp->Data->RightNode);
            }
            free(tmp);
        }

        tmp = QuePop(children);
        Del->data = tmp->Data->data;
        free(tmp);

        while (children->next != NULL){
            tmp = QuePop(children);
            BTreeAdd(Del, tmp->Data->data);
            free(tmp);
        }
    }

    return 0;
}