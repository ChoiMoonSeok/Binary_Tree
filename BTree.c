#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#include "Node.h"
#include "que.h"


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
    else {
        
        BTreeNode *root_node;

        root_node = tree_root->Root;
        printf("root : %d\n", root_node->data);
        while (1){
            // root node보다 작을 때
            printf("%d : %d\n", data, root_node->data);
            if (root_node->data > data){ 
                if (root_node->LeftNode != NULL){

                    // root node 보다 작고, left node보다 클 때
                    if (root_node->LeftNode->data > data){ 
                        tree_element->RightNode = root_node->LeftNode;
                        root_node->LeftNode = tree_element;
                        break;
                    }
                    else{
                        root_node = root_node->LeftNode;
                    }
                }
                else{ 
                    root_node->LeftNode = tree_element;
                    break;
                }
            }
            // root node보다 클 때 
            else{ 

                // root node보다 크고, right node 보다 작을 때
                if (root_node->RightNode != NULL){
                    if (root_node->RightNode->data > data){
                        tree_element->LeftNode = root_node->RightNode;
                        root_node->RightNode = tree_element;
                        break;
                    }
                    else{
                        root_node = root_node->RightNode;
                    }
                }
                else{
                    root_node->RightNode = tree_element;
                    break;
                }
            }
        }
    }

    return 0;
}

int main()
{

    RootNode Tree = b_tree_init();

    b_tree_add(&Tree, 0);
    printf("%d end\n", Tree.Root->data);
    b_tree_add(&Tree, -1);
    printf("%d end\n", Tree.Root->LeftNode->data);
    b_tree_add(&Tree, 1);
    printf("%d end\n", Tree.Root->RightNode->data);
    b_tree_add(&Tree, 2);
    printf("%d end\n", Tree.Root->RightNode->RightNode->data);
    b_tree_add(&Tree, 10);
    printf("%d end\n", Tree.Root->RightNode->RightNode->RightNode->data);
    b_tree_add(&Tree, 8);
    printf("%d end\n", Tree.Root->RightNode->RightNode->RightNode->data);
    printf("%d\n", Tree.Root->RightNode->RightNode->RightNode->LeftNode->data);

    return 0;
}