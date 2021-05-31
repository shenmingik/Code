// 最长无重复子数组

/*
描述
给定一个数组arr，返回arr的最长无重复元素子数组的长度，无重复指的是所有数字都不相同。
子数组是连续的，比如[1,3,5,7,9]的子数组有[1,3]，[3,5,7]等等，但是[1,3,7]不是子数组
*/
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    /**
         * 
         * @param arr int整型vector the array
         * @return int整型
         */
    int maxLength(vector<int> &arr)
    {
        // write code here
        if (arr.empty())
        {
            return 0;
        }

        unordered_set<int> temp;
        int left = 0;
        int right = 0;
        int max = 0;
        int size = arr.size();
        while (right < size)
        {
            if (!temp.count(arr[right]))
            {
                temp.insert(arr[right]);
                right++;
            }
            else
            {
                temp.erase(arr[left]);
                left++;
            }
            max = max > temp.size() ? max : temp.size();
        }
        return max;
    }
};