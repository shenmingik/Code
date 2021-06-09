//最长重复子串

/*
一个重复字符串是由两个相同的字符串首尾拼接而成，例如abcabc便是长度为6的一个重复字符串，而abcba则不存在重复字符串。
给定一个字符串，请编写一个函数，返回其最长的重复字符子串。
若不存在任何重复字符子串，则返回0。
*/

#include <string>
using namespace std;

class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         * 
         * @param a string字符串 待计算字符串
         * @return int整型
         */
        int solve(string a) {
            int len = a.size();
            int count = 0;
            for(int i=len/2;i>=0;i--)
            {
                for(int j=0;j<len/2;j++)
                {
                    if(a[j] == a[i+j])
                    {
                        count++;
                    }
                    else
                    {
                        count = 0;
                    }
                    
                    if(count == i)
                    {
                        return count*2;
                    }
                }
            }
            return 0;
        }
    };