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

RootNode b_tree_init()
{
    RootNode root;
    root.Root = NULL;

    return root;
}

int b_tree_add(RootNode *tree_root, int data)
{
    BTreeNode *tree_element = (BTreeNode *)malloc(sizeof(BTreeNode));
    tree_element->data = data;
    tree_element->LeftNode = NULL;
    tree_element->RightNode = NULL;

    if (tree_root->Root == NULL)
    {

        tree_root->Root = tree_element;

        return 0;
    }
    else
    {

        BTreeNode *root_node;

        root_node = tree_root->Root;
        while (1)
        {
            // root node보다 작을 때
            if (root_node->data > data)
            {
                if (root_node->LeftNode != NULL)
                {

                    // root node 보다 작고, left node보다 클 때
                    if (root_node->LeftNode->data < data)
                    {
                        root_node = root_node->RightNode;
                    }
                    else
                    {
                        root_node = root_node->LeftNode;
                    }
                }
                else
                {
                    root_node->LeftNode = tree_element;
                    break;
                }
            }
            // root node보다 클 때
            else
            {

                // root node보다 크고, right node 보다 작을 때
                if (root_node->RightNode != NULL)
                {
                    if (root_node->RightNode->data < data)
                    {
                        root_node = root_node->RightNode;
                    }
                    else
                    {
                        root_node = root_node->LeftNode;
                    }
                }
                else
                {
                    root_node->RightNode = tree_element;
                    break;
                }
            }
        }
    }

    return 0;
}

int b_tree_delete(RootNode *tree_root, int data)
{

    BTreeNode *root_node = NULL;
    BTreeNode *child_node = tree_root->Root;
    while (1)
    {
        if (child_node->data > data)
        {
            root_node = child_node;
            child_node = child_node->LeftNode;
        }
        else if (child_node->data < data)
        {
            root_node = child_node;
            child_node = child_node->RightNode;
        }
        else
        {
            BTreeNode *del = child_node;

            if (child_node->LeftNode != NULL)
            {
                BTreeNode *upper_child_node = NULL;
                while (child_node->LeftNode != NULL)
                {
                    upper_child_node = child_node;
                    child_node = child_node->LeftNode;
                }

                upper_child_node->LeftNode = child_node->RightNode;
                free(del);
                break;
            }
            else
            {
                if (root_node->data > data)
                {
                    root_node->LeftNode = child_node->RightNode;
                    free(del);
                    break;
                }
                else
                {
                    root_node->RightNode = child_node->RightNode;
                    free(del);
                    break;
                }
            }
        }
    }

    return 0;
}
