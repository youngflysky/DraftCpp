#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MaxSzie = 2001;

typedef struct BinNode
{
    int val;
    struct BinNode *leftChild;
    struct BinNode *rightChild;
} BinNode;
typedef BinNode *BinTree;
BinTree T = NULL;
int N;
int inOrder[MaxSzie];
int preOrder[MaxSzie];

void GetOrder()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> inOrder[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> preOrder[i];
    }
}

BinTree InSert(int val)
{
    BinTree TNode = new BinNode;
    TNode->leftChild = TNode->rightChild = NULL;
    TNode->val = val;
    return TNode;
}

BinTree BulidBinTree(int L1, int R1, int L2, int R2)
{
    if (L1 > R1)
    {
        return NULL;
    }
    BinTree node = InSert(preOrder[L1]);
    int i;
    for (i = L2; i <= R2; ++i)
    {
        if (inOrder[i] == preOrder[L1])
        {
            break;
        }
    }
    node->leftChild = BulidBinTree(L1 + 1, L1 + i - L2, L2, i - 1);
    node->rightChild = BulidBinTree(L1 + i - L2 + 1, R1, i + 1, R2);
    return node;
}

void PostTraversal(BinTree T)
{
    if (T == NULL)
    {
        return;
    }
    PostTraversal(T->leftChild);
    PostTraversal(T->rightChild);
    cout << T->val << ' ';
}

int main()
{
    GetOrder();
    T = BulidBinTree(0, N - 1, 0, N - 1);
    PostTraversal(T);
    return 0;
}
