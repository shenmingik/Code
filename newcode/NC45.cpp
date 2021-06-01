//实现二叉树先序，中序和后序遍历

/*
描述
分别按照二叉树先序，中序和后序打印所有的节点。
*/

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
#include <vector>
using namespace std;

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
         * @param root TreeNode类 the root of binary tree
         * @return int整型vector<vector<>>
         */
    void get_result(vector<vector<int>> &result, TreeNode *root)
    {
        if (root != nullptr)
        {
            result[0].push_back(root->val);
            get_result(result, root->left);
            result[1].push_back(root->val);
            get_result(result, root->right);
            result[2].push_back(root->val);
        }
    }

    vector<vector<int>> threeOrders(TreeNode *root)
    {
        vector<vector<int>> ret(3, vector<int>(0));
        get_result(ret, root);
        return ret;
    }
};