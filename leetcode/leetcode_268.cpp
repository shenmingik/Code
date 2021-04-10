/*
题目描述：
    给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
*/

/*
思路：求和，然后和数学公式（首项+末项）*项数/2 相减，差值就是缺失的数
*/
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            sum+=nums[i];
        }
        return size*(size+1)/2-sum;
    }
};