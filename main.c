#include "BTree.h"

int main()
{

    RootNode *Tree = b_tree_init();

    // case 1
    b_tree_add(Tree, 10);
    printf("case 1\n %d\n\n", Tree->Root->data);

    // case 2
    b_tree_add(Tree, 5);
    printf("case 2\n");
    printf("%d\n", Tree->Root->data);
    printf("%d\n\n", Tree->Root->LeftNode->data);

    // case 3
    b_tree_add(Tree, 15);
    printf("case 3\n");
    printf("%d\n", Tree->Root->data);
    printf("%d %d\n\n", Tree->Root->LeftNode->data, Tree->Root->RightNode->data);

    // case 4
    b_tree_add(Tree, 20);
    printf("case 4\n");
    printf("%d\n", Tree->Root->data);
    printf("%d %d\n", Tree->Root->LeftNode->data, Tree->Root->RightNode->data);
    printf("%d\n\n", Tree->Root->RightNode->RightNode->data);

    // case 5
    b_tree_add(Tree, 13);
    printf("case 5\n");
    printf("%d\n", Tree->Root->data);
    printf("%d %d\n", Tree->Root->LeftNode->data, Tree->Root->RightNode->data);
    printf("%d %d\n\n", Tree->Root->RightNode->LeftNode->data, Tree->Root->RightNode->RightNode->data);

    // case 6
    b_tree_add(Tree, 3);
    printf("case 6\n");
    printf("%d\n", Tree->Root->data);
    printf("%d %d\n", Tree->Root->LeftNode->data, Tree->Root->RightNode->data);
    printf("%d   %d %d\n\n", Tree->Root->LeftNode->LeftNode->data, Tree->Root->RightNode->LeftNode->data, Tree->Root->RightNode->RightNode->data);

    // case 7
    b_tree_add(Tree, 7);
    printf("case 7\n");
    printf("%d\n", Tree->Root->data);
    printf("%d %d\n", Tree->Root->LeftNode->data, Tree->Root->RightNode->data);
    printf("%d %d %d %d\n\n", Tree->Root->LeftNode->LeftNode->data, Tree->Root->LeftNode->RightNode->data, Tree->Root->RightNode->LeftNode->data, Tree->Root->RightNode->RightNode->data);

    // case 8
    b_tree_delete(Tree, 5);
    printf("case 8\n");
    printf("%d\n", Tree->Root->data);
    printf("%d %d\n", Tree->Root->LeftNode->data, Tree->Root->RightNode->data);
    printf("%d   %d %d\n\n", Tree->Root->LeftNode->LeftNode->data, Tree->Root->RightNode->LeftNode->data, Tree->Root->RightNode->RightNode->data);

    // case 9
    b_tree_delete(Tree, 15);
    printf("case 9\n");
    printf("%d\n", Tree->Root->data);
    printf("%d %d\n", Tree->Root->LeftNode->data, Tree->Root->RightNode->data);
    printf("%d   %d\n\n", Tree->Root->LeftNode->LeftNode->data, Tree->Root->RightNode->LeftNode->data);

    // case 10
    b_tree_delete(Tree, 20);
    printf("case 10\n");
    printf("%d\n", Tree->Root->data);
    printf("%d %d\n", Tree->Root->LeftNode->data, Tree->Root->RightNode->data);
    printf("%d\n\n", Tree->Root->LeftNode->LeftNode->data);

    // case 11
    b_tree_delete(Tree, 10);
    printf("case 11\n");
    printf("%d\n", Tree->Root->data);
    printf("%d\n", Tree->Root->LeftNode->data);
    printf("%d\n\n", Tree->Root->LeftNode->LeftNode->data);

    // case 12
    b_tree_delete(Tree, 13);
    printf("case 12\n");
    printf("%d\n", Tree->Root->data);
    printf("%d\n", Tree->Root->LeftNode->data);
    printf("test end");

    return 0;
}