//大数加法

/*
以字符串的形式读入两个数字，编写一个函数计算它们的和，以字符串形式返回。
（字符串长度不大于100000，保证字符串仅由'0'~'9'这10种字符组成）
*/
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         * 计算两个数之和
         * @param s string字符串 表示第一个整数
         * @param t string字符串 表示第二个整数
         * @return string字符串
         */
        string solve(string s, string t) {
            // write code here
            bool is_carry = false;
            int add = 0;
            string ret = "";
            int s_size = s.size();
            int t_size = t.size();
            
            int s_index = s_size-1;
            int t_index = t_size-1;
            while(s_index>=0 || t_index>=0)
            {
                if(s_index < 0)
                {
                    add = t[t_index]-'0';
                }
                else if(t_index < 0)
                {
                    add = s[s_index]-'0';
                }
                else
                {
                    add = s[s_index]-'0'+t[t_index]-'0';
                }
                //如果需要进位，+1
                if(is_carry)
                {
                    is_carry = false;
                    add+=1;
                }
                //如果相加后大于10，减一
                if(add >=10)
                {
                    is_carry = true;
                    add-=10;
                }
                ret.push_back(add+'0');
                s_index--;
                t_index--;
            }
            if(is_carry) ret.push_back('1');
            reverse(ret.begin(),ret.end());
            return ret;
        }
    };