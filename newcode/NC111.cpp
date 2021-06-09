//最大数

/*
给定一个数组由一些非负整数组成，现需要将他们进行排列并拼接，使得最后的结果最大
返回值需要是string类型 否则可能会溢出
*/

/*
思路：前后两个元素两两比较，比较的规则是，如果a+b这个字符串组成的数比b+a这字符串小，那么就交换
*/

/*
代码一： 比较烂
*/
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
         * 最大数
         * @param nums int整型vector 
         * @return string字符串
         */
    string solve(vector<int> &nums)
    {
        // write code here
        int size = nums.size();
        string current;
        string next;
        for (int j = 0; j < size; j++)
        {
            for (int i = 0; i < size - 1; i++)
            {
                current = to_string(nums[i]) + to_string(nums[i + 1]);
                next = to_string(nums[i + 1]) + to_string(nums[i]);
                if (atoi(current.c_str()) < atoi(next.c_str()))
                {
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
        string ret;
        for (int i = 0; i < size; i++)
        {
            ret += to_string(nums[i]);
        }
        if (ret[0] == '0')
            return ret.substr(0, 1);
        return ret;
    }
};
#include <algorithm>
using namespace std;

class Solution {
    public:
        /**
         * 最大数
         * @param nums int整型vector 
         * @return string字符串
         */
        string solve(vector<int>& nums) {
            sort(nums.begin(),nums.end(),[](int a,int b)
                 {
                     return to_string(a)+to_string(b)>to_string(b)+to_string(a);
                 });
            if(nums[0] == 0) return to_string(0);
            string ret;
            for(int it:nums)
            {
                ret+=to_string(it);
            }
            return ret;
        }
    };