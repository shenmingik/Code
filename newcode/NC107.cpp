//寻找峰值

/*
山峰元素是指其值大于或等于左右相邻值的元素。给定一个输入数组nums，任意两个相邻元素值不相等，数组可能包含多个山峰。找到索引最大的那个山峰元素并返回其索引。

假设 nums[-1] = nums[n] = -∞。
*/
class Solution {
    public:
        /**
         * 寻找最后的山峰
         * @param a int整型一维数组 
         * @param aLen int a数组长度
         * @return int整型
         */
        int solve(int* a, int aLen) {
            // write code here
            if(!a) return -1;
            int max_index = 0;
            for(int i=1;i<=aLen-1;i++)
            {
                if(i ==  aLen-1)
                {
                    if(a[i] >=a[i-1])
                    {
                        max_index = i;
                    }
                }
                else if(a[i] >= a[i-1] && a[i] >= a[i+1])
                {
                    max_index = i;
                }
            }
            return max_index;
        }
    };