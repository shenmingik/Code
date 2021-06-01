//重建二叉树

/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *construct(vector<int> &pre, int pre_begin, int pre_end, vector<int> &vin, int vin_begin, int vin_end)
    {
        int root = pre[pre_begin];
        TreeNode *tree = new TreeNode(root);
        if (pre_end == pre_begin)
            return tree;
        int i = 0;
        for (i = vin_begin; i <= vin_end; i++)
        {
            if (vin[i] == root)
            {
                break;
            }
        }
        int left_len = i - vin_begin;
        int right_len = vin_end - i;
        if (left_len > 0)
            tree->left = construct(pre, pre_begin + 1, pre_begin + left_len, vin, vin_begin, i - 1);
        if (right_len > 0)
            tree->right = construct(pre, pre_begin + left_len + 1, pre_end, vin, i + 1, vin_end);

        return tree;
    }

    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() != vin.size() || pre.size() == 0)
            return nullptr;
        return construct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};