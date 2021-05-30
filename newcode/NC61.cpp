//两数之和

/**
* 描述：给出一个整数数组，请在数组中找出两个加起来等于目标值的数，
* 你给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的
* 假设给出的数组中只存在唯一解
* 例如：
* 给出的数组为 {20, 70, 110, 150},目标值为90
* 输出 index1=1, index2=2
*/
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
         * 
         * @param numbers int整型vector 
         * @param target int整型 
         * @return int整型vector
         */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> temp;
        vector<int> ret;
        for (int i = 0; i < numbers.size(); i++)
        {
            auto it = temp.find(numbers[i]);
            if (it != temp.end())
            {
                ret.push_back(it->second + 1);
                ret.push_back(i + 1);
                return ret;
            }
            temp.insert({target - numbers[i], i});
        }
        return ret;
    }
};