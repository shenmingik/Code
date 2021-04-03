/*
题目描述：
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组
*/

/*
错误思路：暴力法（超时）
*/
#if 0
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        if(nums.size()<3) return vec;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                for(int k=j+1;k<size;k++)
                {
                    if(nums[i]+nums[j]+nums[k] == 0)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        if(find(vec.begin(),vec.end(),temp)==vec.end())
                        {
                            vec.push_back(temp);
                        }
                    }
                }
            }
        }
        return vec;
    }
};
#endif

/*
正确思路：
先排序。
然后找到一个i，取得-nums[i]。然后j=i+1，k=size-1；一个从前，一个从后遍历
如果 nums[j]+nums[k] > -nums[i]，那么说明jk之和大了，所以k--；
反之，j++

注意：这里不能有相同的三元组，所以需要加上nums[i] == nums[i-1] && i>0的条件
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        if(nums.size()<3) return vec;
        int size = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<size;i++)
        {
            //排除重复元素，之所以是i-1而不是i+1是因为可能会用到这个元素
            if(i>0 && nums[i] == nums[i-1]) continue;
            else{
                int opposite = -nums[i];
                int j=i+1;  //从头
                int k = size-1; //从尾
                while(j<k)
                {
                    if((nums[j]+nums[k])>opposite) k--;
                    else if((nums[j]+nums[k])<opposite) j++;
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        vec.push_back(temp);

                        //清除重复元素
                        while(j<k &&nums[k-1] == nums[k]) k--;
                        while(j<k&& nums[j+1] == nums[j]) j++;
                        k--;
                        j++;
                    }
                }
            }
        
        }
        return vec;
    }
};