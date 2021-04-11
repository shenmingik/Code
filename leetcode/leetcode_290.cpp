/*
题目描述：
    给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true

示例 2:
输入:pattern = "abba", str = "dog cat cat fish"
输出: false

示例 3:
输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false

示例 4:
输入: pattern = "abba", str = "dog dog dog dog"
输出: false
*/

/*
思路：
    1.首先将字符串s截取出每个单词
    2.用两个map去简历char，string的强连接关系
    3.去map中找，如果都没找到，则表示其实这个连接关系还没有建立，建立关系
    4.去map中查询，如果map1的 第一个等于map2 的第二个，那么返回true，其他都返回false
    5.检查index是否大于0，因为有 “aaa” “aa aa aa aa”的情况可能出现
*/
#include <map>
#include <string>

using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int patter_size = pattern.size();
        int index = 0;
        map<string,char> temp_a;
        map<char,string> temp_b;
        for(int i=0;i<patter_size;i++)
        {
            string sub_str = s.substr(index,s.find(" ",index)-index);
            if(sub_str.empty())
            {
                return false;
            }
            //cout<<sub_str<<endl;
            auto it1 = temp_a.find(sub_str);
            auto it2 = temp_b.find(pattern[i]);
            if(it1 == temp_a.end() && it2 == temp_b.end())
            {
                temp_a.insert({sub_str,pattern[i]});
                temp_b.insert({pattern[i],sub_str});
            }
            else if(it1 != temp_a.end()&& it2!=temp_b.end())
            {
                if(it1->first != it2->second || it1->second != it2->first)
                {
                    return false;
                }
                index = s.find(" ",index)+1;
                continue;
            }
            else
            {
                return false;
            }

            index = s.find(" ",index)+1;
        }
        if(index > 0)
        return false;
        return true;
    }
};