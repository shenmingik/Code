/*
题目描述：
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
*/
/*
思路：
    双指针i，j。j往后走，如果当前元素非0，那么nums[i]=nums[j]，i，j指针同时后移
    最后i指针就指向最后一个不为0元素的后面，把后面都赋值为0就可
*/
#include <vector>

using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int size = nums.size();
        while (j < size)
        {
            if (nums[j] == 0)
            {
                j++;
            }
            else
            {
                nums[i] = nums[j];
                i++;
                j++;
            }
        }

        while (i < size)
        {
            nums[i] = 0;
            i++;
        }
    }
};