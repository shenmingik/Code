/*
题目描述：
    
给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
丑数 就是只包含质因数 2、3 和/或 5 的正整数。
*/

/*
思路：
    设置标志位end，然后将输入的数不算被2 3 5整除，如果最后值为1，则是丑数；反之，则不是
    0不为丑数，但是1是，我很奇怪这个出题者
*/
class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        bool end = false;
        while(!end)
        {
            if(n%2 == 0)
            {
                n/=2;
                continue;
            }
            if(n%3 == 0)
            {
                n/=3;
                continue;
            }
            if(n%5 == 0)
            {
                n/=5;
                continue;
            }
            end = true;
        }
        if(n!=1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};