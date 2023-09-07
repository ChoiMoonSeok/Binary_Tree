#include "BTree.h"

int main(void)
{

    BTreeNode *Root = BTreeInit();
    for (int i = 0; i < 7; i++)
    {
        BTreeAdd(Root, i);
    }

    
    printf("%d Root\n", Root->data);
    printf("%d l\n", Root->LeftNode->data);
    printf("%d r\n", Root->RightNode->data);
    printf("%d l l\n", Root->LeftNode->LeftNode->data);
    printf("%d l r\n", Root->LeftNode->RightNode->data);
    printf("%d r l\n", Root->RightNode->LeftNode->data);
    printf("%d r r\n", Root->RightNode->RightNode->data);

    BTreeDel(Root, 0);
    
    printf("\nAfter Delete Root\n\n");
    printf("%d Root\n", Root->data);
    printf("%d l\n", Root->LeftNode->data);
    printf("%d r\n", Root->RightNode->data);
    printf("%d l l\n", Root->LeftNode->LeftNode->data);
    printf("%d l r\n", Root->LeftNode->RightNode->data);
    printf("%d r l\n", Root->RightNode->LeftNode->data);

    printf("\nSearch %d\n", BTreeSearch(Root, 5)->data);

    BTreeDel(Root, 3);

    printf("\nAfter Delete 3\n\n");
    printf("%d Root\n", Root->data);
    printf("%d l\n", Root->LeftNode->data);
    printf("%d r\n", Root->RightNode->data);
    printf("%d l l\n", Root->LeftNode->LeftNode->data);
    printf("%d l r\n", Root->LeftNode->RightNode->data);

    return 0;
}