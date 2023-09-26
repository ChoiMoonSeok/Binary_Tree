#include "BTree.h"

int main()
{

    RootNode Tree = b_tree_init();

    // case 1
    b_tree_add(&Tree, 10);
    printf("case 1\n %d\n\n", Tree.Root->data);

    // case 2
    b_tree_add(&Tree, 5);
    printf("case 2\n");
    printf("%d\n", Tree.Root->data);
    printf("%d\n\n", Tree.Root->LeftNode->data);

    // case 3
    b_tree_add(&Tree, 15);
    printf("case 3\n");
    printf("%d\n", Tree.Root->data);
    printf("%d %d\n\n", Tree.Root->LeftNode->data, Tree.Root->RightNode->data);

    // case 4
    b_tree_add(&Tree, 20);
    printf("case 4\n");
    printf("%d\n", Tree.Root->data);
    printf("%d %d\n", Tree.Root->LeftNode->data, Tree.Root->RightNode->data);
    printf("%d\n\n", Tree.Root->RightNode->RightNode->data);

    // case 5
    b_tree_add(&Tree, 13);
    printf("case 5\n");
    printf("%d\n", Tree.Root->data);
    printf("%d %d\n", Tree.Root->LeftNode->data, Tree.Root->RightNode->data);
    printf("%d %d\n\n", Tree.Root->RightNode->LeftNode->data, Tree.Root->RightNode->RightNode->data);

    //----------------------------------------------------------------------------------------------------

    return 0;
}