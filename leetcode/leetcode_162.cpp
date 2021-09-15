//162. 寻找峰值

/*
 * 峰值元素是指其值严格大于左右相邻值的元素。
 * 给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
 * 你可以假设 nums[-1] = nums[n] = -∞ 。
 * 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
 */
#include <vector>
using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int peak_left = 0;
        int peak_right = nums.size() - 1;
        int peak = peak_left + (peak_right - peak_left) / 2; //得到中间元素
        while (peak_left < peak_right)
        {
            peak = peak_left + (peak_right - peak_left) / 2; //得到中间元素
            //峰值在左边
            if (nums[peak] > nums[peak + 1])
            {
                peak_right = peak;
            }
            else
            {
                //峰值在右边
                peak_left = peak + 1;
            }
        }
        return peak_left;
    }
};