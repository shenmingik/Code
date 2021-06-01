//替换空格

/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
则经过替换之后的字符串为We%20Are%20Happy。
*/
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param s string字符串 
         * @return string字符串
         */
    string replaceSpace(string s)
    {
        // write code here
        string ret;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                ret.push_back('0');
                ret.push_back('2');
                ret.push_back('%');
            }
            else
            {
                ret.push_back(s[i]);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};