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

RootNode *b_tree_init()
{
    RootNode *root = (RootNode *)malloc(sizeof(RootNode));
    root->Root = NULL;

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
                    root_node = root_node->LeftNode;
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
                if (root_node->RightNode != NULL)
                {
                    root_node = root_node->RightNode;
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
    BTreeNode *root_node[2] = {NULL};
    BTreeNode *leaf_node = NULL;
    root_node[1] = tree_root->Root;

    while (1)
    {
        if (root_node[1] != NULL)
        {
            if (root_node[1]->data > data)
            {
                root_node[0] = root_node[1];
                root_node[1] = root_node[1]->LeftNode;
            }
            else if (root_node[1]->data < data)
            {
                root_node[0] = root_node[1];
                root_node[1] = root_node[1]->RightNode;
            }
            else
            {
                if ((root_node[1]->RightNode == NULL) && (root_node[1]->LeftNode == NULL))
                {
                    leaf_node = root_node[1];
                    break;
                }
                else if ((root_node[1]->LeftNode == NULL) || (root_node[1]->RightNode == NULL))
                {
                    if (root_node[0]->data > data)
                    {
                        if (root_node[1]->LeftNode == NULL)
                        {
                            root_node[0]->LeftNode = root_node[1]->RightNode;
                        }
                        else
                        {
                            root_node[0]->LeftNode = root_node[1]->LeftNode;
                        }
                    }
                    else
                    {
                        if (root_node[1]->LeftNode == NULL)
                        {
                            root_node[0]->RightNode = root_node[1]->RightNode;
                        }
                        else
                        {
                            root_node[0]->RightNode = root_node[1]->LeftNode;
                        }
                    }

                    leaf_node = root_node[1];
                    break;
                }
                else
                {
                    leaf_node = root_node[1]->RightNode;
                    while (leaf_node->LeftNode != NULL)
                    {
                        if (leaf_node->LeftNode->LeftNode == NULL)
                        {
                            break;
                        }
                        else
                        {
                            leaf_node = leaf_node->LeftNode;
                        }
                    }

                    if (root_node[0] != NULL)
                    {
                        if (root_node[0]->data > data)
                        {
                            leaf_node->LeftNode = root_node[1]->LeftNode;
                            root_node[0]->LeftNode = leaf_node;

                            leaf_node = root_node[1];
                        }
                        else
                        {
                            leaf_node->LeftNode = root_node[1]->LeftNode;
                            root_node[0]->RightNode = leaf_node;
                            leaf_node = root_node[1];
                        }
                    }
                    else
                    {

                        if (root_node[1]->RightNode != NULL)
                        {
                            tree_root->Root = root_node[1]->LeftNode;
                            leaf_node->LeftNode = root_node[1]->LeftNode;
                            leaf_node->RightNode = root_node[1]->RightNode;
                            leaf_node = root_node[1];
                        }
                        else
                        {
                            leaf_node->LeftNode = root_node[1]->LeftNode;
                            leaf_node = root_node[1];
                        }
                    }

                    break;
                }
            }
        }
        else
        {
            return 1;
        }
    }

    free(leaf_node);

    return 0;
}
