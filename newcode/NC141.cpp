//判断回文

/*
给定一个字符串，请编写一个函数判断该字符串是否回文。如果回文请返回true，否则返回false。
*/
#include <string>

using namespace std;
class Solution
{
public:
    /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         * 
         * @param str string字符串 待判断的字符串
         * @return bool布尔型
         */
    bool judge(string str)
    {
        // write code here
        int begin = 0;
        int end = str.size() - 1;
        while (begin <= end)
        {
            if (str[begin++] != str[end--])
            {
                return false;
            }
        }
        return true;
    }
};