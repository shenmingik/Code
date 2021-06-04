//二叉树的下一个结点

/*
给定一个二叉树其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的next指针。
*/

#include <cstdlib>

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (pNode)
        {
            //pNode不为空
            TreeLinkNode *pParent = pNode->next;
            TreeLinkNode *pCurrent = pNode;

            if (pCurrent->right)
            {
                pCurrent = pCurrent->right;
                while (pCurrent->left)
                {
                    pCurrent = pCurrent->left;
                }
                return pCurrent;
            }
            else if (pParent) //如果有父节点
            {
                //如果当前节点是父节点的右节点
                while (pCurrent == pParent->right && pParent)
                {
                    pCurrent = pParent;
                    pParent = pParent->next;
                }
                pCurrent = pParent;

                return pCurrent;
            }
        }
        return nullptr;
    }
};