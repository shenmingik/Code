//二分查找Ⅱ

/*
请实现有重复数字的升序数组的二分查找
给定一个 元素有序的（升序）整型数组 nums 和一个目标值 target。
写一个函数搜索 nums 中的第一个出现的target，如果目标值存在返回下标，否则返回 -1
*/

#include <vector>
using namespace std;

class Solution
{
public:
    /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 如果目标值存在返回下标，否则返回 -1
         * @param nums int整型vector 
         * @param target int整型 
         * @return int整型
         */
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        if (nums.empty())
            return -1;
        while (left <= right)
        {
            middle = ((right - left)) / 2 + left;
            if (nums[middle] >= target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        if (nums[left] == target)
            return left;
        return -1;
    }
};