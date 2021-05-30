// 最小的k个数

/*
* 描述：
* 给定一个数组，找出其中最小的K个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
* 如果K>数组的长度，那么返回一个空的数组
*/

/*
* 输出：
* 输入：[4,5,1,6,2,7,3,8],4 
* 返回值：[1,2,3,4]
*/
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> ret;
        if (k <= input.size())
        {
            sort(input.begin(), input.end());
            for (int i = 0; i < k; i++)
            {
                ret.push_back(input[i]);
            }
        }
        return ret;
    }
};