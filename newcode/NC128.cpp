//容器盛水问题
/*
核心思想就是将左边和右边抽象成一个容器，如果碰到更高的壁就更改左边和右边的边界
*/

#include <vector>
using namespace std;

class Solution {
    public:
        /**
         * max water
         * @param arr int整型vector the array
         * @return long长整型
         */
        long long maxWater(vector<int>& arr) {
            // write code here
            long long volume = 0;
            int left = 0;
            int right = arr.size()-1;
            int level = min(arr[left],arr[right]);
            
            while(left<right)
            {
                if(arr[left] <= level)
                {
                    volume+=level-arr[left];
                    left++;
                    if(arr[left] > level)
                    {
                        level = min(arr[left],arr[right]);
                    }
                }
                else
                {
                    volume+=level-arr[right];
                    right--;
                    if(arr[right] > level)
                    {
                        level = min(arr[left],arr[right]);
                    }
                }
            }
            return volume;
        }
    };