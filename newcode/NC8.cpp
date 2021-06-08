//二叉树根节点到叶子节点和为指定值的路径

/*
给定一个二叉树和一个值\ sum sum，请找出所有的根节点到叶子节点的节点值之和等于\ sum sum 的路径，
例如：
给出如下的二叉树，\ sum=22 sum=22，
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
         * @param root TreeNode类 
         * @param sum int整型 
         * @return int整型vector<vector<>>
         */
    void pathSum_core(TreeNode *root, int sum, vector<int> &ret, vector<vector<int>> &result)
    {
        if (!root)
            return;

        ret.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right)
        {
            result.push_back(ret);
        }
        else
        {
            pathSum_core(root->left, sum, ret, result);
            pathSum_core(root->right, sum, ret, result);
        }
        ret.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        // write code here
        vector<vector<int>> result;
        vector<int> ret;
        pathSum_core(root, sum, ret, result);
        return result;
    }
};