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

    if (Root->data == INIT_ROOT){
        Root->data = data;
        return 0;
    }
    QueNode *mothers = QueInit();
    QueNode *children = QueInit();
    BTreeNode *Data = (BTreeNode *)malloc(sizeof(BTreeNode));
    Data->data = data;
    Data->LeftNode = NULL;
    Data->RightNode = NULL;
    
    // BFS 활용
    QueAppend(mothers, Root);
    while (1){
        QueNode *tmp = NULL;
        while (mothers->next != NULL){
            tmp = QuePop(mothers);
            if (tmp->Data->LeftNode == NULL\
                || tmp->Data->RightNode == NULL){
                if (tmp->Data->LeftNode == NULL){
                    tmp->Data->LeftNode = Data;
                }
                else {
                    tmp->Data->RightNode = Data;
                }
                free(tmp);
                MkEmptyQue(mothers);
                free(mothers);
                MkEmptyQue(children);
                free(children);
                return 0;
            }
            else{
                QueAppend(children, tmp->Data->LeftNode);
                QueAppend(children, tmp->Data->RightNode);
                free(tmp);
            }
        }

        while (children->next != NULL){
            tmp = QuePop(children);
            QueAppend(mothers, tmp->Data);
            free(tmp);
        }
    }
}


int main(void){

    BTreeNode *Root = BTreeInit();
    for (int i = 0; i < 7; i++){
        BTreeAdd(Root, i);
    }
    return 0;
}