//括号匹配

/*
给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。
*/
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    /**
         * 
         * @param s string字符串 
         * @return bool布尔型
         */
    bool isValid(string s)
    {
        // write code here
        if (s.empty())
            return false;
        stack<char> bracket;
        int size = s.size();
        char temp;
        for (int i = 0; i < size; i++)
        {
            switch (s[i])
            {
            case '(':
            {
                bracket.push('(');
                break;
            }
            case ')':
            {
                if (bracket.empty())
                    return false;
                temp = bracket.top();
                if (temp == '(')
                {
                    bracket.pop();
                    break;
                }
                return false;
            }
            case '[':
            {
                bracket.push('[');
                break;
            }
            case ']':
            {
                if (bracket.empty())
                    return false;
                temp = bracket.top();
                if (temp == '[')
                {
                    bracket.pop();
                    break;
                }
                return false;
            }
            case '{':
            {
                bracket.push('{');
                break;
            }
            case '}':
            {
                if (bracket.empty())
                    return false;
                temp = bracket.top();
                if (temp == '{')
                {
                    bracket.pop();
                    break;
                }
                return false;
            }
            default:
                return false;
            }
        }
        return bracket.empty();
    }
};