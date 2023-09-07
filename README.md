# Binary Tree Implementaion
단순 이진트리로 구현.\
따라서 정렬과 같은 부분은 구현되어 있지 않음.\

## que.c & que.h
이진 트리 탐색의 경우 BFS를 활용함.\
따라서 BFS 구현에 필요한 Que를 구현한 부분

## Node.h
BTreeNode 구조체의 경우 que.c와 BTree.c의 구현에 모두 필요.\
따라서 구조체만 분리하여 Node.h로 정의.

## BTree.c & BTree.c
이진 트리를 구현한 부분

## main.c
이진트리를 구현하고 이를 테스트한 코드