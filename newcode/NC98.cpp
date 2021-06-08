//判断t1树中是否有与t2树拓扑结构完全相同的子树

/*
给定彼此独立的两棵二叉树，判断 t1 树是否有与 t2 树拓扑结构完全相同的子树。
设 t1 树的边集为 E1，t2 树的边集为 E2，若 E2 等于 E1 ，则表示 t1 树和t2 树的拓扑结构完全相同。
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution
{
public:
    /**
         * 
         * @param root1 TreeNode类 
         * @param root2 TreeNode类 
         * @return bool布尔型
         */
    bool has_contains(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val == root2->val)
        {
            return has_contains(root1->left, root2->left) && has_contains(root1->right, root2->right);
        }
        return false;
    }

    bool isContains(TreeNode *root1, TreeNode *root2)
    {
        // write code here
        if (root1 == nullptr)
            return false;
        if (has_contains(root1, root2))
        {
            return true;
        }
        else
        {
            return isContains(root1->left, root2) || isContains(root1->right, root2);
        }
    }
};