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

typedef struct EdgeNode
{
    struct QueNode *head;
    struct QueNode *tail;
} EdgeNode;

EdgeNode que_init()
{
    EdgeNode edge;
    edge.head = NULL;
    edge.tail = NULL;

    return edge;
};

int que_append(EdgeNode *edge, BTreeNode *que_data)
{

    QueNode *que_element = (QueNode *)malloc(sizeof(QueNode));

    if (edge->head == NULL) // 큐가 비어있는 경우
    {
        QueNode *que_element = (QueNode *)malloc(sizeof(QueNode));
        que_element->Data = que_data;
        que_element->next = NULL;

        edge->head = que_element;
        edge->tail = que_element;

        return 0;
    }
    else
    {

        que_element->Data = que_data;
        que_element->next = NULL;

        edge->tail->next = que_element;

        edge->tail = que_element;

        return 0;
    }
}

QueNode *que_pop(EdgeNode *edge)
{
    if (edge->head == NULL) // 큐가 비어있는 경우
    {
        return NULL;
    }
    else
    {
        QueNode *poped_node = edge->head;

        if (poped_node->next != NULL) // 큐에 노드가 남은 경우
        {
            edge->head = poped_node->next;

            poped_node->next = NULL;

            return poped_node;
        }
        else // 더이상 큐에 남은 노드가 없는 경우
        {
            edge->head = NULL;
            edge->tail = NULL;

            return poped_node;
        }
    }
}